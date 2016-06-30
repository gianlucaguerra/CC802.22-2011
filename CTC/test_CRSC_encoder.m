% CIRCULAR RECURSIVE SYSTEMATIC CONVOLUTIONAL ENCODER TEST 

clc; clear;
addpath(genpath('.'));


%% LOAD OF VARIABLES
%  * CTC parameters
    code_params = CTC.code_params();
    

%% CRSC ENCODER TEST 

% I choose row 5 of the code params
row = 5;

blk_size = code_params(row,1) * 8;
N = code_params(row, 10);

% Information message
u = randi([0, 1], blk_size, 1);
c = CRSC_encoder(u, blk_size, N);