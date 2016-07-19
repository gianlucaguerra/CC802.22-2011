% SIMULATION BINARY CTC

clc; clear;
addpath(genpath('.'));

% .-------------------------------.
% |     PARAMETERS TO CHANGE      |
% '-------------------------------'
    code_params_row = 24;
    rate = '1/2';                                                            % TO CHANGE
    modulation = 'QPSK';                                                     % TO CHANGE
    
    SNR_dB_bimc_qpsk = [0, 0.5, 0.7, 0.9, 1.1, 1.3, 1.6, 2];                 % TO CHANGE
   
    
    it_scheme = 20;  % 1 2 4 10 20                                           % TO CHANGE
     
    tot_bit = 2e3;
% ---------------------------------

% Parameters
code_params = CTC.code_params();

% Genereral code parameters
blk_size = code_params(code_params_row,1)*8;                                             % Information block length

% Codeword length, M and constellation map
switch [modulation, rate]
    case ['QPSK', '1/2']
        codeword_length = code_params(code_params_row, 2)*8;
        M = 4;
        constellation_table = BICM.QPSK;
        conform = BICM.conform_QPSK;
    case ['QPSK', '3/4']
        codeword_length = code_params(code_params_row, 3)*8;
        M = 4;
        constellation_table = BICM.QPSK;
        conform = BICM.conform_QPSK;
    case ['16-QAM', '1/2']
        codeword_length = code_params(code_params_row, 4)*8;
        M = 16;
        constellation_table = BICM.QAM16;
        conform = BICM.conform_QAM16;
    case ['16-QAM', '3/4']
        codeword_length = code_params(code_params_row, 5)*8;
        M = 16;
        constellation_table = BICM.QAM16;
        conform = BICM.conform_QAM16;
    case ['64-QAM', '1/2']
        codeword_length = code_params(code_params_row, 6)*8;
        M = 64;
        constellation_table = BICM.QAM64;
        conform = BICM.conform_QAM64;
    case ['64-QAM', '2/3']
        codeword_length = code_params(code_params_row, 7)*8;
        M = 64;
        constellation_table = BICM.QAM64;
        conform = BICM.conform_QAM64;
    case ['64-QAM', '3/4']
        codeword_length = code_params(code_params_row, 8)*8;
        M = 64;
        constellation_table = BICM.QAM64;
        conform = BICM.conform_QAM64;
    case ['64-QAM', '5/6']
        codeword_length = code_params(code_params_row, 9)*8;
        M = 64;
        constellation_table = BICM.QAM64;
        conform = BICM.conform_QAM64;
    otherwise
        codeword_length = blk_size./str2num(rate);   
        M = 2;
        constellation_table = BICM.PAM2;
        conform = BICM.conform_PAM2;
end

% Simulation parameters
tot_blk = ceil(tot_bit/codeword_length);                                      % Total number of blocks to send

N = code_params(code_params_row, 10); % Number of input pairs

% CTC interleaver and BICM bit interleaver matrices and tables
ctc_int_params = code_params(code_params_row, 11:end); % CTC interleaver parameters
ctc_P_matrix = getPermutationMatrix(blk_size, N, ctc_int_params); % UP2DOWN  CTC interleaver permutation matrix
[ctc_p_input_table, ctc_p_step_table] = getPermutationTables(N, ctc_int_params); % DOWN2UP CTC permutation tables
if (codeword_length > 2304)       % Maximal length for the vector to be interleaved: 2304 bit
    K = codeword_length/2;
    bit_int_params = BICM.bit_int_params(BICM.bit_int_params(:,1)==K, 2:end); % BICM interleaver parameters
    [bit_P_matrix, bit_p_table] = getBitInterleaver(K, bit_int_params);
    bit_P_matrix = blkdiag(bit_P_matrix, bit_P_matrix);
    bit_p_table = [bit_p_table, bit_p_table+K];
else
    K = codeword_length;
    bit_int_params = BICM.bit_int_params(BICM.bit_int_params(:,1)==K, 2:end); % BICM interleaver parameters
    [bit_P_matrix, bit_p_table] = getBitInterleaver(K, bit_int_params);
end

% Conform table
conform_table = getConformTable(M, conform);

% CRSC code component output and state update tables
[crsc_output_table, crsc_state_update_table, crsc_neighbours_table] = getLookUpTables();

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
BER_bicm_qpsk = zeros(1,length(SNR_dB_bimc_qpsk));                                                    % TO CHANGE
PER_bicm_qpsk = zeros(1,length(SNR_dB_bimc_qpsk));                                                    % TO CHANGE

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
SNR = 10.^(SNR_dB_bimc_qpsk./10);                                         % TO CHANGE
Es = 1;

w_I = randn(codeword_length/log2(M),1);  % In-phase noise component
if strcmp(modulation, '2-PAM')
    sigma_w = sqrt(Es./SNR); %!!
    w = w_I;                       % Only in-phase component pattern
else
    sigma_w = sqrt(Es./(2.*SNR)); %!!
    w_Q = randn(codeword_length/log2(M),1);  % Quadrature noise component
    w = w_I + 1j*w_Q;    % Noise pattern
end

% Information message generation
s = zeros(tot_blk, codeword_length/log2(M));
u = zeros(tot_blk, blk_size);
parfor i = 1 : tot_blk
    % Information block generation
    u(i,:) = randi([0, 1], blk_size, 1);
    
    % ENCODER: CTC Encoding with puncturing, the output is a column vector of
    % length codeword_length
    c = CTC_enc_p(u(i,:).', crsc_state_update_table, crsc_output_table, N, ctc_P_matrix, puncturing_pattern);
    
    % Bit interleaving for BICM
    c_i = bit_P_matrix * c;
    
    % CONFORM: The conform map gives a matrix codeword_length/log2(M) x log2(M)
    d = reshape(c_i, log2(M), []).';
    
    % CONSTALLATION MAP
    s(i,:) = constellation_mapper (d, M, constellation_table);
   
end

 parfor snr_index = 1 : length(SNR)                                        % Across all SNR
    errors = 0;
    errors_blk = 0;
    w_s = w .* sigma_w(snr_index);                                    % Noise scaling      
    for n_blk = 1 : tot_blk                                                      % Across all packet
        r = s(n_blk,:).' + w_s;                                                           % Received sequence
        u_hat = BICM_decoder(r, M, sigma_w(snr_index), constellation_table, codeword_length, N, ...
           conform_table, bit_p_table, puncturing_pattern, ...
           crsc_output_table, crsc_state_update_table, crsc_neighbours_table,...
           ctc_p_input_table, ctc_p_step_table, it_scheme);
        errors = errors + sum(u(n_blk,:) ~= u_hat.'); % Error count
         if ( sum(u(n_blk,:) ~= u_hat.')> 0)
             errors_blk = errors_blk + 1;
         end 
    end
    
    BER_bicm_qpsk(snr_index) = errors./(tot_bit);                              % TO CHANGE
    PER_bicm_qpsk(snr_index) = errors_blk./tot_blk;                            % TO CHANGE
       
    disp(['w3 :',num2str(SNR_dB_bimc_qpsk(snr_index))]);                     % TO CHANGE

end

%save([pwd,'/results/p_bit_it20_l120.mat'],'BER_it20_l120', 'PER_it20_l120', 'Eb_N0_dB_it20_l120');   % TO CHANGE!!!

