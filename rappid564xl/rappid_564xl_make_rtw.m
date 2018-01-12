function rappid_564xl_make_rtw(varargin)

%
% Copyright 2010
% Freescale Semiconductor Inc
% All Rights Reserved
%
% $Log: rappid_make_rtw.m,v $
% Revision 1.1  2010/10/28 22:03:39  r61406
% Issue:10000
% Create Code Base for RAppID Toolbox Lite
%
% Revision 1.32  2006/12/05 21:51:54  r66544
% issue:267
%
%
%

%% workaround for rtwmakecfg.m search path issue
path(strcat(rappid_find_leo_root,'\MCLIB for MPC564xL\bam'),path);
%%

%% update model before first call rappid_get_cur_model
%slsfnagctlr('Clear', gcs, 'RTW Builder');
%set_param(gcs,'SimulationCommand','update');

% remove warning "Converting 'SLData(0)' value to MATLAB value" by setting the maximum 
% length of a vector that can appear literally in the file to 1000 (10 by default)
set_param(0,'RTWDataReferencesMinSize',1000);

set_param(rappid_get_cur_model, 'GenerateSampleERTMain','off');
try
    save_system(rappid_get_cur_model);
    if((strcmp(find_matlab_ver,'sp1')==0)&&(strcmp(find_matlab_ver,'sp2')==0)&&(strcmp(find_matlab_ver,'sp3')==0))
        set_param(rappid_get_cur_model,'GenerateMakefile','on');
        set_param(rappid_get_cur_model,'PostCodeGenCommand','rappid_analyzegencode(buildInfo)');
    end
catch
end

env_err=0;

compiler = rappid_564xl_get_data('compiler');

install_doc = [rappid_find_leo_root,filesep,'help',filesep,'Motor_Control_Toolbox_Installation_Quick_Start.pdf'];

if(strcmp(get_param(rappid_get_cur_model,'GenCodeOnly'),'off')==1)

    if(strcmp(compiler,'codewarrior')==1)

        if((isempty(getenv('MW_TOOL'))==1) && (isempty(getenv('CW_TOOL'))==1))            
            error1 = ['Environment Variables MW_TOOL or CW_TOOL not set. Please refer to ''Setting up the Target Compilers'' in <a href = "matlab:web ',install_doc,' -browser">Motor Control Toolbox Installation Quick Start.pdf</a> in the help folder'];
            rappid_error(error1);
            env_err=1;

        end

    elseif(strcmp(compiler,'Diab')==1)

        if(isempty(getenv('DIAB_TOOL'))==1)
            error2 = ['Environment Variable DIAB_TOOL not set. Please refer to ''Setting up the Target Compilers'' in <a href = "matlab:web ',install_doc,' -browser">Motor Control Toolbox Installation Quick Start.pdf</a> in the help folder'];
            rappid_error(error2);
            env_err=1;
        end

    elseif(strcmp(compiler,'GreenHills')==1)

        if(isempty(getenv('GHS_TOOL'))==1)
            error3 = ['Environment Variable GHS_TOOL not set. Please refer to ''Setting up the Target Compilers'' in <a href = "matlab:web ',install_doc,' -browser">Motor Control Toolbox Installation Quick Start.pdf</a> in the help folder'];
            rappid_error(error3);
            env_err=1;
        end

    end

    %else
    %    make_rtw(varargin{:});
end

errs=slsfnagctlr('GetNags',gcs);

toolbox_err = 0;
if (~isempty(errs))
	for(i = 1 : length(errs))
        if (strcmp(errs(i,1).type,'error')==1)
            toolbox_err = toolbox_err+1;
        end
    end
end
    
if(env_err==0) && (toolbox_err==0)
    try
        make_rtw(varargin{:});
		rappid_564xl_bam('','BAM');
    catch
    end
else
    slsfnagctlr('View');
end



return