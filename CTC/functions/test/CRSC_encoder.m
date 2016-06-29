function [ c ] = CRSC_encoder(u, blk_size, N)
% CRSC_ENCODER Component encoder for the CTC
% Rate 2/3, parameter of the code in /config/CRSC_params/

% Load the code specs
[ G, H, m, n ] = load_CRSC_params();

% Codeword initialization (systematic code)
c = zeros(blk_size + N * size(n,2),1);
c(1:blk_size) = u;


end

