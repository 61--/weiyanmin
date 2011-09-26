function B = pixeldup(A,m,n)
%PIXELDUP Duplicates pixels of an image in both directions.
%   B = pixeldup(A,m,n) duplicates each pixel of A m times in
%   the vertical direction and n times in the horizontal direction.
%   Parameters m and n must be integers.  If n is not included, it
%   defaults to m.

%	Copyright 2002-2004: R.C. Gonzalez, R.E. Woods, & S.L. Eddins

% Check inputs
if nargin < 2
    error('At least two inputs are required')
end
if nargin == 2
    n = m;
end

% Generate a vector with elements 1:size(A,1).
u = 1:size(A,1);
% Duplicate each element of the vector m times.
m = round(m); % Protect against nonintergers.
u = u(ones(1,m),:);
u = u(:);

% Now repeat for the other direction.
v = 1:size(A,2);
n = round(n);
v = v(ones(1,n),:);
v = v(:);
B = A(u,v);

% End of function PIXELDUP


    


