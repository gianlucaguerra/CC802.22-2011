classdef CRSC
    % CIRCULAR RECURSIVE SYSTEMATIC CONVOLUTIONAL CODE SPECS (COMPONENT CODE)
    
    properties (Constant = true)
    
        % MATRICES DEFINITION     
        
        G = [1 0 1; 
             1 0 0;
             0 1 0];
        
        H = [1 1;
             0 1;
             0 1];
         
        M = [0 0 0;
             0 0 0;
             1 1 0]; %%%
         
        P = [1 0;
             0 1;
             1 1];
        
        % CIRCULATION STATE MATRIX
        circulation_state_table = [0 6 4 2 7 1 3 5;
                                   0 3 7 4 5 6 2 1;
                                   0 5 3 6 2 7 1 4;
                                   0 4 1 5 6 2 7 3;
                                   0 2 5 7 1 3 4 6;
                                   0 7 6 1 3 4 5 2];
                  
    end
     
end

