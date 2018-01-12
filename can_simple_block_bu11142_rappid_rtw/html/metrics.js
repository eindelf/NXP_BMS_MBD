function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["ISRVectorTable"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\intc_sw_vectable.c",
	size: 1024};
	 this.metricsArray.var["adc_564xl_library.c:ADC"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	size: 8};
	 this.metricsArray.var["dspi_564xL_library.c:DSPI"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	size: 12};
	 this.metricsArray.var["rtDWork"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	size: 1168};
	 this.metricsArray.var["rtM_"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	size: 2};
	 this.metricsArray.var["rtU"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	size: 8};
	 this.metricsArray.var["rtY"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	size: 15};
	 this.metricsArray.fcn["DMA_init_Outputs_wrapper"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142_private.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["DisableExternalInterrupts"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_utils.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["EnableExternalInterrupts"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_utils.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["FunctionCallSubsystem"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 4,
	stackTotal: 43};
	 this.metricsArray.fcn["FunctionCallSubsystem_Init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["FunctionCallSubsystem_Reset"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["FunctionCallSubsystem_Start"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Mode_Entry_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\sysclk_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["PIT_Ch0_ISR"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_main.c",
	stack: 0,
	stackTotal: 30};
	 this.metricsArray.fcn["PIT_Ch1_ISR"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\pit_ch1_isr.c",
	stack: 0,
	stackTotal: 43};
	 this.metricsArray.fcn["SOCEstimationInit_Outputs_wrapper"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142_private.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["SPIRead_Outputs_wrapper"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142_private.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["SPITask_Outputs_wrapper"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142_private.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["SYSTEM_INIT_TASK"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_main.c",
	stack: 0,
	stackTotal: 12};
	 this.metricsArray.fcn["SYSTEM_TASK"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_main.c",
	stack: 2,
	stackTotal: 30};
	 this.metricsArray.fcn["Subsystem"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["Subsystem1"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem2"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem2_Init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem2_Reset"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem2_Start"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem_Reset"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem_i"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 31,
	stackTotal: 39};
	 this.metricsArray.fcn["adc0_config"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc0_config.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_channel_setup_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_channelmode_setup"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["adc_ctu_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_dma_setup_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_enter_powerdownmode_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_trigger_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_exit_powerdownmode_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_trigger_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_general_setup_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_injected_start"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_injected_start_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_trigger_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_interrupt_clear_channel"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["adc_interrupt_set_channel"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["adc_interrupt_set_imr"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_interrupt_setup_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_normal_start"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_normal_start_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_trigger_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_normal_stop"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_normal_stop_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_trigger_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_pin_init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["adc_presample"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_read_chan"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 2,
	stackTotal: 2};
	 this.metricsArray.fcn["adc_sampling_setup_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_scanmode_set"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_singleshot_set"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_trigger_setup_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["adc_wdg_init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["adc_wdg_set_selector"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\adc_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["asm"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_main.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["can0_buf4_7_isr"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can0_buf4_7_isr.c",
	stack: 24,
	stackTotal: 28};
	 this.metricsArray.fcn["can_simple_block_bu11142.c:rate_monotonic_scheduler"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["can_simple_block_bu11142_SetEventsForThisBaseStep"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["can_simple_block_bu11142_initialize"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 4,
	stackTotal: 12};
	 this.metricsArray.fcn["can_simple_block_bu11142_step"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 28};
	 this.metricsArray.fcn["can_simple_block_bu11142_step0"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["can_simple_block_bu11142_step1"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 24,
	stackTotal: 28};
	 this.metricsArray.fcn["can_simple_block_bu11142_terminate"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["ceil"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["cmu_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\sysclk_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["dspi1_2_isr"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi1_2_isr.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["dspi_564xl_config"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["dspi_564xl_get_status"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["dspi_564xl_interrupt_clr"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["dspi_564xl_interrupt_set"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["dspi_564xl_pin_init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["dspi_564xl_read_master"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 2,
	stackTotal: 2};
	 this.metricsArray.fcn["dspi_564xl_read_slave"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 2,
	stackTotal: 2};
	 this.metricsArray.fcn["dspi_564xl_send"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\dspi_564xL_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["e200zX_Interrupt_Setup"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\intc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["flexcan_564xl_buffer_init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["flexcan_564xl_buffer_lock"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["flexcan_564xl_buffer_rxbusy"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["flexcan_564xl_buffer_transmit"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["flexcan_564xl_clear_isr_flag"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["flexcan_564xl_clear_mask"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["flexcan_564xl_get_id"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["flexcan_564xl_get_idtype"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["flexcan_564xl_get_mb"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["flexcan_564xl_get_ts"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 2,
	stackTotal: 2};
	 this.metricsArray.fcn["flexcan_564xl_init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 3,
	stackTotal: 3};
	 this.metricsArray.fcn["flexcan_564xl_init_CCP"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 9,
	stackTotal: 12};
	 this.metricsArray.fcn["flexcan_564xl_init_CCP_FM"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 9,
	stackTotal: 12};
	 this.metricsArray.fcn["flexcan_564xl_init_FM"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 3,
	stackTotal: 3};
	 this.metricsArray.fcn["flexcan_564xl_pin_init"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["flexcan_564xl_readytoreceive"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["flexcan_564xl_release_mb_lock"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["flexcan_564xl_rxbuffull"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["flexcan_564xl_set_filter_id"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\flexcan_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fs_clearmem"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_utils.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["gpi_init_pcr_in_564xl_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\gpio_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["gpi_pin_read_564xl_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\gpio_564xl_library.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["gpo_init_pcr_out_564xl_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\gpio_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["gpo_pin_update_564xl_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\gpio_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["intc_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\intc_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["interrupt_handler"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\intc_sw_vectable.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["main"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_main.c",
	stack: 0,
	stackTotal: 40};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2016b\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["mode_entry_post_config_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\sysclk_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["pit_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\rappid_main.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["pit_timer_init_564xl"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\pit_timer_564xl_library.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundd"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\can_simple_block_bu11142.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["siu_general_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_parallel_port_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portA_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portB_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portC_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portD_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portE_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portF_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portG_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portH_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_portI_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_psmi_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["siu_unused_pins_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\siu_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sys_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\sys_init.c",
	stack: 40,
	stackTotal: 40};
	 this.metricsArray.fcn["sysclk_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\sysclk_init.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sysclk_module_init_fnc"] = {file: "C:\\MCToolbox\\rappid564xl\\can_simple_block_bu11142_rappid_rtw\\sysclk_init.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
