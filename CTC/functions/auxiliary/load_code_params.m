function [ code_params ] = load_code_params()
% LOAD_INTERLEAVER_PARAMS Function to load the ctc interleaver parameters
% The function check the existence of ctc interleaver parameters in the
% data folder and load it. If they don't exist the function create them.

if exist('data/code_params.mat','file')
    load('code_params.mat');
else
    code_data = importdata('config/code_params.conf',' ', 19);
    code_params = code_data.data;
    save('data/code_params.mat','code_params');
end

end

