function sl_customization(cm)
  %% SL_CUSTOMIZATION for PIL connectivity config: MPC564xLpil.ConnectivityConfig
  cm.registerTargetInfo(@loc_createConfig);
  %% Register custom menu function.
  cm.addCustomMenuFcn('Simulink:ToolsMenu', @getMyMenuItems);
end

%% PIL connectivity
function config = loc_createConfig
	config = rtw.connectivity.ConfigRegistry;
	config.ConfigName = 'MPC564xL PIL';
	config.ConfigClass = 'MPC564xLpil.ConnectivityConfig';
	config.SystemTargetFile = {'rappid564xl.tlc'};
	config.TemplateMakefile = {'rappid_564xl_default_tmf'};
	config.TargetHWDeviceType = {'Freescale->32-bit PowerPC' 'Freescale->MPC55xx'};
end

function schemaFcns = getMyMenuItems(callbackInfo) 
  schemaFcns = {@getItemA}; 
end

function schema = getItemA(callbackInfo) 
    schema = sl_container_schema;
    schema.label = 'Freescale Motor Control Development Toolbox for MPC564xL';
    schema.childrenFcns = {@getItem1, @getItem2, @getItem3, @getItem4, @getItem5, @getItem6}; 
end

%% Define the schema function for first menu item.
function schema = getItem1(callbackInfo)
  schema = sl_action_schema;
  schema.label = 'To PIL Mode on MPC5643L';
  schema.userdata = 'udd1';	
  schema.callback = @myCallback1; 
end

function myCallback1(callbackInfo)
  rappid_564xl_set_pilsil_mode(bdroot,'pil');
end

function schema = getItem2(callbackInfo)
  % Make a submenu label 'Item Two' with     
  % the menu item above three times.      
  schema = sl_action_schema;
  schema.label = 'To SIL Mode';     
  schema.userdata = 'udd2';	
  schema.callback = @myCallback2;	
end 


function myCallback2(callbackInfo)
  rappid_564xl_set_pilsil_mode(bdroot,'sil');
end

function schema = getItem3(callbackInfo)
  % Make a submenu label 'Item Two' with     
  % the menu item above three times.      
  schema = sl_action_schema;
  schema.label = 'To Normal Mode';     
  schema.userdata = 'udd3';	
  schema.callback = @myCallback3;	
end 


function myCallback3(callbackInfo)
  rappid_564xl_set_pilsil_mode(bdroot,'nor');
end


function schema = getItem4(callbackInfo)
  % Make a submenu label 'Item Two' with     
  % the menu item above three times.      
  schema = sl_action_schema;
  schema.label = 'To Accelerator Mode';     
  schema.userdata = 'udd3';	
  schema.callback = @myCallback4;	
end 


function myCallback4(callbackInfo)
  rappid_564xl_set_pilsil_mode(bdroot,'acc');
end

function schema = getItem5(callbackInfo)
  % Make a submenu label 'Item Two' with     
  % the menu item above three times.      
  schema = sl_action_schema;
  schema.label = 'Generate PIL Block';     
  schema.userdata = 'udd3';	
  schema.callback = @myCallback5;	
end 


function myCallback5(callbackInfo)
  rappid_564xl_set_pilsil_mode(bdroot,'pilblock');
end

function schema = getItem6(callbackInfo)
  % Make a submenu label 'Item Two' with     
  % the menu item above three times.      
  schema = sl_action_schema;
  schema.label = 'Generate SIL Block';     
  schema.userdata = 'udd3';	
  schema.callback = @myCallback6;	
end 


function myCallback6(callbackInfo)
  rappid_564xl_set_pilsil_mode(bdroot,'silblock');
end