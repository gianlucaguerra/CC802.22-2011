% SIMULATION BINARY CTC

clc; clear;
addpath(genpath('.'));

% .-------------------------------.
% |     PARAMETERS TO CHANGE      |
% '-------------------------------'
    code_params_row = 41;
    rate = '1/2';
        
    Eb_N0_dB = [(0:0.15:10.15);
                (0:0.09:6.1);
                (0:0.1:0.5), (0.52:0.02:1.5), (1.6:0.1:2.7);
                 0, 0.1, 0.2, (0.22:0.02:1.5);
                 0, 0.1, 0.2, (0.22:0.02:1.5)];
    
    it_scheme = [1, 2, 4, 10, 20];
     
    tot_bit = 1e7;
    error_threshold = 1e4;
% ---------------------------------


% Parameters
code_params = CTC.code_params();

% Genereral code parameters
blk_size = code_params(code_params_row,1)*8;                                             % Information block length
codeword_length = blk_size./str2num(rate);                                               % Codeword block length 
R = str2num(rate);                                                                       % Code rate

% Simulation parameters
tot_blk = ceil(tot_bit/codeword_length);                                                 % Total number of blocks to send
Eb_N0 = 10.^(Eb_N0_dB./10);

% Modulation parameters
M = 2;                                                                                   % Number of constellation symbols
L = @(x) 2.*x-(M-1);                                                                     % Constellation map
Es = 1;
modulation_table = getModulationTable(size(CRSC.P,1), L, M);                             % Table with all the possible modulation

% Encoder and CTC interleaver parameters
N = code_params(code_params_row, 10);                                                    % Number of input pairs
ctc_int_params = code_params(code_params_row, 11:end);                                   % CTC interleaver parameters
ctc_P_matrix = getPermutationMatrix(blk_size, N, ctc_int_params);                        % UP2DOWN  CTC interleaver permutation matrix
[ctc_p_input_table, ctc_p_step_table] = getPermutationTables(N, ctc_int_params);         % DOWN2UP CTC permutation tables
[crsc_output_table, crsc_state_update_table, crsc_neighbours_table] = getLookUpTables(); % CRSC code component output and state update tables

% Puncturing parameter
switch rate                                                                              
    case '1/2' 
        puncturing_vector = CTC.puncturing_matrix(1,:);
    case '2/3'
        puncturing_vector = CTC.puncturing_matrix(2,:);
    case '3/4'
        puncturing_vector = CTC.puncturing_matrix(3,:);
    case '5/6'
        puncturing_vector = CTC.puncturing_matrix(4,1:end-1);
end
puncturing_pattern = getPuncturingPattern( puncturing_vector, N );                      % Puncturing pattern

% Error matrix initialization
error_num = zeros(length(it_scheme), size(Eb_N0_dB,2));
error_blk = zeros(length(it_scheme), size(Eb_N0_dB,2));

% TRANSMISSION SCHEME

%                  TRANSMITTER               CHANNEL     RECEIVER
%    <-------------------------------------><-------><------------->
%                                               w      
%    .---------.   .---------.   .---------.    |    .---------.
% ---| ENCODER |---| CONFORM |---|    L    |---(+)---| DECODER |---
%  u '---------' c '---------' d '---------' s     r '---------' u_hat
%                  <----------------------->
%                           MODULATOR

% Noise pattern generation (always the same)
w = randn(codeword_length,1);
sigma_w = sqrt(Es./(2.*R.*log2(M).*Eb_N0));                                  % Noise for each SNR

for n_blk = 1 : tot_blk                                                      % Across all packet

    % Information block generation
    u = randi([0, 1], blk_size, 1);
    
    % ENCODER: CTC Encoding with puncturing, the output is a column vector of
    % length codeword_length
    c = CTC_enc_p(u, crsc_state_update_table, crsc_output_table, N, ctc_P_matrix, puncturing_pattern);
    
    % MODULATOR
    s = L(c);
    
    for snr_index = 1 : size(Eb_N0,2)                                           % Across all SNR
        for it_index = 1 : length(it_scheme)                                        % Across all iteration
            if (error_num(it_index, snr_index)< error_threshold)
                w_s = w .* sigma_w(it_index, snr_index);                                    % Noise scaling
                r = s + w_s;                                                                % Received sequence
            
                u_hat = CTC_dec_p_mex(r, crsc_state_update_table, crsc_output_table,...               % Decoding
                  crsc_neighbours_table, modulation_table, sigma_w(snr_index),...
                  N, it_scheme(it_index), ctc_p_input_table, ctc_p_step_table, puncturing_pattern);
        
                error_num(it_index, snr_index) = error_num(it_index, snr_index) + sum(u ~= u_hat); % Error count
                if (error_num >= 0)
                    error_blk(it_index, snr_index) = error_blk(it_index, snr_index) + 1;
                end
            end
        end
    end
    
    if  mod(n_blk,100) == 0
        BER = error_num./(n_blk*blk_size);
        PER = error_blk./n_blk;
        save([pwd,'/results/p_bit_preview_',num2str(n_blk),'.mat'],'BER', 'PER', 'Eb_N0_dB');
    end

end

BER = error_num./(tot_bit);
PER = error_blk./tot_block;
save([pwd,'/results/p_bit_preview_',num2str(n_blk),'.mat'],'BER', 'PER', 'Eb_N0_dB');

