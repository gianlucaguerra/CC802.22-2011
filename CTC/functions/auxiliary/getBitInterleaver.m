function [ bit_P_matrix, bit_p_table ] = getBitInterleaver(K, bit_int_params )
%GETBITINTERLEAVER This function give permutation matrix and permutation
% table for the BICM bit interleaver. 

    % Interleaver parameters
    p = bit_int_params(1);
    q = bit_int_params(2);
    j = bit_int_params(3);
    
    % Output initialization
    bit_P_matrix = zeros(K);
    bit_p_table = zeros(1, K);
   
    
    for k = 0 : K - 1
        I = k;
        for m = 1 : j
            I = mod( K - p + k + q * p * mod(-k-p*I, K), K);
        end
        bit_P_matrix(k+1, I+1) = 1;
    end

    bit_P_matrix = inv(bit_P_matrix); 
    bit_p_table = (bit_P_matrix*(0:length(bit_P_matrix)-1).').';
    
end

