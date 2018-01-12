classdef MakefileBuilder < rtw.connectivity.Builder
%MAKEFILEBUILDER builds an application for a target processor
% 
%   MAKEFILEBUILDER(COMPONENTARGS, TARGETAPPLICATIONFRAMEWORK) returns an
%   instance of the MAKEFILEBUILDER class. This class supports a customizable
%   makefile-based build process. You can use it to build applications (e.g. a
%   PIL application) that interface with a model component such as a referenced
%   model; this model component is included in the build as a collection of
%   compiled object code or library files.
%
%   MAKEFILEBUILDER uses the same template makefile that is specified in the
%   model representing the component included in the build. It is required that
%   this template makefile includes a makefile target named MAKEFILEBUILDER_TGT.
%
%   See also RTW.CONNECTIVITY.COMPONENTARGS, RTW.CONNECTIVITY.CONFIG,
%   RTW.PIL.RTIOSTREAMAPPLICATIONFRAMEWORK

%   Copyright 2007-2010 The MathWorks, Inc.
%   $Revision: 1.1.8.16 $


    % private properties
    properties (SetAccess = 'private', GetAccess = 'private')
        modelRefLibs;
        exeExtension;
    end    

    methods
        % constructor
        function this = MakefileBuilder(componentArgs, ...
                                        targetApplicationFramework, ...
                                        exeExtension)
            error(nargchk(3, 3, nargin, 'struct'));
            % call super class constructor                             
            this@rtw.connectivity.Builder(componentArgs, ...
                                targetApplicationFramework);
            
            this.exeExtension = exeExtension;
        end
    end

    methods (Access = 'protected')
    
    function buildInfo = getComponentIntegrationBuildInfo(this, buildInfo)
    %getComponentIntegrationBuildInfo returns the integration BUILDINFO object
            error(nargchk(2, 2, nargin, 'struct'));
          
            % 
            % get some build args
            %
            baModelRefTargetType = this.getBuildArg(buildInfo, ...
                'MODELREF_TARGET_TYPE');

            baModelRefLinkLibs = this.getBuildArg(buildInfo, ...
                'MODELREF_LINK_LIBS');

            baRelativePathToAnchor = this.getBuildArg(buildInfo, ...
                'RELATIVE_PATH_TO_ANCHOR');

            baModelLib = this.getBuildArg(buildInfo, ...
                'MODELLIB');

            baSharedSrc = this.getBuildArg(buildInfo, ...
                'SHARED_SRC');

            baSharedSrcDir = this.getBuildArg(buildInfo, ...
                'SHARED_SRC_DIR');

            baSharedBinDir = this.getBuildArg(buildInfo, ...
                'SHARED_BIN_DIR');
            
            baSharedLib = this.getBuildArg(buildInfo, ...
                    'SHARED_LIB');
                                                                              
            % Update shared paths
            tmpPath = baSharedSrc.Value;
            if ~isempty(tmpPath)
                tmpPath = fullfile('..',tmpPath);
                baSharedSrc.Value = tmpPath;
            end
            tmpPath = baSharedSrcDir.Value;
            if ~isempty(tmpPath)
                tmpPath = fullfile('..',tmpPath);
                baSharedSrcDir.Value = tmpPath;
            end
            tmpPath = baSharedBinDir.Value;
            if ~isempty(tmpPath)
                tmpPath = fullfile('..',tmpPath);
                baSharedBinDir.Value = tmpPath;
            end
            tmpPath = baSharedLib.Value;
            if ~isempty(tmpPath)
                tmpPath = fullfile('..',tmpPath);
                baSharedLib.Value = tmpPath;
            end
            
            % Update RELATIVE_PATH_TO_ANCHOR
            relativePathToAnchor = baRelativePathToAnchor.Value;
            relativePathToAnchor = fullfile('..',relativePathToAnchor);
            baRelativePathToAnchor.Value = relativePathToAnchor;
            
            % Update MODELREF_TARGET_TYPE
            baModelRefTargetTypeOrigValue = baModelRefTargetType.Value;
            baModelRefTargetType.Value = 'NONE';
            
            % Add relative path for MODELREF_LINK_LIBS
            modelRefs = baModelRefLinkLibs.Value;
            updatedModelRefs = '';
            if ~isempty(modelRefs)
                % parse modelRefs string
                modelRefsCell = regexp(modelRefs, '(\S*)', 'tokens');
                for i=1:length(modelRefsCell)
                    modelRefLib = modelRefsCell{i}{1};
                    updatedModelRefLib = ['../' modelRefLib];
                    updatedModelRefs = [updatedModelRefs ' ' updatedModelRefLib]; %#ok
                end
                this.modelRefLibs = updatedModelRefs;
            end
            baModelRefLinkLibs.Value = updatedModelRefs;

            % Is the component being linked into an executable being taken
            % from a top-model build or a model reference build
            topmodelbuild = strcmp( baModelRefTargetTypeOrigValue, 'NONE');
            
            % The MODEL_MODULES token is expanded and assigned to MODULES
            % in the TMF.
            %
            % For MakefileBuilder processing, the TMF does:
            % 
            % PREBUILT_SRCS      = $(MODULES)
            % PREBUILT_OBJS      = $(addsuffix .o, $(basename $(PREBUILT_SRCS)))
            % 
            % Therefore, we need to make sure that all prebuilt objects in the
            % original build dir are listed in MODEL_MODULES. 
            %
            % Note that given the above, it doesn't matter whether the .c 
            % files live in the original build dir, so long as the object 
            % code is there!
            %
            % Additionally, the TMF will build other source files listed in
            % BuildInfo in the PIL build directory so we need to make sure 
            % that only the PIL application source files are listed there. 
            % 
            % Hence we remove all source files after the MODEL_MODULES
            % processing complete.            
            for i=1:length(buildInfo.Tokens)
                if strmatch('|>MODEL_MODULES<|', buildInfo.Tokens(i).Key)
                    modelModulesToken = buildInfo.Tokens(i);
                end
            end
            if topmodelbuild                
                % get all source files and set MODEL_MODULES
                % we don't care about location of the source files
                concatenatePaths = false;
                replaceMatlabroot = false;                
                prebuiltSrcFiles = buildInfo.getSourceFiles(concatenatePaths, replaceMatlabroot);                                                                                
                % list of source files to skip:
                %
                % PIL application does not need to link against these
                %
                skipFiles = {'rappid_main' 'ert_main'};
                modelModules = '';
                for srcFileIdx=1:length(prebuiltSrcFiles)
                    srcFile = prebuiltSrcFiles{srcFileIdx};
                    % skip anything on the skip list 
                    [pathstr, srcName, ext] = fileparts(srcFile);
                    if any(strcmp(srcName, skipFiles))
                       continue; 
                    end
                    % add ".." to reference original build dir
                    modelModules = [modelModules ' ' fullfile('..', srcFile)]; %#ok
                end
                % set
                modelModulesToken.Value = modelModules;                
                % MODELLIB not used for integrating a top-model component
                baModelLib.Value = '';                
                % avoid issues with Generate ERT S-Function
                baGenerateERTSfun = this.getBuildArg(buildInfo, ...
                    'GENERATE_ERT_S_FUNCTION');
                baGenerateERTSfun.Value = '0';                                              
            else                                
                % remove MODEL_MODULES (should already be compiled to MODELLIB)
                modelModulesToken.Value = '';                
                % Add relative path for MODELLIB
                modelLib = baModelLib.Value;
                modelLib = fullfile('..',modelLib);
                baModelLib.Value = modelLib;                                
            end            
            % process BuildInfo libraries  
            % 
            % process all libs except for rtwshared which is
            % stripped out by genMakefileAndBuild anyway.
            includeGroupIDs = {};
            excludeGroupIDs = {'SHARED_SRC_LIB'};
            libs = buildInfo.getLinkObjects(includeGroupIDs, excludeGroupIDs);
            for i=1:length(libs)                
                if ~libs(i).LinkOnly
                    % There are two types of non-LinkOnly library:
                    %   precompiled and non-precompiled.
                    %
                    % Precompiled: 
                    %
                    % The behaviour of precompiled libraries 
                    % is deeply embedded inside the TMF's.
                    %
                    % Some of our products use precompiled libraries
                    % (e.g. physmod) so we must support them without any
                    % limitations.   
                    %
                    % Therefore, MakefileBuilder will allow
                    % the TMF to process these libraries in the usual way.
                    % Typically, this will result in linking the PIL
                    % application against a precompiled library, as
                    % desired, however, the TMF may contain logic (e.g.
                    % ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS)) mechanism) that
                    % under some circumstances rebuilds the library inside
                    % the RTW build directory and again inside the PIL
                    % build directory!
                    %
                    % Non-precompiled:
                    %                    
                    % Standalone PIL:
                    %
                    % Non-precompiled libraries are built inside the RTW
                    % build directory.   We want to avoid rebuilding them
                    % again inside the PIL build directory.   Therefore,
                    % MakefileBuilder will mark them as LinkOnly to avoid
                    % the rules in the TMF.
                    %
                    % Model block PIL:
                    % 
                    % There is no unique non-precompiled
                    % lib to link against.   To avoid confusion, we don't 
                    % build it in the PIL build dir; instead we error out.
                    %
                    if ~libs(i).Precompiled
                        if topmodelbuild
                            % Only targets using TargetLibSuffix are supported.
                            %
                            % Without TargetLibSuffix, the lib suffix info is
                            % hardcoded directly into the TMF files, as is the
                            % case for our SIL host-based TMF's.
                            %
                            targetLibSuffix = buildInfo.TargetLibSuffix;
                            if isempty(targetLibSuffix)
                                % error id is contained within error message which
                                % allows us to be more specific than the generic
                                % PILImplementationError that masks the true error
                                errorId = 'MakefileBuilderNoTargetLibSuffix';
                                rtw.connectivity.ProductInfo.error('target', ...
                                    errorId, ...
                                    errorId, ...
                                    buildInfo.ModelName, ...
                                    libs(i).Name);
                            end
                            % transform to LinkOnly in order to avoid any
                            % possibility of a PIL rebuild
                            libs(i).LinkOnly = true;
                            % apply the TargetLibSuffix
                            libs(i).Name = fullfile([libs(i).Name targetLibSuffix]);                                                        
                            % Adjust the BuildInfo Path appropriately.
                            libs(i).Path = '..';
                        else                            
                            % error id is contained within error message which
                            % allows us to be more specific than the generic
                            % PILImplementationError that masks the true error
                            errorId = 'MakefileBuilderModelRefNoNonPrecompLib';
                            rtw.connectivity.ProductInfo.error('target', ...
                                errorId, ...
                                errorId, ...
                                buildInfo.ModelName, ...
                                libs(i).Name);
                        end
                    end
                end
            end
            % remove all source files to make sure that we aren't
            % unknowingly relying on genMakefileAndBuild doing any
            % processing of them, e.g. srcs in the Sfcn group
            buildInfo.Src.Files = [];            
            % Update all relative include paths
            includePaths = buildInfo.Inc.Paths;
            for i=1:length(includePaths)
                if ~isempty(regexp(includePaths(i).Value, '^\.', 'once'))
                    % match "." or ".." at the start of a path
                    includePaths(i).Value = fullfile('..', includePaths(i).Value);
                end
            end
        end

        function build(this, buildInfo)
            error(nargchk(2, 2, nargin, 'struct'));

            % The call to genMakefileAndBuild below fails if the target is up to
            % date (G446835). As a workaround, delete the target if it exists and
            % always re-link it.
            %
            % Note: the RTW target is not touched.
            target = this.getExecutable(buildInfo);
            if exist(target, 'file')
               delete(target);
               if exist(target, 'file')
                  % Permission denied - target must be a resource held by
                  % a process - most likely because Launcher "stopApplication" has
                  % not been called / not been implemented to correctly free up
                  % the application.
                  %
                  % When this workaround is removed then this case
                  % will result in a link error during genMakefileAndBuild 
                  % (only if the target needs to be rebuilt).
                  %
                  % Until then, the error about the build success string from 
                  % genMakefileAndBuild is confusing so we'll throw an error 
                  % message up front.
                  rtw.connectivity.ProductInfo.error('target', 'ExecutablePermissionDenied',...
                      target);
               end
            end
            
            % set build arg for the type of target to build
            buildInfo.addBuildArgs('MAKEFILEBUILDER_TGT', '1');

            % build in app dir (location of buildInfo)
            appDir = this.getComponentArgs.getApplicationCodePath;
            startDir = cd(appDir);

            try            
                % find template makefile tokens
                toks    =  get(buildInfo.Tokens,'Key');
                tokVals =  get(buildInfo.Tokens,'Value');
                
                % create/update RSP-file if required
                rspFile = tokVals{strcmp(toks,'|>MODELREF_LINK_RSPFILE_NAME<|')};
                fid = fopen(rspFile,'wt');
                fprintf(fid, '%s \n', this.modelRefLibs);
                fclose(fid);
                
                % create an rtw_proj.tmw if required
                if ~exist('./rtw_proj.tmw','file')
                    fid = fopen('rtw_proj.tmw','w');
                    fprintf(fid,'This file is generated by the Real-Time Workshop');
                    fclose(fid);
                end                
                % determine rtwVerbose setting                
				if ~isfield(this.getComponentArgs.getInternalData, 'configSet')
					modelName = strtok(this.getComponentArgs.getComponentPath,'/');
					rtwVerboseParam = get_param(modelName, 'RTWVerbose');
				else
					rtwVerboseParam = get_param(this.getComponentArgs.getInternalData.configSet, 'RTWVerbose');                 
				end            
                % convert to logical
                switch rtwVerboseParam
                    case 'on'
                        rtwVerbose = true;
                    case 'off'
                        rtwVerbose = false;
                    otherwise
                        assert(false, 'Unexpected value for rtwVerboseParam: %s', rtwVerboseParam);
                end
                
                            
                % Dispatch any build hooks attached to the model
				rootModel = strtok(this.getComponentArgs.getComponentPath,'/');
				%-------- % does not work on R2009a
                %if bdIsLoaded(rootModel)
                %    hookArgs = {'before_target_make',rootModel};
                %    rtw.pil.BuildHook.dispatch(hookArgs{:});
                %end
				%----------------------------------

                % this.getComponentArgs.getComponentCodeName is used to match the model name specified
                % inside the BuildInfo...
                buildResults = RTW.genMakefileAndBuild(buildInfo,...
                                                       this.getTMF,...
                                                       'buildName', this.getComponentArgs.getComponentCodeName, ...
                                                       'RTWVerbose', rtwVerbose);
            
                % Dispatch any build hooks attached to the model
				%-------- % does not work on R2009a
                %if bdIsLoaded(rootModel)
                %    hookArgs = {'after_target_make',rootModel,[],[],buildInfo};
                %    rtw.pil.BuildHook.dispatch(hookArgs{:});
                %end
				%----------------------------------

            catch eObj
                cd(startDir);
                rethrow(eObj);
            end
            cd(startDir);            
            % make sure the target was built by checking 
            % buildResults.targetNotBuiltReason  
            targetNotBuiltReason = buildResults.targetNotBuiltReason;
            if ~isempty(targetNotBuiltReason.identifier)
                % throw RTW error
                error(targetNotBuiltReason.identifier, ...
                      '%s', ...
                      targetNotBuiltReason.message);
            end                                    
        end

        function exe = getExecutable(this, buildInfo) %#ok
            error(nargchk(2, 2, nargin, 'struct'));
            
            % default location
            exe = fullfile(this.getComponentArgs.getApplicationCodePath, ...
                           [this.getComponentArgs.getComponentCodeName ...
                            this.pGetExecutableExtension]);
        end


        % Get full path to the Template Makefile (TMF) that was used to build the
        % component being integrated; a sub-class may re-use this TMF or supply
        % a new TMF to be used for building the executable.
        function tmfFullPath = getComponentTmfFullPath(this)                        
			if verLessThan('Simulink', '8.5')
				buildInfoFileContents = this.getComponentBuildInfoMATFileContents;
			else
				componentBuildInfoPath = this.getComponentBuildInfoPath;
				buildInfoFileContents = this.getComponentBuildInfoMATFileContents(componentBuildInfoPath);
			end
            
            % check for templateMakefile field
            if ~isfield(buildInfoFileContents, 'templateMakefile')
                rtw.connectivity.ProductInfo.error('target', 'GetComponentTmfFullPath');
            end
            
            tmfFullPath = buildInfoFileContents.templateMakefile;

        end
        
        
        function tmf = getTMF(this)
            error(nargchk(1, 1, nargin, 'struct'));
            
            % Re-use the same Template Makefile as for the component build
            tmf = this.getComponentTmfFullPath;
            
        end
        
        function extension = getExecutableExtension(this)
            error(nargchk(1, 1, nargin, 'struct'));
            
            extension = this.exeExtension;
            
        end
    end
    
    
    methods (Access = 'private')    

        function exe = pGetExecutableExtension(this)
           % get the extension from the subclass
           exe = this.getExecutableExtension;
           % add "." if required
           if ~isempty(exe)
              if exe(1) ~= '.'
                 exe = ['.' exe];
              end
           end          
        end                
    end
    
    methods (Access = 'private', Static = true)
        function buildArg = getBuildArg(buildInfo, key)
             % get build args
            buildArgs = buildInfo.BuildArgs;
            buildArg = [];
            for i=1:length(buildArgs)
                ba = buildArgs(i);
                if strcmp(ba.Key, key)
                    buildArg = ba;
                    break;
                end
            end    
            if isempty(buildArg)
                rtw.connectivity.ProductInfo.error('target', 'BuildArgMissing', key);
            end
        end 
    end
end
