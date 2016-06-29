function [ codeword ] = bcc_tb_punc_enc( uncoded_bits, rate)
%BINARY_CONVOLUTIONAL_ENCODER WITH TAIL BITING Binary convolutional encoder 
% for code (171o, 133o) defined in standard 802.22 (p. 330), the base version
% is a rate 1/2 code, different rates are implemented through PUNCTURING
% ALLOWED RATE are: 1/2, 2/3, 3/4, 5/6   
   
    % Octal representation of the code (Given by the standard)
    octal_A = 171;
    octal_B = 133;
    
    % Definition of g(D)
    g_A = dec2bin(oct2dec(octal_A))-'0';
    g_B = dec2bin(oct2dec(octal_B))-'0';
    
    g = [g_A; g_B];
    
    % Constraints length K
    K = length(g_A);
    
    % Output function definition:  
    output_function = @(u, state) xor(g(:, 1) .* u , g(:, 2:end) * state); 
    
    % State update function definition: (doens't depends on the code,
    % simply last inpute enters in the registry and the last goes out)
    state_update_function = @(u, state) xor([1; 0; 0; 0; 0; 0] .* u ...
                  , [0, 0, 0, 0, 0, 0; ...
                     1, 0, 0, 0, 0, 0; ...
                     0, 1, 0, 0, 0, 0; ...
                     0, 0, 1, 0, 0, 0; ...
                     0, 0, 0, 1, 0, 0; ...
                     0, 0, 0, 0, 1, 0] * state);
    
    % Finite state machine initialization:
    %  * Starting from state s_0 = [b_(M-1) b_(M-2) ... b_(M-K)]
    state = flip(uncoded_bits(end-(K-1)+1:end),1);
    %  * Codeword initialiazation
    codeword = zeros(2*numel(uncoded_bits), 1);
    
    % Enconding:
    for l = 1 : numel(uncoded_bits)
        codeword(2*l-1:2*l) = output_function(uncoded_bits(l), state).';
        state = state_update_function(uncoded_bits(l), state);
    end
    
    % Puncturer
    switch rate
        case '1/2'
        case '2/3'
            puncturer = (3:4:numel(codeword));
            codeword(puncturer) = [];
        case '3/4'
            puncturer = (3:3:numel(codeword));
            codeword(puncturer) = [];
        case '5/6'
            puncturer = sort([(3:10:numel(codeword)), (6:10:numel(codeword))...
                        , (7:10:numel(codeword)), (10:10:numel(codeword))]);
            codeword(puncturer) = [];
        otherwise
            disp('RATE INVALID. Valid rates are 1/2, 2/3, 3/4, 5/6.');
    end
    
end

