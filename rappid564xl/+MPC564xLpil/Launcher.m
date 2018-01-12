classdef Launcher < rtw.connectivity.Launcher
%
%   LAUNCHER(COMPONENTARGS,BUILDER) instantiates a LAUNCHER object that you can
%   use to control starting and stopping of an application on the target
%   processor. In this case, the target processor is a processor of your host
%   computer.
%
    properties
    
        ExePid = '';                                        
        TempFile = '';                                      
        
    end
    
    methods
        % constructor
        function this = Launcher(componentArgs, builder)
            error(nargchk(2, 2, nargin, 'struct'));
            % call super class constructor
            this@rtw.connectivity.Launcher(componentArgs, builder);
        end
        
        % destructor
        function delete(this) %#ok
            

        end
        
        % Start the application
        function startApplication(this)
            % get name of the elf file for loading to the target
            exe = this.getBuilder.getApplicationExecutable;
			
				% launch BootLoader
				disp(['start BootLoader ...'])
				rappid_564xl_bam(exe,'PIL'); 
        end
        
        % Stop the application
        function stopApplication(this)
            if ~isempty(this.ExePid)                                       
				disp('stop Debugger ...')
                rtw.connectivity.Utils.killProcess(this.ExePid, this.TempFile);         
                disp(['Debugger process terminated, pid = ' int2str(this.ExePid)]); 
				this.ExePid = '';                                              
            end                                                            
            
        end
    end
end
