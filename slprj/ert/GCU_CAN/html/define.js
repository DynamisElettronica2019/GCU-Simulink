function CodeDefine() { 
this.def = new Array();
this.def["GCU_CAN_TractionValue"] = {file: "GCU_CAN_c.html",line:109,type:"fcn"};
this.def["GCU_CAN_AAC_ExternalValues"] = {file: "GCU_CAN_c.html",line:123,type:"fcn"};
this.def["GCU_CAN_sendStartEngCommand"] = {file: "GCU_CAN_c.html",line:141,type:"fcn"};
this.def["GCU_CAN_sendAacCommand"] = {file: "GCU_CAN_c.html",line:157,type:"fcn"};
this.def["GCU_CAN_sendShiftCommand"] = {file: "GCU_CAN_c.html",line:175,type:"fcn"};
this.def["GCU_CAN_sendClutchCommand"] = {file: "GCU_CAN_c.html",line:197,type:"fcn"};
this.def["GCU_CAN_WHEEL_SPEED_UPDATE"] = {file: "GCU_CAN_c.html",line:215,type:"fcn"};
this.def["GCU_CAN_AAC_COM"] = {file: "GCU_CAN_c.html",line:285,type:"fcn"};
this.def["GCU_CAN_GEAR_RPM_UPDATE"] = {file: "GCU_CAN_c.html",line:354,type:"fcn"};
this.def["GCU_CAN_Init"] = {file: "GCU_CAN_c.html",line:424,type:"fcn"};
this.def["GCU_CAN"] = {file: "GCU_CAN_c.html",line:437,type:"fcn"};
this.def["GCU_CAN_initialize"] = {file: "GCU_CAN_c.html",line:766,type:"fcn"};
this.def["RT_MODEL_GCU_CAN_T"] = {file: "GCU_CAN_h.html",line:33,type:"type"};
this.def["aac_values"] = {file: "GCU_CAN_h.html",line:42,type:"type"};
this.def["DW_TractionValue_GCU_CAN_T"] = {file: "GCU_CAN_h.html",line:49,type:"type"};
this.def["DW_AAC_ExternalValues_GCU_CAN_T"] = {file: "GCU_CAN_h.html",line:54,type:"type"};
this.def["DW_GCU_CAN_f_T"] = {file: "GCU_CAN_h.html",line:67,type:"type"};
this.def["MdlrefDW_GCU_CAN_T"] = {file: "GCU_CAN_h.html",line:77,type:"type"};
this.def["rt_roundd"] = {file: "../../_sharedutils/html/rt_roundd_c.html",line:19,type:"fcn"};
this.def["int8_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:46,type:"type"};
this.def["uint8_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:47,type:"type"};
this.def["int16_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:48,type:"type"};
this.def["uint16_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:49,type:"type"};
this.def["int32_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:50,type:"type"};
this.def["uint32_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:51,type:"type"};
this.def["int64_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:52,type:"type"};
this.def["uint64_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:53,type:"type"};
this.def["real32_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:54,type:"type"};
this.def["real64_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:55,type:"type"};
this.def["real_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:61,type:"type"};
this.def["time_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:62,type:"type"};
this.def["boolean_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:63,type:"type"};
this.def["int_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:64,type:"type"};
this.def["uint_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:65,type:"type"};
this.def["ulong_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:66,type:"type"};
this.def["ulonglong_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:70,type:"type"};
this.def["pointer_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:91,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["GCU_CAN_c.html"] = "../GCU_CAN.c";
	this.html2Root["GCU_CAN_c.html"] = "GCU_CAN_c.html";
	this.html2SrcPath["GCU_CAN_h.html"] = "../GCU_CAN.h";
	this.html2Root["GCU_CAN_h.html"] = "GCU_CAN_h.html";
	this.html2SrcPath["rt_roundd_c.html"] = "../rt_roundd.c";
	this.html2Root["rt_roundd_c.html"] = "../../_sharedutils/html/rt_roundd_c.html";
	this.html2SrcPath["rt_roundd_h.html"] = "../rt_roundd.h";
	this.html2Root["rt_roundd_h.html"] = "../../_sharedutils/html/rt_roundd_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "../../_sharedutils/html/rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"GCU_CAN_c.html","GCU_CAN_h.html","rt_roundd_c.html","rt_roundd_h.html","rtwtypes_h.html"];
