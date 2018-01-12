function rappid_564xl_user_copy_required_files(dest_dir)

mysource_dir = pwd;

    rp_copy(strcat(mysource_dir,filesep,'SPITask_CH1_wrapper.c'),strcat(dest_dir,filesep,'SPITask_CH1_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPITask_CH1.c'),strcat(dest_dir,filesep,'SPITask.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPITask_wrapper.c'),strcat(dest_dir,filesep,'SPITask_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPITask.c'),strcat(dest_dir,filesep,'SPITask.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPIRead_wrapper.c'),strcat(dest_dir,filesep,'SPIRead_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPIRead.c'),strcat(dest_dir,filesep,'SPIRead.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'DMA_init_wrapper.c'),strcat(dest_dir,filesep,'DMA_init_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'DMA_init.c'),strcat(dest_dir,filesep,'DMA_init.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPISendDMA_wrapper.c'),strcat(dest_dir,filesep,'SPISendDMA_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SPISendDMA.c'),strcat(dest_dir,filesep,'SPISendDMA.c'),'f');    
%     rp_copy(strcat(mysource_dir,filesep,'PEC15for6bytes_wrapper.c'),strcat(dest_dir,filesep,'PEC15for6bytes_wrapper.c'),'f');
%     rp_copy(strcat(mysource_dir,filesep,'PEC15for6bytes.c'),strcat(dest_dir,filesep,'PEC15for6bytes.c'),'f');   
    rp_copy(strcat(mysource_dir,filesep,'SOCEstimationInit_wrapper.c'),strcat(dest_dir,filesep,'SOCEstimationInit_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SOCEstimationInit.c'),strcat(dest_dir,filesep,'SOCEstimationInit.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SOCEstimationTask_wrapper.c'),strcat(dest_dir,filesep,'SOCEstimationTask_wrapper.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'SOCEstimationTask.c'),strcat(dest_dir,filesep,'SOCEstimationTask.c'),'f');
% 

mysource_dir = ['C:\MCToolbox\rappid564xl\src\sfmSrc'];
    rp_copy(strcat(mysource_dir,filesep,'BMU_Driver.c'),strcat(dest_dir,filesep,'BMU_Driver.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'DMA.c'),strcat(dest_dir,filesep,'DMA.c'),'f');    
    %rp_copy(strcat(mysource_dir,filesep,'DSPI_Driver.c'),strcat(dest_dir,filesep,'DSPI_Driver.c'),'f');

mysource_dir = ['C:\MCToolbox\rappid564xl\src\OptSrc'];
    rp_copy(strcat(mysource_dir,filesep,'Extended.c'),strcat(dest_dir,filesep,'Extended.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'const_params.c'),strcat(dest_dir,filesep,'const_params.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'rt_nonfinite.c'),strcat(dest_dir,filesep,'rt_nonfinite.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'rt_roundd_snf.c'),strcat(dest_dir,filesep,'rt_roundd_snf.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'rtGetInf.c'),strcat(dest_dir,filesep,'rtGetInf.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'rtGetNaN.c'),strcat(dest_dir,filesep,'rtGetNaN.c'),'f');
    rp_copy(strcat(mysource_dir,filesep,'look2_binlx.c'),strcat(dest_dir,filesep,'look2_binlx.c'),'f');    
    
%mysource_dir = ['C:\C\BMS\Ursidae\drivers_MPC564xL'];
%    rp_copy(strcat(mysource_dir,filesep,'spi_564xL_library.c'),strcat(dest_dir,filesep,'spi_564xL_library.c'),'f');

mysource_dir = ['C:\MCToolbox\rappid564xl\src\sfmInclude'];
    rp_copy(strcat(mysource_dir,filesep,'BMU_Driver.h'),strcat(dest_dir,filesep,'BMU_Driver.h'),'f');
    rp_copy(strcat(mysource_dir,filesep,'DMA.h'),strcat(dest_dir,filesep,'DMA.h'),'f');
    %rp_copy(strcat(mysource_dir,filesep,'DSPI_Driver.h'),strcat(dest_dir,filesep,'DSPI_Driver.h'),'f');
    rp_copy(strcat(mysource_dir,filesep,'localTypedefs.h'),strcat(dest_dir,filesep,'localTypedefs.h'),'f');

mysource_dir = ['C:\MCToolbox\rappid564xl\src\OptInclude'];
    rp_copy(strcat(mysource_dir,filesep,'Extended.h'),strcat(dest_dir,filesep,'Extended.h'),'f');
    rp_copy(strcat(mysource_dir,filesep,'look2_binlx.h'),strcat(dest_dir,filesep,'look2_binlx.h'),'f');    
    rp_copy(strcat(mysource_dir,filesep,'rt_nonfinite.h'),strcat(dest_dir,filesep,'rt_nonfinite.h'),'f');
    rp_copy(strcat(mysource_dir,filesep,'rt_roundd_snf.h'),strcat(dest_dir,filesep,'rt_roundd_snf.h'),'f');    
    rp_copy(strcat(mysource_dir,filesep,'rtGetInf.h'),strcat(dest_dir,filesep,'rtGetInf.h'),'f');
    rp_copy(strcat(mysource_dir,filesep,'rtGetNaN.h'),strcat(dest_dir,filesep,'rtGetNaN.h'),'f');    
    rp_copy(strcat(mysource_dir,filesep,'rtwtypes.h'),strcat(dest_dir,filesep,'rtwtypes.h'),'f');    

    %mysource_dir = ['C:\C\BMS\Ursidae\includes_MPC564xL'];
%    rp_copy(strcat(mysource_dir,filesep,'spi_564xL_library.h'),strcat(dest_dir,filesep,'spi_564xL_library.h'),'f');

mysource_dir = ['C:\MCToolbox\rappid564xl\src\includes'];
    rp_copy(strcat(mysource_dir,filesep,'FMPC5643L.h'),strcat(dest_dir,filesep,'FMPC5643L.h'),'f');

return