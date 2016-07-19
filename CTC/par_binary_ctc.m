parpool('local',2);
clc;
clear;
addpath(genpath('.'));
spmd
    switch labindex 
        case 1
            simulation_binary_CTC1;
        case 2
            simulation_binary_CTC2;
%         case 3
%             simulation_binary_CTC3;
%         case 4
%             simulation_binary_CTC4;
    end
end
delete(gcp('nocreate'))