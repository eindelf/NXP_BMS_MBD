function tmf = rappid_564xl_default_tmf()
%
% Copyright 2011 
% Freescale Semiconductor Inc
% All Rights Reserved 
%
% $Log: rappid_564xl_default_tmf.m,v $
% Revision 1.1  2010/10/28 22:03:39  r61406
% Issue:10000
% Create Code Base for RAppID Toolbox Lite
%
% Revision 1.6  2006/07/20 15:40:41  r61406
% PWM:Updated copyright notice and Log tag.
%
%

compiler = rappid_564xl_get_data('compiler');
targettype =rappid_564xl_get_data('targettype');
ver_str = find_matlab_ver;

tmf = 'rappid_564xl';
if(strcmp(compiler,'codewarrior')==1)
	tmf = strcat(tmf,'_cw');
elseif(strcmp(compiler,'Diab')==1)
	tmf = strcat(tmf,'_diab');
elseif(strcmp(compiler,'GreenHills')==1)
	tmf = strcat(tmf,'_ghs');
end

if(strcmp(targettype,'FLASH')==1)
	tmf = strcat(tmf,'_flash');
end

if(strcmp(ver_str(1),'8')==1)
  if (str2num(ver_str) > 8)
	tmf = strcat(tmf,'_2013');
  else
	tmf = strcat(tmf,'_2012b');
  end
end

tmf = strcat(tmf,'.tmf');

return
