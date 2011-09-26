function [H] = lpfilter(type,M,N,D0,n)
%LPFILTER Computes freq. domain lowpass filters
%		THIS IS NOT A STANDARD MATLAB FUNCTION
%		H = lpfilter (type,M,N,D0,n) creates the
%		transfer function of a lowpass filter, H, of
%		the specified type and size MxN. Acceptable 
%		values for type, D0, and n are:
%
%				'ideal'				Ideal lowpass filter with
%									cutoff frequency D0. If
%									supplied, n is ignored.
%				'btw'				Butterworth lowpass filter
%									of order n, and cutoff D0.
%				'gauss'			    Gaussian lowpass filter with
%									cutoff (standard deviation)D0.
%									If supplied, n is ignored.
%		M and N should be even numbers for DFT
%		filtering.
%
%		Class support: double, uint8, uint16
%		The output is of class double

%		Verify the number of inputs

error(nargchk(4,5,nargin));

%		Issue warning if M or N not even

L1 = M/2;
L2 = N/2;
if((L1-round(L1)) | (L2-round(L2)))
		disp('Warning: M & N must be even for DFT filtering')
end

%		Set up meshgrid to compute filter functions
%		running from 0 to M-1 and 0 to N-1. But,
%		recall that U and V run from 1 to M and 1 to N,
%		repectively.  See Section 2.10.4 for an 
%		explanation of meshgrid. Recall also that
%		meshgrid reverses the order of rows and 
%		columns, so the final result must be transposed
%		in order to preserve the original order of 
%		of the coordinates.


[U,V] = meshgrid(0:M-1,0:N-1);

%   Compute the filter center

U0=L1;
V0=L2;

%		Compute distances D(U,V)

D=((U-U0).^2 + (V-V0).^2).^0.5;

%		Begin filter computations

switch type
	case 'ideal'
		H = D<=D0;
        H = H';
	case 'btw'
		H = 1./(1 + (D./D0).^(2*n));
        H = H';
	case 'gauss'
		H = exp(-(D.^2)./(2*(D0^2)));
        H = H';
	otherwise
		error('Unknown filter type')
end

%		End of function
