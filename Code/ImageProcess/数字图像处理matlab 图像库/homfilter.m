function H = homfilter(M, N, gL, gH, c, D0, p)
%H = HOMFILTER(M, N, gL, gH, c, D0, p) Generates a homomorphic filter.
%   Implements the following equation, from Gonzalez and Woods, 3rd ed.
%
%   H(u,v) = (gH - gL)(1 - exp(-c(D^2(u,v)/D0^2)) + gL
%
%   where D(u,v) is the distance from the center of the M-by-N frequency
%   rectangle. If p =1  the program generates a cross section of the
%   filter, extending from the center of the freq.rectangle to point 
%   (M/2, N). If p = 0, or it is not included, a plot is not generated.
%   It is assumed that gH > gL.
%
%   The filter function, H, is not centered. To view it, or use it in a 
%   program that requires a centered filter, use function fftshift.


% Set up the meshgrid arrays needed for computing the required distances.

% Set up range of variables.
u = 0:(M - 1);
v = 0:(N - 1);

% Compute the indices for use in meshgrid.
idx = find(u > M/2);
u(idx) = u(idx) - M;
idy = find(v > N/2);
v(idy) = v(idy) - N;

% Compute the meshgrid arrays.
[V, U] = meshgrid(v, u);

% Compute the distances D^2(U, V).
D2 = U.^2 + V.^2;

% Generate the filter.
H = (gH - gL)*(1 - exp(-c*(D2./D0^2))) + gL;

% Check for plot.
if nargin == 7 & p == 1
   Hc = fftshift(H);
   p = Hc(floor(M/2),floor(N/2):N);
   figure, plot(p)
end