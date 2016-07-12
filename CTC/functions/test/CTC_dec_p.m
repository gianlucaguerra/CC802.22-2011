function [ u_hat ] = CTC_dec_p(r, state_update_table, output_table, ...
             neighbours_table, modulation_table, sigma_w, ...
             P, N, n_it, p_input_table, p_step_table, puncturing_pattern )
% CTC_DECODER: Basic CTC decoding through message passing 
    
    % CRSC code component params
    crsc_k = size(CRSC.P,2);
    crsc_n = size(CRSC.P,1);
    crsc_v = length(CRSC.G);
    
%   piece_const = log(1+exp(-(0:5)));% TO IMPLEMENT AND SEE THE DIFFERENCE!

    % De-puncturing of the received sequence in a N x (2n-k) matrix
    r_dep = zeros(N, 2*crsc_n-crsc_k);
    index_r = 0;
    index_p = 0;
    for i = 0 : N -1  
         for j = 0 : 2*crsc_n-crsc_k-1
            if (puncturing_pattern(index_p+1) == 1)
                 r_dep(i+1, j+1) = r(index_r+1);
                 index_r = index_r + 1;
            else
                 r_dep(i+1, j+1) = 0;
            end
            index_p = index_p + 1;
         end
    end

    % MESSAGE PASSING DECODING ALGORITHM

    % 1. INITIALIZATION
    
    % 1.1 The q vector is initialized to the a priori probability,
    q = log(ones(2^crsc_k, N)./(2^crsc_k)); % Row: input  | Column: step l
    q = bsxfun(@minus, q, max(q)); % Normalization
    
    % 1.2 Two g vectors: g1 for the upper code and g2 for the lower one
    g1 = zeros(2^crsc_n, N);      % Row: output | Column: step l in blocks
    g2 = zeros(2^crsc_n, N);      % Row: output | Column: step l in blocks   
    % To compute g2 we use must rebuild the part due to the lower encoder
    % using the inverse of the permutation matrix P^-1 = P^T
    r1 = r_dep(:,1:crsc_n);
    r2 = [reshape(P*(reshape(r_dep(:,[1,2]).', 1,[]).'),2,[]).',r_dep(:, crsc_n+1:end)];
    for l = 0 : N - 1
        for  y = 0 : 2^crsc_n - 1
            mod_y = modulation_table(y+1,:).*puncturing_pattern(l*(2*crsc_n-crsc_k)+1:l*(2*crsc_n-crsc_k)+crsc_n).';
            g1(y+1, l+1) = ...
                    sum(abs(r1(l+1,:) - mod_y).^2);
            g2(y+1, l+1) = ...
                    sum(abs(r2(l+1,:) - mod_y).^2);    
        end
    end
    g1 = -1/(2*sigma_w^2).*g1;
    g2 = -1/(2*sigma_w^2).*g2;
    g1 = bsxfun(@minus, g1, max(g1)); % Normalization
    g2 = bsxfun(@minus, g2, max(g2)); % Normalization
    
    E2 = 0;
    E1 = 0;
   
    for cont = 1 : n_it
    
        % 2 BCJR ALGORITHM ON THE UPPER CODE
    
        % 2.0 BCJR initialization 
        backward_matrix = -Inf(2^crsc_v, N);   % Row: state  | Column: step l
        forward_matrix = -Inf(2^crsc_v, N);    % Row: state  | Column: step l
        extrinsic_matrix = -Inf(2^crsc_k, N);  % Row: input  | Column: step l
    
        mu_eq = E2 + q;
        mu_eq = bsxfun(@minus, mu_eq, max(mu_eq));  % Normalization
        
        % 2.1 Backward messages update
        backward_matrix(1,end) = 0; % Starting with B_(N-1)(s_0) = 0 
        for l = 2*N-1 : -1 : 1      % This is a matlab matrix index
            index = mod(l,N);
            for s = 0 : 2^crsc_v - 1  % s_l
                summ = -Inf;       % Sum over u 
                for u = 0 : 2^crsc_k - 1 
                    ql_u = mu_eq(u+1, index+1);
                    y = output_table(s+1, u+1);
                    gl_y = g1(y+1, index+1);
                    s_n  = state_update_table(s+1, u+1);    % s_(l+1)
                    B_n = backward_matrix(s_n+1, index+1);
                    add = B_n + gl_y + ql_u;
                    % TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION
                    summ = log(exp(summ)+exp(add));
                end
                if index == 0
                    index2 = N;
                else
                    index2 = index;
                end
                backward_matrix(s+1, index2) = summ;           
            end
           backward_matrix(:, index2) = backward_matrix(:, index2) ...
                         - max(backward_matrix(:, index2)); % Normalization
        end
    
        % 2.2 Forward messages update
        forward_matrix(1,1) = 0; % Starting with F_0 (s_0) = 0
        for l = 2:2*N            % This is a matlab matrix index
            index = mod(l-1, N);
            if index == 0
                index2 = N;
            else 
                index2 = index;
            end
            for s = 0 : 2^crsc_v - 1  % s_(l+1)
                summ = -Inf;        % Sum over the neighbours of s
                for u_p = 0 : 2^crsc_k - 1
                    ql_u = mu_eq(u_p+1, index2);
                    s_p = neighbours_table(s+1, u_p+1);  % s_l
                    y = output_table(s_p+1, u_p+1);
                    gl_y = g1(y+1, index2);
                    F_p = forward_matrix(s_p+1, index2);
                    add = F_p + gl_y + ql_u;
                    % TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION
                    summ = log(exp(summ)+exp(add));
                end
                forward_matrix(s+1, index+1) = summ;
            end
            forward_matrix(:, index+1) = forward_matrix(:, index+1) - ...
                        max(forward_matrix(:, index+1)); % Normalization
        end
    
        % 2.3 Extrinsic message update
        index_b = 1;
        index_f = 1;
        for l = 1 : N                             % This is a matlab index!
            for u = 0 : 2^crsc_k -1
                summ = -Inf;
                for s = 0 : 2^crsc_v -1
                    s_n = state_update_table(s+1, u+1);
                    y = output_table(s+1, u+1);
                    gl_y = g1(y+1, l);
                    F = forward_matrix(s+1, index_f);
                    B = backward_matrix(s_n+1, index_b);
                    add = F + B + gl_y;
                    % TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION
                    summ = log(exp(summ)+exp(add));
                end
                extrinsic_matrix(u+1, l) = summ;
            end
            index_f = index_f + 1;
            index_b = index_b + 1;
            % index_b = mod(index_b + 1, N);        
        end
        E1 = extrinsic_matrix;
        E1 = bsxfun(@minus, E1, max(E1));  % Normalization
    
        % 2.4 Message from the equality factor update
        mu_eq = E1 + q;
        mu_eq = bsxfun(@minus, mu_eq, max(mu_eq));  % Normalization
    
        % 3 BCJR ALGORITHM ON THE LOWER CODE
        
        % 3.0 BCJR matrices initialization 
        backward_matrix = -Inf(2^crsc_v, N);   % Row: state  | Column: step l
        forward_matrix = -Inf(2^crsc_v, N);    % Row: state  | Column: step l
        extrinsic_matrix = -Inf(2^crsc_k, N);  % Row: input  | Column: step l
    
        % 3.1 Backward message update
        backward_matrix(1,end) = 0; % Starting with B_(N-1)(s_0) = 0 
        for l = 2*N-1 : -1 : 1      % This is a matlab matrix index
            index = mod(l,N);
            for s = 0 : 2^crsc_v - 1  % s_l
                summ = -Inf;       % Sum over u 
                for u = 0 : 2^crsc_k - 1 
                    ql_u = mu_eq(p_input_table(u+1, index+1)+1, p_step_table(u+1,index+1)+1);
                    y = output_table(s+1, u+1);
                    gl_y = g2(y+1, index+1);
                    s_n  = state_update_table(s+1, u+1);    % s_(l+1)
                    B_n = backward_matrix(s_n+1, index+1);
                    add = B_n + gl_y + ql_u;
                    % TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION
                    summ = log(exp(summ)+exp(add));
                end
                if index == 0
                    index2 = N;
                else
                    index2 = index;
                end
                backward_matrix(s+1, index2) = summ;           
            end
            backward_matrix(:, index2) = backward_matrix(:, index2) ...
                         - max(backward_matrix(:, index2)); % Normalization
        end
    
        % 3.2 Forward messages update
        forward_matrix(1,1) = 0; % Starting with F_0 (s_0) = 0
        for l = 2:2*N            % This is a matlab matrix index
            index = mod(l-1, N);
            if index == 0
                index2 = N;
            else 
                index2 = index;
            end
            for s = 0 : 2^crsc_v - 1  % s_(l+1)
                summ = -Inf;        % Sum over the neighbours of s
                for u_p = 0 : 2^crsc_k - 1
                    ql_u = mu_eq(p_input_table(u_p+1,index2)+1, p_step_table(u_p+1,index2)+1);
                    s_p = neighbours_table(s+1, u_p+1);  % s_l
                    y = output_table(s_p+1, u_p+1);
                    gl_y = g2(y+1, index2);
                    F_p = forward_matrix(s_p+1, index2);
                    add = F_p + gl_y + ql_u;
                    % TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION
                    summ = log(exp(summ)+exp(add));
                end
                forward_matrix(s+1, index+1) = summ;
            end
            forward_matrix(:, index+1) = forward_matrix(:, index+1) - ...
                        max(forward_matrix(:, index+1)); % Normalization
        end
    
        % 3.3 Extrinsic message update
        index_b = 1;
        index_f = 1;
        for l = 1 : N                             % This is a matlab index!
            for u = 0 : 2^crsc_k -1
                summ = -Inf;
                for s = 0 : 2^crsc_v -1
                    s_n = state_update_table(s+1, u+1);
                    y = output_table(s+1, u+1);
                    gl_y = g2(y+1, l);
                    F = forward_matrix(s+1, index_f);
                    B = backward_matrix(s_n+1, index_b);
                    add = F + B + gl_y;
                    % TO IMPLEMENT: PIECEWISE CONSTANT APPROXIMATION
                    summ = log(exp(summ)+exp(add));
                end
                %extrinsic_matrix(u+1, l) = summ;
                extrinsic_matrix(p_input_table(u+1,l)+1, p_step_table(u+1,l)+1) = summ;
            end
            index_f = index_f + 1;
            index_b = index_b + 1;
            % index_b = mod(index_b + 1, N);        
        end
        E2 = extrinsic_matrix;  
        E2 = bsxfun(@minus, E2, max(E2));   % Normalization
    end
    
    % Maximum a posteriori estimate
    [ ~ , u_hat_num ] = max(E2+q+E1);
    u_hat = zeros(length(u_hat_num) * crsc_k, 1);
    num2input = @(i) mod(fix(i./(2.^(crsc_k-1:-1:0)).'),2);
    for i = 0 : length(u_hat_num)-1         % From u_hat_num to u_hat
       u_hat(crsc_k*i+1:crsc_k*i+crsc_k) = num2input(u_hat_num(i+1)-1);
    end
    
end

