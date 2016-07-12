% BICM TEST 

clc; clear;
addpath(genpath('.'));

disp('BINARY INTERLEAVED CODE MODULATION TEST');
disp(' ');
code_params = CTC.code_params();  % CTC main parameters table

% .-------------------------------.
% |     PARAMETERS TO CHANGE      |
% '-------------------------------'
    code_params_row = 46;
    modulation = '64-QAM';
    rate = '5/6';
    
    Eb_N0_dB = 10;

% ---------------------------------

% PARAMETERS
blk_size = code_params(code_params_row,1)*8; 

% Codeword length, and M 
switch [modulation, rate]
    case ['QPSK', '1/2']
        codeword_length = code_params(code_params_row, 2)*8;
        M = 4;
    case ['QPSK', '3/4']
        codeword_length = code_params(code_params_row, 3)*8;
        M = 4;
    case ['16-QAM', '1/2']
        codeword_length = code_params(code_params_row, 4)*8;
        M = 16;
    case ['16-QAM', '3/4']
        codeword_length = code_params(code_params_row, 5)*8;
        M = 16;
    case ['64-QAM', '1/2']
        codeword_length = code_params(code_params_row, 6)*8;
        M = 64;
    case ['64-QAM', '2/3']
        codeword_length = code_params(code_params_row, 7)*8;
        M = 64;
    case ['64-QAM', '3/4']
        codeword_length = code_params(code_params_row, 8)*8;
        M = 64;
    case ['64-QAM', '5/6']
        codeword_length = code_params(code_params_row, 9)*8;
        M = 64;
    otherwise
        codeword_length = blk_size./str2num(rate);   
        M = 2;
end

ctc_int_params = code_params(code_params_row, 11:end); % CTC interleaver parameters
N = code_params(code_params_row, 10); % Number of input pairs

% CTC interleaver and BICM bit interleaver matrices and tables
ctc_P_matrix = getPermutationMatrix(blk_size, N, ctc_int_params); % UP2DOWN  CTC interleaver permutation matrix
[ctc_p_input_table, ctc_p_step_table] = getPermutationTables(N, ctc_int_params); % DOWN2UP CTC permutation tables
% (TO DO  bit interleaver for BICM)

% CRSC code component output and state update tables
[crsc_output_table, crsc_state_update_table, crsc_neighbours_table] = getLookUpTables();

% Puncturing patterns
switch rate
    case '1/2' 
        puncturing_vector = CTC.puncturing_matrix(1,:);
        R = 1/2;
    case '2/3'
        puncturing_vector = CTC.puncturing_matrix(2,:);
        R = 2/3;
    case '3/4'
        puncturing_vector = CTC.puncturing_matrix(3,:);
        R = 3/4;
    case '5/6'
        puncturing_vector = CTC.puncturing_matrix(4,1:end-1);
        R = 5/6;
end
puncturing_pattern = getPuncturingPattern( puncturing_vector, N );


% TRANSMISSION SCHEME

%                  TRANSMITTER               CHANNEL     RECEIVER
%    <-------------------------------------><-------><------------->
%        (bit interleaving)                     w      
%    .---------. * .---------.   .---------.    |    .---------.
% ---| ENCODER |---| CONFORM |---|    L    |---(+)---| DECODER |---
%  u '---------' c '---------' d '---------' s     r '---------' u_hat
%                  <----------------------->
%                           MODULATOR


% Information message generation: u
u = randi([0, 1], blk_size, 1);

% ENCODER: CTC Encoding with puncturing, the output is a column vector of
% length codeword_length
c = CTC_enc_p(u, crsc_state_update_table, crsc_output_table, N, ctc_P_matrix, puncturing_pattern);

% Bit interleaving for BICM (TO DO)


% CONFORM: The conform map gives a matrix codeword_length/log2(M) x log2(M)
d = reshape(c, [], log2(M));

% CONSTELLATION MAP 
s = constellation_mapper (d, M);

% CHANNEL: AWGN memoryless
Eb_N0 = 10^(Eb_N0_dB/10);
Es = 1;
sigma_w = sqrt(Es/(2*R*log2(M)*Eb_N0));
w_I = randn(size(s,1),size(s,2));  % In-phase noise component
if strcmp(modulation, '2-PAM')
    w = w_I;                       % Only in-phase component pattern
    w = w .*sigma_w;               % Scaling the noise
else
    w_Q = randn(size(s,1),size(s,2));  % Quadrature noise component
    w = w_I + w_Q;    % Noise pattern
    w = w .* sigma_w/sqrt(2);
end
r = s + w;

% DISPLAY MESSAGES
disp('PARAMETERS:');
disp(' ');
disp(['Code parameters row: ', num2str(code_params_row),'.']);
disp(['Modulation: ', modulation,'.']);
disp(['Rate: ', rate,'.']);
disp(['Es/N0: ' , num2str(Eb_N0_dB), ' dB.']);
disp(['Block length: ', num2str(blk_size),'.']);
disp(['Codeword length: ', num2str(codeword_length),'.']);





