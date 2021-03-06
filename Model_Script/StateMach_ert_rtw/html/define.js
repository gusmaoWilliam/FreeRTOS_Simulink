function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:35,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:72,type:"fcn"};
this.def["rtDW"] = {file: "StateMach_c.html",line:26,type:"var"};
this.def["rtU"] = {file: "StateMach_c.html",line:29,type:"var"};
this.def["rtY"] = {file: "StateMach_c.html",line:32,type:"var"};
this.def["rtM_"] = {file: "StateMach_c.html",line:35,type:"var"};
this.def["rtM"] = {file: "StateMach_c.html",line:36,type:"var"};
this.def["StateMach_step"] = {file: "StateMach_c.html",line:39,type:"fcn"};
this.def["StateMach_initialize"] = {file: "StateMach_c.html",line:132,type:"fcn"};
this.def["RT_MODEL"] = {file: "StateMach_h.html",line:35,type:"type"};
this.def["DW"] = {file: "StateMach_h.html",line:42,type:"type"};
this.def["ExtU"] = {file: "StateMach_h.html",line:48,type:"type"};
this.def["ExtY"] = {file: "StateMach_h.html",line:53,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["StateMach_c.html"] = "../StateMach.c";
	this.html2Root["StateMach_c.html"] = "StateMach_c.html";
	this.html2SrcPath["StateMach_h.html"] = "../StateMach.h";
	this.html2Root["StateMach_h.html"] = "StateMach_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
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
"ert_main_c.html","StateMach_c.html","StateMach_h.html","rtwtypes_h.html"];
