clc;
clear;
close all;

code_params = CTC.code_params();
row = 1;
blk_size = code_params(row,1)*8;
N = code_params(row, 10);
int_params = code_params(row, 11:end); % Interleaver parameters
P = getPermutationMatrix(blk_size, N, int_params); % Interleaver permutations
[p_input_table, p_step_table] = getPermutationTables(N, int_params);

u = (0:blk_size-1).';
int = P*u;