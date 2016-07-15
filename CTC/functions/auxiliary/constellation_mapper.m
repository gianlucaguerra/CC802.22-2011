function [ s ] = constellation_mapper(d, M, constellation_table)
% CONSTELLATION_MAPPER Map the conform symbols in the complex constellation

    binvect2num = @(x) sum(x.*2.^(log2(M)-1:-1:0));
    
    s = zeros(size(d,1) ,1);
    for i = 1 : size(d,1)
        s(i) = constellation_table(binvect2num(d(i,:))+1);
    end

end

