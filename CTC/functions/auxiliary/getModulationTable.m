function [ modulation_table ] = getModulationTable(n, L, M)
% GETMODULATIONTABLE This function gives as output the modulation for each 
% possible output of the decoder

    num2output = @(x) mod(fix(x./(2.^(n-1:-1:0)).'),2);

    modulation_table = zeros(2^n, n/log2(M));
    for i = 0 : 2^n-1
        output = num2output(i);
        for m = 0 : n/log2(M)-1
            symbols = L(output(m*log2(M)+1:m*log2(M)+log2(M)));
            modulation_table(i+1, m*log2(M)+1:m*log2(M)+log2(M)) = symbols;
        end
    end
end

