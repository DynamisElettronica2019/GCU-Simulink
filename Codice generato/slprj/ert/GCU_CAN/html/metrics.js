function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["GCU_CAN_DW"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	size: 22};
	 this.metricsArray.var["GCU_CAN_MdlrefDW"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	size: 4};
	 this.metricsArray.fcn["GCU_CAN"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 9,
	stackTotal: 18};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_AAC_COM"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 1,
	stackTotal: 9};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_GEAR_RPM_UPDATE"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 1,
	stackTotal: 9};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_WHEEL_SPEED_UPDATE"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 1,
	stackTotal: 9};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_sendAacCommand"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_sendClutchCommand"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_sendShiftCommand"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 4,
	stackTotal: 8};
	 this.metricsArray.fcn["GCU_CAN.c:GCU_CAN_sendStartEngCommand"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["GCU_CAN_AAC_ExternalValues"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["GCU_CAN_Init"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["GCU_CAN_TractionValue"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["GCU_CAN_initialize"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["UnpackCanUART_Outputs_wrapper"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["ceil"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_roundd"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\_sharedutils\\rt_roundd.c",
	stack: 8,
	stackTotal: 8};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="GCU_CAN_metrics.html">Global Memory: 26(bytes) Maximum Stack: 9(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
