function rappid_analyzegencode(buildInfo)
% Get the names and paths of all source and include files
% generated for the model and then analyze them.

% buildInfo - build information for my model.

% Define cell array to hold data.

%
% Copyright 2006 
% Freescale Semiconductor Inc
% All Rights Reserved 
%
% $Log: rappid_analyzegencode.m,v $
% Revision 1.1  2010/10/28 22:03:38  r61406
% Issue:10000
% Create Code Base for RAppID Toolbox Lite
%
% Revision 1.2  2006/07/20 15:40:18  r61406
% PWM:Update Copyright notice and Log Tag.
%
%

try
MyBuildInfo={};

% Get source file information.
MyBuildInfo.srcfiles=getSourceFiles(buildInfo, true, true);
MyBuildInfo.srcpaths=getSourcePaths(buildInfo, true);

% Get include (header) file information.
MyBuildInfo.incfiles=getIncludeFiles(buildInfo, true, true);
MyBuildInfo.incpaths=getIncludePaths(buildInfo, true);

% Analyze generated code here

catch
disp('failure in rappid_analyzegencode');
end

return
