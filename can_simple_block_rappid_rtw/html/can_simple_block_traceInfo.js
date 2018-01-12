function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/ADC Config */
	this.urlHashMap["can_simple_block:35"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=can_simple_block:35";
	/* <Root>/CAN Config */
	this.urlHashMap["can_simple_block:2"] = "can_simple_block.c:129";
	/* <Root>/CAN Receive Data Trigger1 */
	this.urlHashMap["can_simple_block:3"] = "can_simple_block.c:142&can_simple_block.h:34,35,36,37";
	/* <Root>/CAN Transmit1 */
	this.urlHashMap["can_simple_block:4"] = "can_simple_block.c:90";
	/* <Root>/CAN_Receive_data1 */
	this.urlHashMap["can_simple_block:5"] = "can_simple_block.c:45,133";
	/* <Root>/Constant */
	this.urlHashMap["can_simple_block:6"] = "msg=rtwMsg_notTraceable&block=can_simple_block:6";
	/* <Root>/Constant1 */
	this.urlHashMap["can_simple_block:7"] = "can_simple_block.c:72";
	/* <Root>/Constant2 */
	this.urlHashMap["can_simple_block:8"] = "can_simple_block.c:73";
	/* <Root>/Constant3 */
	this.urlHashMap["can_simple_block:9"] = "can_simple_block.c:74";
	/* <Root>/Constant4 */
	this.urlHashMap["can_simple_block:10"] = "can_simple_block.c:75";
	/* <Root>/Constant5 */
	this.urlHashMap["can_simple_block:11"] = "can_simple_block.c:76";
	/* <Root>/Constant6 */
	this.urlHashMap["can_simple_block:12"] = "can_simple_block.c:77";
	/* <Root>/Constant7 */
	this.urlHashMap["can_simple_block:13"] = "can_simple_block.c:78";
	/* <Root>/Constant8 */
	this.urlHashMap["can_simple_block:14"] = "can_simple_block.c:79";
	/* <Root>/RAppID_564xL_Config */
	this.urlHashMap["can_simple_block:40"] = "msg=&block=can_simple_block:40";
	/* <Root>/Subsystem */
	this.urlHashMap["can_simple_block:16"] = "can_simple_block.c:29";
	/* <Root>/Out1 */
	this.urlHashMap["can_simple_block:29"] = "can_simple_block.h:44";
	/* <Root>/Out2 */
	this.urlHashMap["can_simple_block:30"] = "can_simple_block.h:45";
	/* <Root>/Out3 */
	this.urlHashMap["can_simple_block:31"] = "can_simple_block.h:46";
	/* <Root>/Out4 */
	this.urlHashMap["can_simple_block:32"] = "can_simple_block.h:47";
	/* <Root>/Out5 */
	this.urlHashMap["can_simple_block:33"] = "can_simple_block.c:68&can_simple_block.h:48";
	/* <S1>/In3 */
	this.urlHashMap["can_simple_block:19"] = "can_simple_block.c:34,39&can_simple_block.h:39";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "can_simple_block"};
	this.sidHashMap["can_simple_block"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "can_simple_block:16"};
	this.sidHashMap["can_simple_block:16"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/ADC Config"] = {sid: "can_simple_block:35"};
	this.sidHashMap["can_simple_block:35"] = {rtwname: "<Root>/ADC Config"};
	this.rtwnameHashMap["<Root>/Bus Creator"] = {sid: "can_simple_block:1"};
	this.sidHashMap["can_simple_block:1"] = {rtwname: "<Root>/Bus Creator"};
	this.rtwnameHashMap["<Root>/CAN Config"] = {sid: "can_simple_block:2"};
	this.sidHashMap["can_simple_block:2"] = {rtwname: "<Root>/CAN Config"};
	this.rtwnameHashMap["<Root>/CAN Receive Data Trigger1"] = {sid: "can_simple_block:3"};
	this.sidHashMap["can_simple_block:3"] = {rtwname: "<Root>/CAN Receive Data Trigger1"};
	this.rtwnameHashMap["<Root>/CAN Transmit1"] = {sid: "can_simple_block:4"};
	this.sidHashMap["can_simple_block:4"] = {rtwname: "<Root>/CAN Transmit1"};
	this.rtwnameHashMap["<Root>/CAN_Receive_data1"] = {sid: "can_simple_block:5"};
	this.sidHashMap["can_simple_block:5"] = {rtwname: "<Root>/CAN_Receive_data1"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "can_simple_block:6"};
	this.sidHashMap["can_simple_block:6"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "can_simple_block:7"};
	this.sidHashMap["can_simple_block:7"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "can_simple_block:8"};
	this.sidHashMap["can_simple_block:8"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant3"] = {sid: "can_simple_block:9"};
	this.sidHashMap["can_simple_block:9"] = {rtwname: "<Root>/Constant3"};
	this.rtwnameHashMap["<Root>/Constant4"] = {sid: "can_simple_block:10"};
	this.sidHashMap["can_simple_block:10"] = {rtwname: "<Root>/Constant4"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "can_simple_block:11"};
	this.sidHashMap["can_simple_block:11"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/Constant6"] = {sid: "can_simple_block:12"};
	this.sidHashMap["can_simple_block:12"] = {rtwname: "<Root>/Constant6"};
	this.rtwnameHashMap["<Root>/Constant7"] = {sid: "can_simple_block:13"};
	this.sidHashMap["can_simple_block:13"] = {rtwname: "<Root>/Constant7"};
	this.rtwnameHashMap["<Root>/Constant8"] = {sid: "can_simple_block:14"};
	this.sidHashMap["can_simple_block:14"] = {rtwname: "<Root>/Constant8"};
	this.rtwnameHashMap["<Root>/RAppID_564xL_Config"] = {sid: "can_simple_block:40"};
	this.sidHashMap["can_simple_block:40"] = {rtwname: "<Root>/RAppID_564xL_Config"};
	this.rtwnameHashMap["<Root>/Subsystem"] = {sid: "can_simple_block:16"};
	this.sidHashMap["can_simple_block:16"] = {rtwname: "<Root>/Subsystem"};
	this.rtwnameHashMap["<Root>/Out1"] = {sid: "can_simple_block:29"};
	this.sidHashMap["can_simple_block:29"] = {rtwname: "<Root>/Out1"};
	this.rtwnameHashMap["<Root>/Out2"] = {sid: "can_simple_block:30"};
	this.sidHashMap["can_simple_block:30"] = {rtwname: "<Root>/Out2"};
	this.rtwnameHashMap["<Root>/Out3"] = {sid: "can_simple_block:31"};
	this.sidHashMap["can_simple_block:31"] = {rtwname: "<Root>/Out3"};
	this.rtwnameHashMap["<Root>/Out4"] = {sid: "can_simple_block:32"};
	this.sidHashMap["can_simple_block:32"] = {rtwname: "<Root>/Out4"};
	this.rtwnameHashMap["<Root>/Out5"] = {sid: "can_simple_block:33"};
	this.sidHashMap["can_simple_block:33"] = {rtwname: "<Root>/Out5"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "can_simple_block:17"};
	this.sidHashMap["can_simple_block:17"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "can_simple_block:18"};
	this.sidHashMap["can_simple_block:18"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/In3"] = {sid: "can_simple_block:19"};
	this.sidHashMap["can_simple_block:19"] = {rtwname: "<S1>/In3"};
	this.rtwnameHashMap["<S1>/In4"] = {sid: "can_simple_block:20"};
	this.sidHashMap["can_simple_block:20"] = {rtwname: "<S1>/In4"};
	this.rtwnameHashMap["<S1>/function"] = {sid: "can_simple_block:21"};
	this.sidHashMap["can_simple_block:21"] = {rtwname: "<S1>/function"};
	this.rtwnameHashMap["<S1>/Demux"] = {sid: "can_simple_block:22"};
	this.sidHashMap["can_simple_block:22"] = {rtwname: "<S1>/Demux"};
	this.rtwnameHashMap["<S1>/Mux"] = {sid: "can_simple_block:23"};
	this.sidHashMap["can_simple_block:23"] = {rtwname: "<S1>/Mux"};
	this.rtwnameHashMap["<S1>/Terminator"] = {sid: "can_simple_block:24"};
	this.sidHashMap["can_simple_block:24"] = {rtwname: "<S1>/Terminator"};
	this.rtwnameHashMap["<S1>/Terminator1"] = {sid: "can_simple_block:25"};
	this.sidHashMap["can_simple_block:25"] = {rtwname: "<S1>/Terminator1"};
	this.rtwnameHashMap["<S1>/Terminator2"] = {sid: "can_simple_block:26"};
	this.sidHashMap["can_simple_block:26"] = {rtwname: "<S1>/Terminator2"};
	this.rtwnameHashMap["<S1>/Terminator3"] = {sid: "can_simple_block:27"};
	this.sidHashMap["can_simple_block:27"] = {rtwname: "<S1>/Terminator3"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "can_simple_block:28"};
	this.sidHashMap["can_simple_block:28"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
