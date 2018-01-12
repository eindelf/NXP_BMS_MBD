function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/ADC Config */
	this.urlHashMap["can_spi_simple_block_bu:35"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=can_spi_simple_block_bu:35";
	/* <Root>/CAN Config */
	this.urlHashMap["can_spi_simple_block_bu:2"] = "can_spi_simple_block_bu.c:139";
	/* <Root>/CAN Receive Data Trigger1 */
	this.urlHashMap["can_spi_simple_block_bu:3"] = "can_spi_simple_block_bu.c:161&can_spi_simple_block_bu.h:34,35,36,37";
	/* <Root>/CAN Transmit1 */
	this.urlHashMap["can_spi_simple_block_bu:4"] = "can_spi_simple_block_bu.c:100";
	/* <Root>/CAN_Receive_data1 */
	this.urlHashMap["can_spi_simple_block_bu:5"] = "can_spi_simple_block_bu.c:55,152";
	/* <Root>/Constant */
	this.urlHashMap["can_spi_simple_block_bu:6"] = "msg=rtwMsg_notTraceable&block=can_spi_simple_block_bu:6";
	/* <Root>/Constant1 */
	this.urlHashMap["can_spi_simple_block_bu:7"] = "can_spi_simple_block_bu.c:82";
	/* <Root>/Constant2 */
	this.urlHashMap["can_spi_simple_block_bu:8"] = "can_spi_simple_block_bu.c:83";
	/* <Root>/Constant3 */
	this.urlHashMap["can_spi_simple_block_bu:9"] = "can_spi_simple_block_bu.c:84";
	/* <Root>/Constant4 */
	this.urlHashMap["can_spi_simple_block_bu:10"] = "can_spi_simple_block_bu.c:85";
	/* <Root>/Constant5 */
	this.urlHashMap["can_spi_simple_block_bu:11"] = "can_spi_simple_block_bu.c:86";
	/* <Root>/Constant6 */
	this.urlHashMap["can_spi_simple_block_bu:12"] = "can_spi_simple_block_bu.c:87";
	/* <Root>/Constant7 */
	this.urlHashMap["can_spi_simple_block_bu:13"] = "can_spi_simple_block_bu.c:88";
	/* <Root>/Constant8 */
	this.urlHashMap["can_spi_simple_block_bu:14"] = "can_spi_simple_block_bu.c:89";
	/* <Root>/Constant9 */
	this.urlHashMap["can_spi_simple_block_bu:44"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=can_spi_simple_block_bu:44";
	/* <Root>/DSPI Config */
	this.urlHashMap["can_spi_simple_block_bu:43"] = "can_spi_simple_block_bu.c:143";
	/* <Root>/DSPI Transmit */
	this.urlHashMap["can_spi_simple_block_bu:45"] = "can_spi_simple_block_bu.c:46,146";
	/* <Root>/Data Type Conversion4 */
	this.urlHashMap["can_spi_simple_block_bu:46"] = "can_spi_simple_block_bu.h:44&can_spi_simple_block_bu_data.c:25";
	/* <Root>/Subsystem */
	this.urlHashMap["can_spi_simple_block_bu:16"] = "can_spi_simple_block_bu.c:29";
	/* <Root>/Out1 */
	this.urlHashMap["can_spi_simple_block_bu:29"] = "can_spi_simple_block_bu.h:49";
	/* <Root>/Out2 */
	this.urlHashMap["can_spi_simple_block_bu:30"] = "can_spi_simple_block_bu.h:50";
	/* <Root>/Out3 */
	this.urlHashMap["can_spi_simple_block_bu:31"] = "can_spi_simple_block_bu.h:51";
	/* <Root>/Out4 */
	this.urlHashMap["can_spi_simple_block_bu:32"] = "can_spi_simple_block_bu.h:52";
	/* <Root>/Out5 */
	this.urlHashMap["can_spi_simple_block_bu:33"] = "can_spi_simple_block_bu.c:78&can_spi_simple_block_bu.h:53";
	/* <S1>/In3 */
	this.urlHashMap["can_spi_simple_block_bu:19"] = "can_spi_simple_block_bu.c:34,40&can_spi_simple_block_bu.h:39";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "can_spi_simple_block_bu"};
	this.sidHashMap["can_spi_simple_block_bu"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "can_spi_simple_block_bu:16"};
	this.sidHashMap["can_spi_simple_block_bu:16"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/ADC Config"] = {sid: "can_spi_simple_block_bu:35"};
	this.sidHashMap["can_spi_simple_block_bu:35"] = {rtwname: "<Root>/ADC Config"};
	this.rtwnameHashMap["<Root>/Bus Creator"] = {sid: "can_spi_simple_block_bu:1"};
	this.sidHashMap["can_spi_simple_block_bu:1"] = {rtwname: "<Root>/Bus Creator"};
	this.rtwnameHashMap["<Root>/CAN Config"] = {sid: "can_spi_simple_block_bu:2"};
	this.sidHashMap["can_spi_simple_block_bu:2"] = {rtwname: "<Root>/CAN Config"};
	this.rtwnameHashMap["<Root>/CAN Receive Data Trigger1"] = {sid: "can_spi_simple_block_bu:3"};
	this.sidHashMap["can_spi_simple_block_bu:3"] = {rtwname: "<Root>/CAN Receive Data Trigger1"};
	this.rtwnameHashMap["<Root>/CAN Transmit1"] = {sid: "can_spi_simple_block_bu:4"};
	this.sidHashMap["can_spi_simple_block_bu:4"] = {rtwname: "<Root>/CAN Transmit1"};
	this.rtwnameHashMap["<Root>/CAN_Receive_data1"] = {sid: "can_spi_simple_block_bu:5"};
	this.sidHashMap["can_spi_simple_block_bu:5"] = {rtwname: "<Root>/CAN_Receive_data1"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "can_spi_simple_block_bu:6"};
	this.sidHashMap["can_spi_simple_block_bu:6"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "can_spi_simple_block_bu:7"};
	this.sidHashMap["can_spi_simple_block_bu:7"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "can_spi_simple_block_bu:8"};
	this.sidHashMap["can_spi_simple_block_bu:8"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant3"] = {sid: "can_spi_simple_block_bu:9"};
	this.sidHashMap["can_spi_simple_block_bu:9"] = {rtwname: "<Root>/Constant3"};
	this.rtwnameHashMap["<Root>/Constant4"] = {sid: "can_spi_simple_block_bu:10"};
	this.sidHashMap["can_spi_simple_block_bu:10"] = {rtwname: "<Root>/Constant4"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "can_spi_simple_block_bu:11"};
	this.sidHashMap["can_spi_simple_block_bu:11"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/Constant6"] = {sid: "can_spi_simple_block_bu:12"};
	this.sidHashMap["can_spi_simple_block_bu:12"] = {rtwname: "<Root>/Constant6"};
	this.rtwnameHashMap["<Root>/Constant7"] = {sid: "can_spi_simple_block_bu:13"};
	this.sidHashMap["can_spi_simple_block_bu:13"] = {rtwname: "<Root>/Constant7"};
	this.rtwnameHashMap["<Root>/Constant8"] = {sid: "can_spi_simple_block_bu:14"};
	this.sidHashMap["can_spi_simple_block_bu:14"] = {rtwname: "<Root>/Constant8"};
	this.rtwnameHashMap["<Root>/Constant9"] = {sid: "can_spi_simple_block_bu:44"};
	this.sidHashMap["can_spi_simple_block_bu:44"] = {rtwname: "<Root>/Constant9"};
	this.rtwnameHashMap["<Root>/DSPI Config"] = {sid: "can_spi_simple_block_bu:43"};
	this.sidHashMap["can_spi_simple_block_bu:43"] = {rtwname: "<Root>/DSPI Config"};
	this.rtwnameHashMap["<Root>/DSPI Transmit"] = {sid: "can_spi_simple_block_bu:45"};
	this.sidHashMap["can_spi_simple_block_bu:45"] = {rtwname: "<Root>/DSPI Transmit"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "can_spi_simple_block_bu:46"};
	this.sidHashMap["can_spi_simple_block_bu:46"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/RAppID_564xL_Config"] = {sid: "can_spi_simple_block_bu:40"};
	this.sidHashMap["can_spi_simple_block_bu:40"] = {rtwname: "<Root>/RAppID_564xL_Config"};
	this.rtwnameHashMap["<Root>/Subsystem"] = {sid: "can_spi_simple_block_bu:16"};
	this.sidHashMap["can_spi_simple_block_bu:16"] = {rtwname: "<Root>/Subsystem"};
	this.rtwnameHashMap["<Root>/Out1"] = {sid: "can_spi_simple_block_bu:29"};
	this.sidHashMap["can_spi_simple_block_bu:29"] = {rtwname: "<Root>/Out1"};
	this.rtwnameHashMap["<Root>/Out2"] = {sid: "can_spi_simple_block_bu:30"};
	this.sidHashMap["can_spi_simple_block_bu:30"] = {rtwname: "<Root>/Out2"};
	this.rtwnameHashMap["<Root>/Out3"] = {sid: "can_spi_simple_block_bu:31"};
	this.sidHashMap["can_spi_simple_block_bu:31"] = {rtwname: "<Root>/Out3"};
	this.rtwnameHashMap["<Root>/Out4"] = {sid: "can_spi_simple_block_bu:32"};
	this.sidHashMap["can_spi_simple_block_bu:32"] = {rtwname: "<Root>/Out4"};
	this.rtwnameHashMap["<Root>/Out5"] = {sid: "can_spi_simple_block_bu:33"};
	this.sidHashMap["can_spi_simple_block_bu:33"] = {rtwname: "<Root>/Out5"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "can_spi_simple_block_bu:17"};
	this.sidHashMap["can_spi_simple_block_bu:17"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "can_spi_simple_block_bu:18"};
	this.sidHashMap["can_spi_simple_block_bu:18"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/In3"] = {sid: "can_spi_simple_block_bu:19"};
	this.sidHashMap["can_spi_simple_block_bu:19"] = {rtwname: "<S1>/In3"};
	this.rtwnameHashMap["<S1>/In4"] = {sid: "can_spi_simple_block_bu:20"};
	this.sidHashMap["can_spi_simple_block_bu:20"] = {rtwname: "<S1>/In4"};
	this.rtwnameHashMap["<S1>/function"] = {sid: "can_spi_simple_block_bu:21"};
	this.sidHashMap["can_spi_simple_block_bu:21"] = {rtwname: "<S1>/function"};
	this.rtwnameHashMap["<S1>/Demux"] = {sid: "can_spi_simple_block_bu:22"};
	this.sidHashMap["can_spi_simple_block_bu:22"] = {rtwname: "<S1>/Demux"};
	this.rtwnameHashMap["<S1>/Mux"] = {sid: "can_spi_simple_block_bu:23"};
	this.sidHashMap["can_spi_simple_block_bu:23"] = {rtwname: "<S1>/Mux"};
	this.rtwnameHashMap["<S1>/Terminator"] = {sid: "can_spi_simple_block_bu:24"};
	this.sidHashMap["can_spi_simple_block_bu:24"] = {rtwname: "<S1>/Terminator"};
	this.rtwnameHashMap["<S1>/Terminator1"] = {sid: "can_spi_simple_block_bu:25"};
	this.sidHashMap["can_spi_simple_block_bu:25"] = {rtwname: "<S1>/Terminator1"};
	this.rtwnameHashMap["<S1>/Terminator2"] = {sid: "can_spi_simple_block_bu:26"};
	this.sidHashMap["can_spi_simple_block_bu:26"] = {rtwname: "<S1>/Terminator2"};
	this.rtwnameHashMap["<S1>/Terminator3"] = {sid: "can_spi_simple_block_bu:27"};
	this.sidHashMap["can_spi_simple_block_bu:27"] = {rtwname: "<S1>/Terminator3"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "can_spi_simple_block_bu:28"};
	this.sidHashMap["can_spi_simple_block_bu:28"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
