function [ u_hat ] = BICM_decoder( r, M, sigma_w, constellation_table, ...
    codeword_length, N, conform_table, bit_p_table, puncturing_pattern,...
    output_table, state_update_table, neighbours_table, ...
    p_input_table, p_step_table, n_it)
%BICM_DECODER BICM DECODER THAT EXPLOITS MESSAGE PASSING

    % CRSC code component params
    %crsc_k = size(CRSC.P,2);
    %crsc_n = size(CRSC.P,1);
    %crsc_v = length(CRSC.G);
    crsc_k = 2;
    crsc_n = 3;
    crsc_v = 3;

    r_length = codeword_length/log2(M); % Length of the received sequence
    
    % MESSAGE PASSING DECODING ALGORITHM

    % 1. INITIALIZATION
    
    % 1.1 The q vector is initialized to the a priori probability,
    q = log(ones(2^crsc_k, N)./(2^crsc_k)); % Row: input  | Column: step l
    q = bsxfun(@minus, q, max(q)); % Normalization
    
    % 1.2 The g vector is initialized using the received symbol sequence
    g = zeros(M, r_length);      % Row: output | Column: step l in blocks
    for l = 0 : r_length -1
        for s = 0 : M - 1         % In this case s is a constellation signal
            g(s+1, l+1) = - abs(r(l+1)-constellation_table(s+1))^2/(2*sigma_w^2);
        end 
    end
    g = bsxfun(@minus, g, max(g)); % Normalization
    
    % 1.3 Output message from the conform node to the BICM interleaver and
    % viceversa
    mu_w2d = zeros(2, codeword_length);
    mu_d2w = log(ones(2, codeword_length)./2); % The d_i are equiprobable
    mu_d2w = bsxfun(@minus, mu_d2w, max(mu_d2w)); % Normalization
    
    
    % 2 COMFORM NODE EVALUATION
    
    for l = 0 : r_length - 1         % For across the conform nodes
        possible_input_msg = mu_d2w(:,log2(M)*l+1:log2(M)*(l+1)); % Gathering the possible input message
        for m = 0 : log2(M) - 1      % For across the d_m of a conform node
            col_index = ones(log2(M), 1);
            col_index(m+1) = 0;
            input_msg = possible_input_msg(:,col_index==1);             
            for d = 0 : 1            % For across each possible value of d_m (0 and 1)
                summ = -Inf;
                for i = 0 : M/2 - 1  % For across all possible permutation but d_m                   
                    add = g(conform_table(2*m+d+1, i+1)+1,l+1);
                    for j = (log2(M) - 2): -1 :0     % i from dec2bin
                        index_input_msg = mod(fix(i/2^j), 2)+1;
                        add = add + input_msg(index_input_msg, log2(M) - 1 - j ); %!!
                    end
                    summ = log(exp(summ)+exp(add));
                end
                mu_w2d(d+1, bit_p_table(l*log2(M)+m+1)+1) = summ;
            end            
        end
    end
    mu_w2d = bsxfun(@minus, mu_w2d, max(mu_w2d)); % Normalization
    
    % 3 SISTEMATIC PART, CODE1 OUTPUT, CODE2 OUTPUT and DEPUNCTURING
    systematic_out1 = zeros(2, crsc_n*N);
    out2 = zeros(2, (crsc_n-crsc_k)*N);
    
    index_p = 0;
    index_s = 0;
    index_2 = 0;
    index_m = 0;
    while (index_p <= length(puncturing_pattern)-4)
        systematic_out1(:, index_s+1) = mu_w2d(:,index_m+1);
        systematic_out1(:, index_s+2) = mu_w2d(:,index_m+2);
        if (puncturing_pattern(index_p + 3) == 0)
            systematic_out1(:,index_s + 3) = 0;
            out2(:, index_2 + 1) = 0;
            index_m = index_m + 2;
        else
            systematic_out1(:, index_s + 3) = mu_w2d(:, index_m + 3);
            out2(:, index_2 + 1) = mu_w2d(:, index_m + 4);
            index_m = index_m + 4;
        end
        index_p = index_p + 4;
        index_s = index_s + 3;
        index_2 = index_2 + 1;
    end
    
    % 4 ALPHA NODES EVALUATION
    mu_alpha2y = zeros(2^crsc_n, N);
    for n = 0 : N - 1
        for y = 0 : 2^crsc_n - 1
            for j = crsc_n-1: -1 :0  % from dec2bin
                index = mod(fix(y/2^j), 2)+1;
                mu_alpha2y(y+1, n+1) = mu_alpha2y(y+1, n+1) + systematic_out1(index, crsc_n*n+crsc_n-j);
            end 
        end
    end
    
    
    % 5 BCJR ALGORITHM ON THE UPPER CODE    
    % 5.0 BCJR initialization 
    E2 = zeros(2^crsc_k, N);
    E1 = zeros(2^crsc_k, N);
    
 for cont = 1 : n_it
     
    backward_matrix = -Inf(2^crsc_v, N);   % Row: state  | Column: step l
    forward_matrix = -Inf(2^crsc_v, N);    % Row: state  | Column: step l
    extrinsic_matrix = -Inf(2^crsc_k, N);  % Row: input  | Column: step l
    
    mu_eq = E2 + q;
    mu_eq = bsxfun(@minus, mu_eq, max(mu_eq));  % Normalization
    
    % 5.1 Backward messages update
        backward_matrix(1,end) = 0; % Starting with B_(N-1)(s_0) = 0 
        for l = 2*N-1 : -1 : 1      % This is a matlab matrix index
            index = mod(l,N);
            for s = 0 : 2^crsc_v - 1  % s_l
                summ = -Inf;       % Sum over u 
                for u = 0 : 2^crsc_k - 1 
                    ql_u = mu_eq(u+1, index+1);
                    y = output_table(s+1, u+1);
                    gl_y = mu_alpha2y(y+1, index+1);
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
    
   % 5.2 Forward messages update
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
                gl_y = mu_alpha2y(y+1, index2);
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
   
   % 5.3 Extrinsic message update
   index_b = 1;
   index_f = 1;
   for l = 1 : N                             % This is a matlab index!
       for u = 0 : 2^crsc_k -1
           summ = -Inf;
           for s = 0 : 2^crsc_v -1
               s_n = state_update_table(s+1, u+1);
               y = output_table(s+1, u+1);
               gl_y = mu_alpha2y(y+1, l);
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
    
  % 5.4 Message from the equality factor update
  mu_eq = E1 + q;
  mu_eq = bsxfun(@minus, mu_eq, max(mu_eq));  % Normalization  
  
  
  % 6 BCJR ALGORITHM ON THE LOWER CODE
        
        % 6.0 BCJR matrices initialization 
        backward_matrix = -Inf(2^crsc_v, N);   % Row: state  | Column: step l
        forward_matrix = -Inf(2^crsc_v, N);    % Row: state  | Column: step l
        extrinsic_matrix = -Inf(2^crsc_k, N);  % Row: input  | Column: step l
    
        % 6.1 Backward message update
        backward_matrix(1,end) = 0; % Starting with B_(N-1)(s_0) = 0 
        for l = 2*N-1 : -1 : 1      % This is a matlab matrix index
            index = mod(l,N);
            for s = 0 : 2^crsc_v - 1  % s_l
                summ = -Inf;       % Sum over u 
                for u = 0 : 2^crsc_k - 1 
                    ql_u = mu_eq(p_input_table(u+1, index+1)+1, p_step_table(u+1,index+1)+1);
                    y = mod(output_table(s+1, u+1),2);   %!!
                    gl_y = out2(y+1, index+1);
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
    
        % 6.2 Forward messages update
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
                    y = mod(output_table(s_p+1, u_p+1),2); %!!
                    gl_y = out2(y+1, index2);
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
    
        % 6.3 Extrinsic message update
        index_b = 1;
        index_f = 1;
        for l = 1 : N                             % This is a matlab index!
            for u = 0 : 2^crsc_k -1
                summ = -Inf;
                for s = 0 : 2^crsc_v -1
                    s_n = state_update_table(s+1, u+1);
                    y = mod(output_table(s+1, u+1),2);  %!!
                    gl_y = out2(y+1, l);
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
    %num2input = @(i) mod(fix(i./(2.^(crsc_k-1:-1:0)).'),2);
    for i = 0 : length(u_hat_num)-1         % From u_hat_num to u_hat
      % u_hat(crsc_k*i+1:crsc_k*i+crsc_k) = num2input(u_hat_num(i+1)-1);
      u_hat_num_i = u_hat_num(i+1)-1; 
      u_hat(crsc_k*i+2) = mod(u_hat_num_i,2);
      u_hat(crsc_k*i+1) = mod(fix(u_hat_num_i/2),2);
    end
    
    
    
    
    
    
    
    
    
  

end

