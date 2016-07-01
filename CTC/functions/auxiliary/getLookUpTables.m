function [ output_table, state_update_table, neighbours_table ] = ...
                                              getLookUpTables()
% GETLOOKUPTABLES Function to generate the look-up tables of the CRSC code
% component

    % Load the code specs
    G = CRSC.G;
    H = CRSC.H;
    M = CRSC.M;
    P = CRSC.P;
    
    % Rate and others
    k = size(P,2);
    n = size(P,1);
    v = length(G);        % Memory of the encoder
    
    % State update and output function definition
    state_update = @(s,u) xor(mod(G*s,2) , mod(H*u,2));
    output = @(s,u) xor(mod(M*s,2) , mod(P*u,2));
    
    % Auxiliary functions
    state2num = @(s) sum(s.*2.^(v-1:-1:0).');
    num2state = @(s) mod(fix(s./(2.^(v-1:-1:0)).'),2);
    num2input = @(i) mod(fix(i./(2.^(k-1:-1:0)).'),2);
    output2num = @(o) sum(o.*2.^(n-1:-1:0).');
    
    % Output and state update look-up table generation
    output_table = zeros(2^v,2^k);
    state_update_table = zeros(2^v,2^k);
    
    for s = 0 : 2^v-1
        state = num2state(s);
        for i = 0 : 2^k-1            
            input = num2input(i);
            out = output(state,input);
            next_state = state_update(state,input);
            o = output2num(out);
            next_s = state2num(next_state);
            output_table(s+1,i+1) = o;
            state_update_table(s+1,i+1) = next_s;
        end
    end
   
    % Neighbours look-up table generation (generated from state_update table)
    neighbours_table = zeros(2^v,2^k);
    
    for s = 0 : 2^v-1
        for i = 0 : 2^k-1
            next_s = state_update_table(s+1,i+1);
            neighbours_table(next_s+1,i+1) = s;
        end
    end
    
    

end

