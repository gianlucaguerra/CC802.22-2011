function [ codeword ] = bcc_enc( uncoded_bits )
%BCC_ENC Binary convolutional encoder for code
% (171o, 133o) defined in standard 802.22 (p. 330), the base version
% is a rate 1/2 code, different rates can be implemented through PUNCTURING

   
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
    %  * Starting from state s_0 = 0
    state = zeros(K-1,1);
    %  * Codeword initialiazation
    codeword = zeros(2*(numel(uncoded_bits)+numel(state)), 1);
    %  * Padding to force the last state to s = 0 
    uncoded_bits = [uncoded_bits; zeros(length(state), 1)]; 
    
    % Enconding:
    for l = 1 : numel(uncoded_bits)
        codeword(2*l-1:2*l) = output_function(uncoded_bits(l), state).';
        state = state_update_function(uncoded_bits(l), state);
    end
    
end

