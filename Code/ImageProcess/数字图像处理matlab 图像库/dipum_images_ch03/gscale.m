function g = gscale(f, varargin)
%GSCALE scales the intensity of the input image.
%   G = GSCALE(f, method, low, high) Scales the intensity  values of 
%   input image f to the full range of class uint or uint16, or 
%   to the range specified in minmax and outputs the result in g.
%
%   g = gscale(f, 'uint8') Scales the intensities of f to the FULL 
%       8-bit intensity range [0, 255].  This is the default if 
%       'uint8' is not included in the argument.
%
%   g = gscale(f, 'full16') Scales the intensities of f to the FULL 
%       16-bit intensity range [0, 65535].
%
%   g = gscale(f, 'minmax', low, high) Scales the intensities of f to 
%       the range [low, high]. These values must be provided, and they 
%       must be in the range [0, 1], independently of the class of the 
%       input. The program performs any necessary scaling. If the input 
%       is of class double, and its values are not in the range [0, 1], 
%       the program scales it to this range before proceesing.  The class 
%       of the output is equal to the class of the input.
%
%   Class support: The input can be of class double, uint8 or uint16.

%   Copyright 2002-2004: R.C. Gonzalez, R.E. Woods, & S.L. Eddins

if length(varargin) == 0 % If only one arg, it must be f.
	method = 'full8';
else method = varargin{1}
end

if strcmp(class(f),'double') & (max(f(:)) > 1 | min(f(:)) < 0)
    f = mat2gray(f);
end

% Perform the specified scaling.
switch method
    case 'full8'
		g = im2uint8(mat2gray(double(f)));
	case 'full16'
		g = im2uint16(mat2gray(double(f)));
	case 'minmax'
        low = varargin{2}; high = varargin{3};
        if low > 1 | low < 0 | high > 1 | high < 0
            error('Parameters low and high must be in the range [0,1]')
        end
        if strcmp(class(f),'double')
            low_in = min(f(:));
            high_in = max(f(:));
        elseif strcmp(class(f),'uint8')
            low_in = double(min(f(:)))./255;
            high_in = double(max(f(:)))./255;
        elseif strcmp(class(f),'uint16')
            low_in = double(min(f(:)))./65535;
            high_in = double(max(f(:)))./65535;    
        end
        % imadjust automatically matches the class of the input.
        g = imadjust(f, [low_in high_in], [low high]);   
	otherwise
		error('Unknown method')
end

%   End of function GSCALE.

