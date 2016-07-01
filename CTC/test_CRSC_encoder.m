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

%% CRSC ENCODER TEST 

% I choose row 5 of the code params
row = 5;

blk_size = code_params(row,1) * 8;
N = code_params(row, 10);
disp(['Block length: ', num2str(blk_size),' bit.']);

% Information message
u = randi([0, 1], blk_size, 1);

% Encoding
tic
c = CRSC_encoder(u, blk_size, N);
time = toc;

disp(['Codeword length: ', num2str(length(c)),' bit.']);
disp(' ');
disp(['Encoding time with CRSC_encoder: ', num2str(time), ' seconds.']);
tic
c_fast = fast_CRSC_encoder(u, state_update_table, output_table,...
                                    blk_size, N);
time = toc;            

disp(['Encoding time with fast_CRSC_encoder: ', num2str(time), ' seconds.']);
                                
                                