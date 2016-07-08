function [ P ] = getPermutationMatrix(blk_size, N, int_params )
% GETPERMUTATIONMATRIX Return the permutation matrix for the CTC interleaver
% The function takes as input the block size, N and the interleaver 
% parameters (table 212 p.334)

% 1st level matrix permutation (intrapair)
P1 = zeros(blk_size);
for j = 0 : N-1
   if mod(j, 2)==0
       P1(2*j+1, 2*j+2) = 1;
       P1(2*j+2, 2*j+1) = 1;
   else
       P1(2*j+1, 2*j+1) = 1;
       P1(2*j+2, 2*j+2) = 1;
   end
end

% 2nd level matrix permutation (pairwise)
P2 = zeros(blk_size);
for j = 0 : N-1
    switch mod(j, 4)
        case 0
            P = 0;
        case 1
            P = N/2 + int_params(2);
        case 2
            P = int_params(3);
        case 3
            P = N/2 + int_params(4);
    end
    i = mod(int_params(1)*j+P+1,N);    
    P2(2*i+1, 2*j+1) = 1;
    P2(2*i+2, 2*j+2) = 1;    
end
P = P2*P1;
P = P.';

end

