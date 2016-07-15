function [ u_hat ] = BICM_decoder( r, M, sigma_w, constellation_table, ...
    codeword_length, N, conform_table, bit_p_table, puncturing_pattern )
%BICM_DECODER BICM DECODER THAT EXPLOITS MESSAGE PASSING

    % CRSC code component params
    crsc_k = size(CRSC.P,2);
    crsc_n = size(CRSC.P,1);
    crsc_v = length(CRSC.G);

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
    
    u_hat = 0;

end

