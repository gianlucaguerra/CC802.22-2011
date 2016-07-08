% CIRCULAR RECURSIVE SYSTEMATIC CONVOLUTIONAL ENCODER TEST 

clc; clear;
addpath(genpath('.'));

disp('CRSC ENCODER/DECODER TEST');
disp(' ');

%% LOAD OF VARIABLES

% CTC parameters
disp('Loading CTC main table...');
code_params = CTC.code_params();
% Look-up tables generation
disp('Generating look-up table for the CRSC code...');
[output_table, state_update_table, neighbours_table] = getLookUpTables();
disp(' ');

%% CRSC ENCODER/DECODER TEST 

% I choose row 5 of the code params
row = 5;

blk_size = code_params(row,1) * 8;
N = code_params(row, 10);
disp(['Block length: ', num2str(blk_size),' bit.']);

% Information message
u = randi([0, 1], blk_size, 1);

% Encoding (epsilon)
tic
c = CRSC_encoder(u, N);
time = toc;
disp(['Codeword length: ', num2str(numel(c)),' bit.']);
disp(' ');
disp(['Encoding time with CRSC_encoder: ', num2str(time), ' seconds.']);
tic
c_fast = fast_CRSC_encoder(u, state_update_table, output_table, N);
time = toc;            
disp(['Encoding time with fast_CRSC_encoder: ', num2str(time), ' seconds.']);
disp(' ');

% Conform map (Omega)
disp('Conform map : Binary to Binary');
M = 2;
d = c_fast;
disp(['Total number of symbols per block: ', num2str(numel(d)),' symbols.']);
disp(' ');

% Constellation map (L)
disp('Modulation: 2-PAM');
L = @(x) 2.*x-(M-1);
s = L(d);
disp(' ');

% Channel
Eb_N0_dB = 5;
Eb_N0 = 10^(Eb_N0_dB/10);
R = 2/3;
Es = 1;
sigma_w = sqrt(Es/(2*R*log2(M)*Eb_N0)); 
disp(['Channel: Eb_N0 = ',num2str(Eb_N0_dB),' dB ==> sigma_w = ', num2str(sigma_w)]);
disp(' ');
w = randn(size(s,1),size(s,2)).*sigma_w;      % Noise generation
r = s + w;

% MAP decoding
modulation_table = getModulationTable(size(c_fast,2), L, M); 
tic;
u_hat = CRSC_decoder(r, state_update_table, output_table,...
                             neighbours_table, modulation_table, sigma_w);
time = toc;
error_num = sum(u ~= u_hat);
disp('Deconding algorithm: BCJR.');
disp(['Decoding time with CRSC_dencoder: ', num2str(time), ' seconds.']);
disp(['Number of error after the decoding: ', num2str(error_num), '.']);