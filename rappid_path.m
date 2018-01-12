%RAPPID_PATH Setup RAppID paths.
%   RAPPID_PATH changes the MATLAB path to remove old RAppID installation
%   paths and use the newest RAppID installation.  By default, the RAppID
%   paths are prepended to your current path.
%
%   RAPPID_PATH('append') appends the new paths, instead of the default prepending.
%   RAPPID_PATH('remove') removes old RAppID installation paths only.
%

%
%   Copyright 2006 
%   Freescale Semiconductor Inc 
%   All Rights Reserved
%
%   $Log: rappid_path.m,v $
%   Revision 1.10  2008/10/10 19:10:58  r61406
%   Issue:000
%   Update to add src and includes directoyr to path for R2008A/B MATLAB
%
%   Revision 1.9  2006/07/20 14:50:30  r61406
%   PWM:Update with copyright and log info tag.
%
%
%
function rappid_path(varargin)

%%%%%%%%%%%%%%%%%%%%%%%%%%%
% remove old rappid paths %
%%%%%%%%%%%%%%%%%%%%%%%%%%%

rem=path;
newpth=[];

while ~isempty(rem)
    [pth,rem]=strtok(rem,';');
    if isempty(regexp(pth,'rappid564xl','once'))
        newpth=[newpth pathsep pth];
    end
end

if nargin==1 && strcmpi(varargin{1},'remove')
    path(newpth);
    savepath;
    rehash toolboxcache;
    disp(['Successful.']);
    return;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% add (certain) new rappid paths %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

expandPaths = {
	'src',
};

paths = {
	'rappid564xl',
	'rappid564xl/mscripts',
	'MCLIB for MPC564xL/bam',
	'Examples',
    ''
};

mustFind = [expandPaths; paths];

root = fileparts(which('rappid_path'));

while 1
    notFound = [];
    for idx=1:length(mustFind)
        d=dir([root filesep mustFind{idx}]);
        notFound(idx) = length(d)==0;
    end

    if sum(notFound) > 0
        newRoot = fileparts(root);
        if strcmpi(newRoot,root)
            disp(['Could not find a valid RAppID installation.']);
            return;
        end
        root = newRoot;
    else
        break;
    end
end

disp(['Treating ''' root ''' as RAppID installation root.']);

rppth = [];
for idx=1:length(expandPaths)
    rppth = [rppth pathsep genpath([root filesep expandPaths{idx}])];
end
for idx=1:length(paths)
    rppth = [rppth pathsep root filesep paths{idx}];
end

%%%%%%%%%%%%%%%%%%%%%%
% save, reload, done %
%%%%%%%%%%%%%%%%%%%%%%

if nargin==1 && strcmpi(varargin{1},'append')
    path([newpth pathsep rppth]);
    disp(['RAppID path appended.']);
else
    path([rppth pathsep newpth]);
    disp(['RAppID path prepended.']);
end

savepath;
rehash toolboxcache;
disp(['Successful.']);

end
