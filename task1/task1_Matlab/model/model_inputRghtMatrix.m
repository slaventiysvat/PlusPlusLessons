
function size = model_inputRghtMatrix(M,N)
% the input matrix must be a sixe MxN where
%M and N always bigger than 2
    if N < 2 
        error(['Please enter size of matrix bigger than N = ' num2str(N)]);
        elseif M < 2
        error(['Please enter size of matrix bigger than M = ' num2str(M)]);
             else
            size=[M N];
    end

end