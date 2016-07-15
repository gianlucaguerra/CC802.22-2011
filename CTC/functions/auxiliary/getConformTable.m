function [ conform_table ] = getConformTable(M, conform)
% GETCONFORMTABLE 

    conform_table = zeros(2*log2(M), M/2);
    
    for i = 0 : log2(M) - 1        
        conform_table(2*i+1,:) = find(conform(:,i+1)==0)-1;
        conform_table(2*(i+1),:) = find(conform(:,i+1)==1)-1;       
    end

end

