function [ G, H, m, n ] = load_CRSC_params()
% LOAD_INTERLEAVER_PARAMS Function to load the CRSC code parameters
% The function check the existence of CRSC code parameter in the
% data folder and load it. If they don't exist the function create them.

if exist('data/CRSC_params.mat','file')
    load('data/CRSC_params.mat');
else
    CRSC_data = importdata('config/CRSC_params/G.conf',' ', 9);
    G = CRSC_data.data;
    CRSC_data = importdata('config/CRSC_params/H.conf',' ', 9);
    H = CRSC_data.data;
    CRSC_data = importdata('config/CRSC_params/m.conf',' ', 9);
    m = CRSC_data.data;
    CRSC_data = importdata('config/CRSC_params/n.conf',' ', 9);
    n = CRSC_data.data;
    save('data/CRSC_params.mat','G', 'H', 'm', 'n');
end

end

