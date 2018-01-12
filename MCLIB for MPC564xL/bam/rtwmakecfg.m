function makeInfo=rtwmakecfg()
%RTWMAKECFG adds include and source directories to the generated makefiles.
%   For details refer to documentation on the rtwmakecfg API.
makeInfo=[];

if(isHostBuild)

    % configure host source / libraries for the build
    mscripts_dir = rappid_564xl_find_mscripts;
    rappidDir ='rappid564xl';
    targetDir ='rappid564xl\rappid564xl';
    targetPath = rappid_564xl_find_target_path(targetDir);
    rappid_root_ind = findstr(targetPath,'\rappid564xl');
    rappid_root = mscripts_dir(1:rappid_root_ind(1)-1);      % rappid installation directory
     
    % add MC include path
    mc_includes = strcat(rappid_root,filesep,rappidDir,filesep,'MCLIB for MPC564xL',filesep,'include');
    makeInfo.includePath{1} = mc_includes; 
    
    % add MC library
	if strcmp(computer('arch'),'win32') == 1,
		mc_library = strcat(rappid_root,filesep,rappidDir,filesep,'MCLIB for MPC564xL',filesep,'lib',filesep,'lcc',filesep,'MCLIB.lib');
	else
		mc_library = strcat(rappid_root,filesep,rappidDir,filesep,'MCLIB for MPC564xL',filesep,'lib',filesep,'vc',filesep,'MCLIB.lib');
	end
	makeInfo.linkLibsObjs{1} = mc_library;
	
else
    
end


function hostBuild =isHostBuild
% determine if this is a host build (e.g. Accelerator) or a target build
% check the STF to determine the build context
%
% Note: in 12a, we introduce SIL Portable Word Sizes support with target 
% specific STF's - this function will have to be updated to get the context 
% via the MakeRTWSettingsObject.
%
rootModel = bdroot;
stf = get_param(rootModel, 'SystemTargetFile');
if strcmp(stf, 'rappid564xl.tlc')
    hostBuild = false;
else
    hostBuild = true;
end
