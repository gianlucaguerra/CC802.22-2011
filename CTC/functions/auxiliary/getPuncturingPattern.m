function [ puncturing_pattern ] = getPuncturingPattern( puncturing_vector, N )
%GET_PUNCTURING_PATTERN 
    
    n = size(CRSC.M,1);
    k = size(CRSC.P,2);
    l = length(puncturing_vector);
    puncturing_pattern = zeros(N*(2*n-k),1); 
    for i = 0 : N - 1
       puncturing_pattern(i*(2*n-k)+1:(i+1)*(2*n-k),1) = [ones(k,1); ones(2*(n-k),1).*puncturing_vector(mod(i,l)+1)];
    end

end

