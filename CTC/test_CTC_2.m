% TEST CTC_2


clc; clear;
addpath(genpath('.'));

% .-------------------------------.
% |     PARAMETERS TO CHANGE      |
% '-------------------------------'
    code_params_row = 41;
    rate = '1/2';                                                               % TO CHANGE
        
    Eb_N0_dB = -1;                                          % TO CHANGE    
    it_scheme = 1;  % 1 2 4 10 20  
    
% ---------------------------------

% Parameters
code_params = CTC.code_params();

% Genereral code parameters
blk_size = code_params(code_params_row,1)*8;                                             % Information block length
codeword_length = blk_size./str2num(rate);                                               % Codeword block length 
R = str2num(rate);

Eb_N0 = 10.^(Eb_N0_dB./10);

% Modulation parameters
M = 2;                                                                                   % Number of constellation symbols
L = @(x) 2.*x-(M-1);                                                                     % Constellation map
Es = 1;
modulation_table = getModulationTable(size(CRSC.P,1), L, M);  

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
sigma_w = sqrt(Es./(2.*R.*log2(M).*Eb_N0));    

% Information block generation
u = randi([0, 1], blk_size, 1);
    
% ENCODER: CTC Encoding with puncturing, the output is a column vector of
% length codeword_length
c = CTC_enc_p(u, crsc_state_update_table, crsc_output_table, N, ctc_P_matrix, puncturing_pattern);
    
% MODULATOR
s = L(c);

w_s = w .* sigma_w;
r = s + w_s;
% u_hat = CTC_dec_p(r, crsc_state_update_table, crsc_output_table,...         % Decoding
%                crsc_neighbours_table, modulation_table, sigma_w,...
%                N, it_scheme, ctc_p_input_table, ctc_p_step_table, puncturing_pattern);
u_hat = CTC_dec_minsum_mex(r, crsc_state_update_table, crsc_output_table,...         % Decoding
               crsc_neighbours_table, modulation_table, sigma_w,...
               N, it_scheme, ctc_p_input_table, ctc_p_step_table, puncturing_pattern);

errors = sum(u ~= u_hat);
disp(['Block length: ', num2str(blk_size), ' bit.']);
disp(['Rate: ', rate, '.']);
disp(['Eb/N0: ', num2str(Eb_N0_dB), ' dB.']);
disp(['Decoding iterations:: ', num2str(it_scheme), '.']);
disp(['Number of error after the decoding: ', num2str(errors), '.']);