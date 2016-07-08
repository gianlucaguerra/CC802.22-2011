function [ u_hat ] = CRSC_decoder(r, state_update_table, output_table, ...
                            neighbours_table, modulation_table, sigma_w)
% CRSC_DECODER Component decoder for the CTC
% Rate 2/3, parameter of the code in /specs&param/specs_802_22/CRSC.m

    % Code params and other stuffs
    k = size(CRSC.P,2);
    n = size(CRSC.P,1);
    v = length(CRSC.G);
    base_rate = k/n;
    
    blk_size = numel(r)*base_rate;
    N = blk_size/2;
%   piece_const = log(1+exp(-(0:5)));% TO IMPLEMENT AND SEE THE DIFFERENCE!

    % BCJR ALGORITHM

    % Initialization
    q = log(ones(2^k, N)./(2^k));     % Row: input  | Column: step l
    
    g = zeros(2^n, N);      % Row: output | Column: step l in blocks 
    for l = 0 : N - 1
        for y = 0 : 2^n - 1
            g(y+1, l+1) = ...
                    sum(abs(r(l+1,:) - modulation_table(y+1,:)).^2); 
        end
    end
    g = -1/(2*sigma_w^2).*g;
    
    backward_matrix = -Inf(2^v, N);   % Row: state  | Column: step l
    forward_matrix = -Inf(2^v, N);    % Row: state  | Column: step l
    extrinsic_matrix = -Inf(2^k, N);  % Row: input  | Column: step l
    
    % Backward messages update
    backward_matrix(1,end) = 0; % Starting with B_(N-1)(s_0) = 0 
    for l = 2*N-1 : -1 : 1      % The first time we compute B_(N-2)
        index = mod(l,N);
        for s = 0 : 2^v - 1  % s_l
            summ = 0;       % Sum over u 
            for u = 0 : 2^k - 1 
                ql_u = q(u+1, index+1);
                y = output_table(s+1, u+1);
                gl_y = g(y+1, index+1);
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
    
    % Forward messages update
    forward_matrix(1,1) = 0; % Starting with F_0 (s_0) = 0
    for l = 2:2*N            % The first time we compute F_1
        index = mod(l-1, N);
        if index == 0
            index2 = N;
        else 
            index2 = index;
        end
        for s = 0 : 2^v - 1  % s_(l+1)
            summ = 0;        % Sum over the neighbours of s
            for u_p = 0 : 2^k - 1
                ql_u = q(u_p+1, index2);
                s_p = neighbours_table(s+1, u_p+1);  % s_l
                y = output_table(s_p+1, u_p+1);
                gl_y = g(y+1, index2);
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
    
    % Extrinsic message update
    index_b = 1;
    index_f = 1;
    for l = 1 : N                             % This is a matlab index!
        for u = 0 : 2^k -1
            summ = 0;
            for s = 0 : 2^v -1
                s_n = state_update_table(s+1, u+1);
                y = output_table(s+1, u+1);
                gl_y = g(y+1, l);
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
      
  % Maximum a posteriori estimate
  [ ~ , u_hat_num ] = max(extrinsic_matrix+q);
  u_hat = zeros(length(u_hat_num) * k, 1);
  num2input = @(i) mod(fix(i./(2.^(k-1:-1:0)).'),2);
  for i = 0 : length(u_hat_num)-1         % From u_hat_num to u_hat
    u_hat(k*i+1:k*i+k) = num2input(u_hat_num(i+1)-1);
  end
end

