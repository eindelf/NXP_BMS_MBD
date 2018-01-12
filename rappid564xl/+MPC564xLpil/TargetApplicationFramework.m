classdef TargetApplicationFramework < rtw.pil.RtIOStreamApplicationFramework
%
%   The TARGETAPPLICATIONFRAMEWORK allows you to specify additional files needed
%   to build an application for the target environment. These files may include
%   code for hardware initialization as well as device driver code for a
%   communications channel. 
%
    methods
        % constructor
        function this = TargetApplicationFramework(componentArgs)
            error(nargchk(1, 1, nargin, 'struct'));
            % call super class constructor
            this@rtw.pil.RtIOStreamApplicationFramework(componentArgs);
            
%            this.addPILMain('target');                                             
                                                                                 
            % Additional source and library files to include in the build        
            % must be added to the BuildInfo property                            
                                                                                 
            % Get the BuildInfo object to update                                 
%            buildInfo = this.getBuildInfo;
                                                                                 
            % Add device driver files to implement the target-side of the        
            % host-target rtIOStream communications channel                      
%            buildInfo.addSourceFiles('linflex_pil.c');                       
                                                                                 
        end
    end
end
