% SIMULATION TEST 

clc; clear;
addpath(genpath('.'));

disp('CTC ENCODER/DECODER TEST');
disp(' ');

%% LOAD OF VARIABLES

% CTC parameters
disp('Loading CTC main table...');
code_params = CTC.code_params();
disp(' ');


%% CTC ENCODER/DECODER TEST

% For the test is used the 7th row of the CTC.code_params, in particular
%   blk_size:        30 byte
%   rate:            1/2
%   conform:         B2B
%   modulation:      2 - PAM 

disp('CODE:');
row = 46;
blk_size = code_params(row,1)*8;
disp(['Block length: ', num2str(blk_size),' bit.']);
codeword_length = code_params(row,2)*8;
disp(['Codeword length: ', num2str(codeword_length),' bit.']);
R = blk_size/codeword_length;
disp(['Rate: ', num2str(R),'.']);
disp(' ');

% Information message
u = randi([0, 1], blk_size, 1);

% Encoding (epsilon)
disp('ENCODER:');
N = code_params(row, 10);              % Number of vector input of length k
disp(['N: ', num2str(N), ' input vectors']);

disp('Generating permutation matrix for the interleaver... ');
int_params = code_params(row, 11:end); % Interleaver parameters
P = getPermutationMatrix(blk_size, N, int_params); % Interleaver permutations

disp('Generating look-up table for the CRSC component code...'); % Look-up tables generation
[output_table, state_update_table, neighbours_table] = getLookUpTables();

tic;
c = CTC_encoder(u, state_update_table, output_table, N, P);
time = toc;
disp(['Encoding time with CTC_encoder: ', num2str(time), ' seconds.']);
disp(' ');

% Modulation
disp('MODULATION:');
disp('Conform map : Binary to Binary');
M = 2;
d = c;    % Conform map (Omega)
disp(['Total number of symbols per block: ', num2str(numel(d)),' symbols.']);
disp('COnstellation map: 2-PAM');
L = @(x) 2.*x-(M-1);       % Constellation map (L)
s = L(d);
disp(' ');

% Channel
disp('CHANNEL:');
Eb_N0_dB = 20;
Eb_N0 = 10^(Eb_N0_dB/10);
Es = 1;
sigma_w = sqrt(Es/(2*R*log2(M)*Eb_N0)); 
disp(['Channel: Eb_N0 = ',num2str(Eb_N0_dB),' dB ==> sigma_w = ', num2str(sigma_w)]);
disp(' ');
w = randn(size(s,1),size(s,2)).*sigma_w;      % Noise generation
r = s + w;

% MAP decoding
modulation_table = getModulationTable(size(CRSC.P,1), L, M); 
[p_input_table, p_step_table] = getPermutationTables(N, int_params);
% tic;
n_it = 1;
u_hat = CTC_decoder(r, state_update_table, output_table,...
                  neighbours_table, modulation_table, sigma_w,...
                  P, N, n_it, p_input_table, p_step_table);
time = toc;
error_num = sum(u ~= u_hat);
disp('Deconding algorithm: BCJR.');
disp(['Decoding time with CRSC_dencoder: ', num2str(time), ' seconds.']);
disp(['Number of error after the decoding: ', num2str(error_num), '.']);
P_bit = error_num./blk_size;
disp(['BER: ', num2str(P_bit), '.']);
disp(' ');