function [H] = hpfilter(type,M,N,D0,n)
%HPFILTER Computes freq. domain highpass filters
%		THIS IS NOT A STANDARD MATLAB FUNCTION
%		H = hpfilter (type,M,N,D0,n) creates the
%		transfer function of a highpass filter, H, of
%		the specified type and size MxN. Possible 
%		values for type, D0, and n are:
%
%				'ideal'				Ideal highpass filter with
%									cutoff frequency D0. If
%									supplied, n is ignored.
%				'btw'				Butterworth highpass filter
%									of order n, and cutoff D0.
%				'gaussn'			Gaussian highpass filter with
%									cutoff (standard deviation)D0.
%									If supplied, n is ignored.
%		M and N should be even numbers for DFT
%		filtering.
%
%		Class support: double, uint8, uint16
%		The output is of class double

%       The transfer function Hhp of a highpass filter
%       is 1 - Hlp, where Hlp is the transfer function of
%       the corresponding lowpass filter.  Thus, we can 
%       use function lpfilter to generate highpass filters

%       If filter is btw, make sure that n is provided
%       Otherwise, pass n=1 as an arbitrary value to
%       prevent error message

if strmatch(type,'btw')
    if nargin < 5
        error('Must specify order for btw filter')
    end
else
    n=1;
end

Hlp = lpfilter(type,M,N,D0,n);
H = 1 - Hlp;

%       End of function