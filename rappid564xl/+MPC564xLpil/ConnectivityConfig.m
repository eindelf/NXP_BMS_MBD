classdef ConnectivityConfig < rtw.connectivity.Config
%
%   CONNECTIVITYCONFIG(COMPONENTARGS) creates instances of MAKEFILEBUILDER,
%   LAUNCHER, RTIOSTREAMHOSTCOMMUNICATOR and collects them together into a
%   connectivity configuration class for PIL.
%
    methods
        % Constructor
        function this = ConnectivityConfig(componentArgs)
            
            % An executable framework specifies additional source files and
            % libraries required for building the PIL executable
            targetApplicationFramework = ...
                MPC564xLpil.TargetApplicationFramework(componentArgs);
            
            % Filename extension for executable on the target system
            exeExtension = '.elf';
            
            % Create an instance of MakefileBuilder; this works in
            % conjunction with your template makefile to build the PIL
            % executable
			builder = MPC564xLpil.MakefileBuilder(componentArgs, targetApplicationFramework, exeExtension);
            
            % Launcher
            launcher = MPC564xLpil.Launcher(componentArgs, builder);
            
            % File extension for shared libraries (e.g. .dll on Windows)
            sharedLibExt=system_dependent('GetSharedLibExt'); 

            % Evaluate name of the rtIOStream shared library
            prefix = '';
            rtiostreamLib = [prefix 'rtiostreamserial' sharedLibExt];
            
            hostCommunicator = rtw.connectivity.RtIOStreamHostCommunicator(...
                componentArgs, ...
                launcher, ...
                rtiostreamLib);
            
            % For some targets it may be necessary to set a timeout value
            % for initial setup of the communications channel. For example,
            % the target processor may take a few seconds before it is
            % ready to open its side of the communications channel. If a
            % non-zero timeout value is set then the communicator will
            % repeatedly try to open the communications channel until the
            % timeout value is reached.
            hostCommunicator.setInitCommsTimeout(0); 
            
            % Configure a timeout period for reading of data by the host 
            % from the target. If no data is received with the specified 
            % period an error will be thrown.
            timeoutReadDataSecs = 10;
            hostCommunicator.setTimeoutRecvSecs(timeoutReadDataSecs);

            % Custom arguments that will be passed to the
            % rtIOStreamOpen function in the rtIOStream shared
            % library (this configures the host-side of the
            % communications channel)
			portNumStr = rappid_564xl_get_pil_port();
			baudStr = int2str(rappid_564xl_pil_baud());
			
			rtIOStreamOpenArgs = { '-port', portNumStr, '-baud', baudStr };
            hostCommunicator.setOpenRtIOStreamArgList(rtIOStreamOpenArgs);
            
            % call super class constructor to register components
            this@rtw.connectivity.Config(componentArgs,...
                                         builder,...
                                         launcher,...
                                         hostCommunicator);
        end
    end
end

