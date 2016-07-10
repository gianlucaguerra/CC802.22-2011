function [ c ] = CTC_enc_p( u, crsc_state_update_table,...
                                 crsc_output_table, N, P )
% CTC_ENCODER Basic DUO Binary Convolutional Turbo Code (CTC) encoder 
% of rate 1/2

    % CRSC specs load
    crsc_k = size(CRSC.P,2);
    crsc_n = size(CRSC.P,1);
    crsc_v = length(CRSC.G);
    crsc_circulation_state_table = CRSC.circulation_state_table;
    
    % Auxiliary function
    input2num = @(i) sum(i.*2.^(crsc_k-1:-1:0).');
    num2output = @(o) mod(fix(o./(2.^(crsc_n-1:-1:0)).'),2);

    % Codeword initialization
    c = zeros(N,crsc_n+(crsc_n-crsc_k));
    
    % Inputs to the encoder components
    u1 = u;     % Not interleaved
    u2 = P*u;   % Interleaved
    
    % Inputs Parse
    i1 = zeros(length(u1)/crsc_k, 1);
    i2 = zeros(length(u2)/crsc_k, 1);
    for l = 0 : length(i1)-1
        i1(l+1) = input2num(u1(crsc_k*l+1:crsc_k*l+crsc_k));
        i2(l+1) = input2num(u2(crsc_k*l+1:crsc_k*l+crsc_k));
    end
    
    % Pre-encoding
    s1 = 0;
    s2 = 0;
    for l = 0 : N-1
        s1 = crsc_state_update_table(s1+1, i1(l+1)+1);
        s2 = crsc_state_update_table(s2+1, i2(l+1)+1);
    end
    
    % Circulation state determination
    s1 = crsc_circulation_state_table(mod(N, 2^crsc_v-1), s1+1);
    s2 = crsc_circulation_state_table(mod(N, 2^crsc_v-1), s2+1);

    % Encoding
    for l = 0 : N-1
        o = crsc_output_table(s1+1, i1(l+1)+1);         %  |
        out1 = num2output(o);                      %  |  1st code component
        s1 = crsc_state_update_table(s1+1,i1(l+1)+1);   %  |
        
        o = crsc_output_table(s2+1, i2(l+1)+1);         %  |
        out2 = num2output(o);                      %  |  2nd code component
        s2 = crsc_state_update_table(s2+1,i2(l+1)+1);   %  |
                        
        c(l+1,:) = [out1; out2(crsc_k+1:end)];
        
    end
    
    c = reshape(c.',1,[]);

end

