function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "D:\\Users\\willi\\Documents\\Git\\LearningFreeRTOS\\StateMach_ert_rtw\\StateMach.c",
	size: 4};
	 this.metricsArray.var["rtM_"] = {file: "D:\\Users\\willi\\Documents\\Git\\LearningFreeRTOS\\StateMach_ert_rtw\\StateMach.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "D:\\Users\\willi\\Documents\\Git\\LearningFreeRTOS\\StateMach_ert_rtw\\StateMach.c",
	size: 3};
	 this.metricsArray.var["rtY"] = {file: "D:\\Users\\willi\\Documents\\Git\\LearningFreeRTOS\\StateMach_ert_rtw\\StateMach.c",
	size: 1};
	 this.metricsArray.fcn["StateMach_initialize"] = {file: "D:\\Users\\willi\\Documents\\Git\\LearningFreeRTOS\\StateMach_ert_rtw\\StateMach.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["StateMach_step"] = {file: "D:\\Users\\willi\\Documents\\Git\\LearningFreeRTOS\\StateMach_ert_rtw\\StateMach.c",
	stack: 4,
	stackTotal: 4};
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
