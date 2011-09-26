function [g, A] = minus1(f)
%MINUSONE Multiplies the input array by (-1)^(x+y)
%  [G, A] = MINUS1(F) multiplies the input array, F, by b(-1)^x+y.
%  A is the matrix of alternating 1s and -1s.
%  The input can be of class uint8, uint16 or double, real, or
%  imaginary. The output is of class double, and is real if the input 
%  was real; otherwise it too is imaginary. 

[M,N] = size(f);
f = double(f);

% Create first and second rows.
x = 1:N+1;
pair = [(-1).^(x - 1); (-1).^(x)];

% Duplicate the pair to form M x N matrix.
K = ceil((M/2) + 1);
A = repmat(pair,K,1);

% Trim to size.
A = A(1:M,1:N);

% Array multiply f by A.
g = A.*f;
