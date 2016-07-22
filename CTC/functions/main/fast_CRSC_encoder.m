function [ c ] = fast_CRSC_encoder( u, state_update_table, output_table, N)
% FAST_CRSC_ENCODER CRSC encoder for the CTC component code that exploits 
% look-up tables
      
    % Code specs
    k = size(CRSC.P,2);
    n = size(CRSC.P,1);
    v = length(CRSC.G);

    % Circulation state table load
    circulation_state_table = CRSC.circulation_state_table;
    
    % Auxiliary function
    input2num = @(i) sum(i.*2.^(k-1:-1:0).');
    num2output = @(o) mod(fix(o./(2.^(n-1:-1:0)).'),2);

    % Codeword initialization
    c = zeros(N,n);
    
    % Input Parse
    i = zeros(length(u)/k,1);
    for l = 0 : length(i)-1
        i(l+1) = input2num(u(k*l+1:k*l+k));
    end
    
    % Pre-encoding
    s = 0;
    for l = 0 : N-1
        s = state_update_table(s+1, i(l+1)+1);    
    end
    
    % Circulation state determination
    s = circulation_state_table(mod(N, 2^v-1), s+1);
    
    % Encoding
    for l = 0 : N-1
        o = output_table(s+1, i(l+1)+1);
        out = num2output(o);
        c(l+1,:) = out;
        s = state_update_table(s+1,i(l+1)+1);
    end
    
    

end

