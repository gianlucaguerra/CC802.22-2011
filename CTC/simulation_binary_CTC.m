% SIMULATION BINARY CTC

clc; clear;
addpath(genpath('.'));

% .-------------------------------.
% |     PARAMETERS TO CHANGE      |
% '-------------------------------'
    code_params_row = 41;
    rate = '1/2';                                                               % TO CHANGE
        
    Eb_N0_dB_it10_minsum = (0:0.25:6);                            % TO CHANGE
   
    
    it_scheme = 10;  % 1 2 4 10 20                                               % TO CHANGE
     
    tot_bit = 1e7;  
% ---------------------------------


% Parameters
code_params = CTC.code_params();

% Genereral code parameters
blk_size = code_params(code_params_row,1)*8;                                             % Information block length
codeword_length = blk_size./str2num(rate);                                               % Codeword block length 
R = str2num(rate);                                                                       % Code rate

% Simulation parameters
tot_blk = ceil(tot_bit./codeword_length);                                                 % Total number of blocks to send
Eb_N0 = 10.^(Eb_N0_dB_it10_minsum./10);                                                      % TO CHANGE

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
BER_it10_minsum = zeros(1,length(Eb_N0));                                                    % TO CHANGE
PER_it10_minsum = zeros(1,length(Eb_N0));                                                    % TO CHANGE

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

% Information message generation
s = zeros(tot_blk, codeword_length);
u = zeros(tot_blk, blk_size);
parfor i = 1 : tot_blk
    % Information block generation
    u(i,:) = randi([0, 1], blk_size, 1);
    
    % ENCODER: CTC Encoding with puncturing, the output is a column vector of
    % length codeword_length
    c = CTC_enc_p(u(i,:).', crsc_state_update_table, crsc_output_table, N, ctc_P_matrix, puncturing_pattern);
    
    % MODULATOR
    s(i,:) = L(c);
   
end

 parfor snr_index = 1 : length(Eb_N0)                                        % Across all SNR
    errors = 0;
    errors_blk = 0;
    w_s = w .* sigma_w(snr_index);                                    % Noise scaling      
    for n_blk = 1 : tot_blk                                                      % Across all packet
        r = s(n_blk,:).' + w_s;                                                           % Received sequence
%         u_hat = CTC_dec_p_mex(r, crsc_state_update_table, crsc_output_table,...         % Decoding
%                crsc_neighbours_table, modulation_table, sigma_w(snr_index),...
%                N, it_scheme, ctc_p_input_table, ctc_p_step_table, puncturing_pattern);
        u_hat = CTC_dec_minsum_mex(r, crsc_state_update_table, crsc_output_table,...         % Decoding
               crsc_neighbours_table, modulation_table, sigma_w(snr_index),...
               N, it_scheme, ctc_p_input_table, ctc_p_step_table, puncturing_pattern);
           
        errors = errors + sum(u(n_blk,:) ~= u_hat.'); % Error count
         if ( sum(u(n_blk,:) ~= u_hat.')> 0)
             errors_blk = errors_blk + 1;
         end 
    end
    
    BER_it10_minsum(snr_index) = errors./(tot_bit);                              % TO CHANGE
    PER_it10_minsum(snr_index) = errors_blk./tot_blk;                            % TO CHANGE
       
    disp(['w3 :',num2str(Eb_N0_dB_it10_minsum(snr_index))]);                     % TO CHANGE

end

save([pwd,'/results/p_bit_it10_minsum.mat'],'BER_it10_minsum', 'PER_it10_minsum', 'Eb_N0_dB_it10_minsum');   % TO CHANGE!!!

