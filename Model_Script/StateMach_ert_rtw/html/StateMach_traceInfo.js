function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/In_Btn */
	this.urlHashMap["StateMach:1"] = "StateMach.c:44&StateMach.h:46";
	/* <Root>/In_DebTime */
	this.urlHashMap["StateMach:15"] = "StateMach.c:45&StateMach.h:47";
	/* <Root>/State_LedBtn */
	this.urlHashMap["StateMach:7"] = "StateMach.c:20,43,128&StateMach.h:39,40,41";
	/* <Root>/Out_Ld */
	this.urlHashMap["StateMach:3"] = "StateMach.c:57,71,82&StateMach.h:52";
	/* <S1>:5 */
	this.urlHashMap["StateMach:7:5"] = "StateMach.c:64,106,120";
	/* <S1>:3 */
	this.urlHashMap["StateMach:7:3"] = "StateMach.c:58,83,99";
	/* <S1>:7 */
	this.urlHashMap["StateMach:7:7"] = "StateMach.c:72,113";
	/* <S1>:4 */
	this.urlHashMap["StateMach:7:4"] = "StateMach.c:54";
	/* <S1>:6 */
	this.urlHashMap["StateMach:7:6"] = "StateMach.c:103";
	/* <S1>:8 */
	this.urlHashMap["StateMach:7:8"] = "StateMach.c:68";
	/* <S1>:11 */
	this.urlHashMap["StateMach:7:11"] = "StateMach.c:79";
	/* <S1>:9 */
	this.urlHashMap["StateMach:7:9"] = "StateMach.c:117";
	/* <S1>:3:1 */
	this.urlHashMap["StateMach:7:3:1"] = "StateMach.c:59,84";
	/* <S1>:8:1 */
	this.urlHashMap["StateMach:7:8:1"] = "StateMach.c:65,66";
	/* <S1>:7:1 */
	this.urlHashMap["StateMach:7:7:1"] = "StateMach.c:73";
	/* <S1>:11:1 */
	this.urlHashMap["StateMach:7:11:1"] = "StateMach.c:76,77";
	/* <S1>:5:1 */
	this.urlHashMap["StateMach:7:5:1"] = "StateMach.c:87,107,121";
	/* <S1>:6:1 */
	this.urlHashMap["StateMach:7:6:1"] = "StateMach.c:100,101";
	/* <S1>:9:1 */
	this.urlHashMap["StateMach:7:9:1"] = "StateMach.c:114,115";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "StateMach"};
	this.sidHashMap["StateMach"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "StateMach:7"};
	this.sidHashMap["StateMach:7"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/In_Btn"] = {sid: "StateMach:1"};
	this.sidHashMap["StateMach:1"] = {rtwname: "<Root>/In_Btn"};
	this.rtwnameHashMap["<Root>/In_DebTime"] = {sid: "StateMach:15"};
	this.sidHashMap["StateMach:15"] = {rtwname: "<Root>/In_DebTime"};
	this.rtwnameHashMap["<Root>/State_LedBtn"] = {sid: "StateMach:7"};
	this.sidHashMap["StateMach:7"] = {rtwname: "<Root>/State_LedBtn"};
	this.rtwnameHashMap["<Root>/Out_Ld"] = {sid: "StateMach:3"};
	this.sidHashMap["StateMach:3"] = {rtwname: "<Root>/Out_Ld"};
	this.rtwnameHashMap["<S1>:5"] = {sid: "StateMach:7:5"};
	this.sidHashMap["StateMach:7:5"] = {rtwname: "<S1>:5"};
	this.rtwnameHashMap["<S1>:3"] = {sid: "StateMach:7:3"};
	this.sidHashMap["StateMach:7:3"] = {rtwname: "<S1>:3"};
	this.rtwnameHashMap["<S1>:7"] = {sid: "StateMach:7:7"};
	this.sidHashMap["StateMach:7:7"] = {rtwname: "<S1>:7"};
	this.rtwnameHashMap["<S1>:4"] = {sid: "StateMach:7:4"};
	this.sidHashMap["StateMach:7:4"] = {rtwname: "<S1>:4"};
	this.rtwnameHashMap["<S1>:6"] = {sid: "StateMach:7:6"};
	this.sidHashMap["StateMach:7:6"] = {rtwname: "<S1>:6"};
	this.rtwnameHashMap["<S1>:8"] = {sid: "StateMach:7:8"};
	this.sidHashMap["StateMach:7:8"] = {rtwname: "<S1>:8"};
	this.rtwnameHashMap["<S1>:11"] = {sid: "StateMach:7:11"};
	this.sidHashMap["StateMach:7:11"] = {rtwname: "<S1>:11"};
	this.rtwnameHashMap["<S1>:9"] = {sid: "StateMach:7:9"};
	this.sidHashMap["StateMach:7:9"] = {rtwname: "<S1>:9"};
	this.rtwnameHashMap["<S1>:3:1"] = {sid: "StateMach:7:3:1"};
	this.sidHashMap["StateMach:7:3:1"] = {rtwname: "<S1>:3:1"};
	this.rtwnameHashMap["<S1>:8:1"] = {sid: "StateMach:7:8:1"};
	this.sidHashMap["StateMach:7:8:1"] = {rtwname: "<S1>:8:1"};
	this.rtwnameHashMap["<S1>:7:1"] = {sid: "StateMach:7:7:1"};
	this.sidHashMap["StateMach:7:7:1"] = {rtwname: "<S1>:7:1"};
	this.rtwnameHashMap["<S1>:11:1"] = {sid: "StateMach:7:11:1"};
	this.sidHashMap["StateMach:7:11:1"] = {rtwname: "<S1>:11:1"};
	this.rtwnameHashMap["<S1>:5:1"] = {sid: "StateMach:7:5:1"};
	this.sidHashMap["StateMach:7:5:1"] = {rtwname: "<S1>:5:1"};
	this.rtwnameHashMap["<S1>:6:1"] = {sid: "StateMach:7:6:1"};
	this.sidHashMap["StateMach:7:6:1"] = {rtwname: "<S1>:6:1"};
	this.rtwnameHashMap["<S1>:9:1"] = {sid: "StateMach:7:9:1"};
	this.sidHashMap["StateMach:7:9:1"] = {rtwname: "<S1>:9:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
