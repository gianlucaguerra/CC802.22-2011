function [ scrambled_data ] = scrambler( unscrambled_data )
% SCRAMBLER This function implements the scrambling of the standard
%            802.22 (p.330) with 
%                  * POLYNOMIAL GENERATOR of the Pseudo Random Binary 
%                    Sequence (PRBS): 1+x^14+x^15
%                  * Pseudo Random Binary Sequence (PRBS) maximal length: 
%                    L = 2^r-1 with r = 15
%                  * DATA SCRAMBLER INITIALIZATION:     
%                          0 1 1 0 1 1 1 0 0 0 1 0 1 0 1    

    % VARIABLE INITIALIZATION
    scrambled_data = zeros(1,length(unscrambled_data));
    data_scrambler = [0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1]; 

    % SCRAMBLED DATA GENERATION
    for i = 1 : numel(unscrambled_data)
        % i-th scramble bit generation
        scrambled_data(i) = mod(data_scrambler(14) + data_scrambler(15) ... 
                            + unscrambled_data(i), 2);
        % data_scambler update: pos15 = pos14 + pos15 and rotate
        data_scrambler(15) = mod((data_scrambler(14) ... 
                            + data_scrambler(15)), 2);
        data_scrambler = circshift(data_scrambler ,[0 1]);
    end



end

