function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["GCU_Model_DW"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	size: 123};
	 this.metricsArray.var["GCU_Model_M_"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	size: 285};
	 this.metricsArray.var["GCU_Model_Y"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	size: 1};
	 this.metricsArray.fcn["GCU_CAN"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 9,
	stackTotal: 18};
	 this.metricsArray.fcn["GCU_CAN_Init"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["GCU_CAN_initialize"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_CAN\\GCU_CAN.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["GCU_Model.c:GCU_Model_checkGear"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["GCU_Model.c:GCU_Model_updateData"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	stack: 5,
	stackTotal: 5};
	 this.metricsArray.fcn["GCU_Model_initialize"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	stack: 0,
	stackTotal: 4};
	 this.metricsArray.fcn["GCU_Model_step0"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	stack: 4,
	stackTotal: 54};
	 this.metricsArray.fcn["GCU_Model_step2"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
	stack: 1,
	stackTotal: 19};
	 this.metricsArray.fcn["GCU_timer"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_timer\\GCU_timer.c",
	stack: 8,
	stackTotal: 50};
	 this.metricsArray.fcn["GCU_timer_Init"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_timer\\GCU_timer.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["GCU_timer_initialize"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\slprj\\ert\\GCU_timer\\GCU_timer.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["PackCanUART_Outputs_wrapper"] = {file: "C:\\Users\\SIMONE\\Documents\\Programmi per GCU\\GCU model\\Codice generato\\GCU_Model_ert_rtw\\GCU_Model.c",
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
	 return data; }; 
	 this.codeMetricsSummary = '<a href="GCU_Model_metrics.html">Global Memory: 409(bytes) Maximum Stack: 9(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
