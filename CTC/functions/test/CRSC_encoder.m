function [ c ] = CRSC_encoder(u, N)
% CRSC_ENCODER Component encoder for the CTC
% Rate 2/3, parameter of the code in /specs&param/specs_802_22/CRSC.m

    % Load the code specs
    G = CRSC.G;
    H = CRSC.H;
    M = CRSC.M;
    P = CRSC.P;
    circulation_state_table = CRSC.circulation_state_table;
    
    k = size(P,2);
    n = size(P,1);

    % State update and output function definition
    state_update = @(s,u) xor(mod(G*s,2) , mod(H*u,2));
    output = @(s,u) xor(mod(M*s,2) , mod(P*u,2));

    % Codeword initialization
    c = zeros(N-1, n);
    
    % PreEncoding (without redundancy bits)
    s = zeros(length(G),1); % Initial state zero initialized!
    for i = 0 : N-1
        s = state_update(s,u(k*i+1:k*i+k));    
    end
    
    % Circulation state determination
    s_c = circulation_state_table(mod(N, (2^length(G))-1),...
                                  sum(s.*2.^(length(G)-1:-1:0).')+1);
    s_c = mod(fix(s_c./(2.^(length(G)-1:-1:0)).'),2); % Circulant state
    
    % Encoding
    s = s_c;
    for i = 0 : N-1
        u_i = u(k*i+1:k*i+k);
        y = output(s,u_i);
        c(i+1,:) = y;
        s = state_update(s,u_i);
    end   
end

