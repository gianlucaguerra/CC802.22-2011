function [p_input_table, p_step_table] = getPermutationTables(N, int_params)
% GETPERMUTATIONTABLE: Function to get the permutation tables to implement
% the TCT decoder
    
    k = size(CRSC.P,2);

    % Input permutation table
    p_input_table = zeros(2^k, N);
    for j = 0 : N-1
        if mod(j, 2) == 0
            p_input_table(:, j+1) = [0; 2; 1; 3];
        else
            p_input_table(:, j+1) = [0; 1; 2; 3];
        end
    end
    
    % Step permutation table
    p_step_table = zeros(2^k, N);
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
        p_step_table(:, j+1) = ones(2^k,1).*i; 
    end

end

