% SIMULATION TEST 

clc; clear;
addpath(genpath('.'));

disp('CTC/CRSC SIMULATION TEST');
disp(' ');

%% LOAD OF VARIABLES

% CTC parameters
disp('Loading CTC main table...');
code_params = CTC.code_params();
disp(' ');

%% CTC/CRSC SIMULATION TEST

disp('CODE:');
row = 41;
blk_size = code_params(row,1)*8;
disp(['Block length: ', num2str(blk_size),' bit.']);
codeword_length = code_params(row,2)*8;
disp(['Codeword length: ', num2str(codeword_length),' bit.']);
R = blk_size/codeword_length;
disp(['Rate: ', num2str(R),'.']);
disp(' ');

% Information message
u = randi([0, 1], blk_size, 1);

% Encoding (epsilon)
N = code_params(row, 10);              % Number of vector input of length k
int_params = code_params(row, 11:end); % Interleaver parameters
P = getPermutationMatrix(blk_size, N, int_params); % Interleaver permutations
[output_table, state_update_table, neighbours_table] = getLookUpTables();
c = CTC_encoder(u, state_update_table, output_table, N, P);


% Modulation
M = 2;
d = c;    % Conform map (Omega)
L = @(x) 2.*x-(M-1);       % Constellation map (L)
s = L(d);

modulation_table = getModulationTable(size(CRSC.P,1), L, M); 
[p_input_table, p_step_table] = getPermutationTables(N, int_params); 

n_it = [1, 4, 8, 12];
Es = 1;
%Eb_N0_dB = (0:0.5:5);
Eb_N0_dB = (0:0.5:2.5);
Eb_N0 = 10.^(Eb_N0_dB./10);
sigma_w = sqrt(Es./(2.*R.*log2(M).*Eb_N0)); 

P_bit = zeros(length(n_it), length(Eb_N0));
tot_blk = 5788; 

parfor snr_index = 1 : length(Eb_N0)
    disp(num2str(Eb_N0_dB(snr_index)));
    error_num = zeros(1,length(n_it));
    
    for blk_index = 1 : tot_blk
        
        % Channel 
        w = randn(size(s,1),size(s,2)).*sigma_w(snr_index);  % Noise generation
        r = s + w;

        % MAP decoding
           
        for it_index = 1 : length(n_it)
            u_hat = CTC_decoder(r, state_update_table, output_table,...
                  neighbours_table, modulation_table, sigma_w(snr_index),...
                  P, N, n_it(it_index), p_input_table, p_step_table);

            error_num(it_index) = error_num(it_index) + sum(u ~= u_hat);
        end
        
    end
    
    P_bit(:, snr_index) = (error_num./(tot_blk*blk_size)).';
        
end
