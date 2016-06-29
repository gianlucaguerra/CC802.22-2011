function [ u_hat ] = bcc_dec( rho )
% BCC_DEC Function that implements VITERBI decoding for BCC_ENC encoder

    % CODE PROPERTIES
    % Octal representation of the code (Given by the standard)
    octal_A = 171;
    octal_B = 133;
    
    % Definition of g(D)
    g_A = dec2bin(oct2dec(octal_A))-'0';
    g_B = dec2bin(oct2dec(octal_B))-'0';
    
    g = [g_A; g_B];
    
    % Constraints length K
    K = length(g_A);
    v = K-1;
    
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

    % Neighbour matrix generation
    neighbour_matrix = zeros(64, 8);
    for s = 1 : 64
        bin_state = [zeros(1,6-length(dec2bin(s-1)-'0')), dec2bin(s-1)-'0'].';
        for i = 0 : 1   
            output = (output_function(i, bin_state)).';
            next_state = bin2dec(num2str(state_update_function(i, bin_state).'))+1;
            if neighbour_matrix(next_state,1) == 0
                neighbour_matrix(next_state,:) = [s, i, output, 0, 0, 0, 0];
            else
                neighbour_matrix(next_state,:) = ...
                neighbour_matrix(next_state,:) + [0, 0, 0, 0, s, i, output];
            end
        end
    end
    
    % SOFT VITERBI_DECODING
    k = length(rho)/2;
    neighbours_index = 1:4:8;
    input_index = 2:4:8;
    Gamma = Inf(64,k+1);
    Gamma(1,1) = 0;
    Survivor_state = zeros(64,k+1);
    Survivor_input = zeros(64,k+1);
    path_metric = zeros(1,2);
    u_hat = zeros(1,k);
    
    for t = 1:k
        r = rho(2*t-1:2*t).';
        for s = 1:64
            for i = 1:2
                y = neighbour_matrix(s, 2*i+2*(i-1)+1:2*(i+1)+2*(i-1));
                cost = norm(r-(2.*y-ones(1,2)))^2;
                path_metric(i) = cost + Gamma(neighbour_matrix(s,neighbours_index(i)),t);
            end
            [min_path, index] = min(path_metric);
            Gamma(s,t+1) = min_path;
            Survivor_state(s, t+1) = neighbour_matrix(s,neighbours_index(index));
            Survivor_input(s, t+1) = neighbour_matrix(s,input_index(index));
        end
    end
    
    % Backtracking
    last_state = 1;
    for t=k+1:-1:2
        u_hat(t-1) = Survivor_input(last_state,t);
        last_state = Survivor_state(last_state,t);
    end
    
    u_hat = u_hat(1:k-(K-1));

end



