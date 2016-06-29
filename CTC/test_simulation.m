% SIMULATION TEST 

clc; clear;
addpath(genpath('.'));


%% LOAD OF VARIABLES
%  * CTC interleaver parameters
    code_params = load_code_params();
    
% *************************************
row = 1;
blk_size = code_params(row,1)*8;
N = code_params(row, 10);
int_params = code_params(row, 11:end);

u = randi([0, 1], blk_size, 1);

% *************************************

P = getPermutationMatrix(blk_size, N, int_params);


