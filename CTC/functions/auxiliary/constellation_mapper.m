function [ s ] = constellation_mapper(d, M)
% CONSTELLATION_MAPPER Map the conform symbols in the complex constellation

    binvect2num = @(x) sum(x.*2.^(log2(M)-1:-1:0));
    switch M
        case 2
            constellation_table = Data_modulation.PAM2;
        case 4 
            constellation_table = Data_modulation.QPSK;
        case 16 
            constellation_table = Data_modulation.QAM16;
        case 64
            constellation_table = Data_modulation.QAM64;
    end
    
    s = zeros(size(d,1) ,1);
    for i = 1 : size(d,1)
        s(i) = constellation_table(binvect2num(d(i,:))+1);
    end

end

