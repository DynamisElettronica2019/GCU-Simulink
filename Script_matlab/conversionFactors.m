ADC_LSB = 3.3/4095;
VoltageGainVector = ADC_LSB * ones(1,9);

%%  ACS725-Decimi di ampere
ACS725_gain = 10/0.264;
ACS725_offset = 3.3*0.1;

%%  TEMPERATURE-°C
TEMP_VOLTAGE_OFFSET = 100;  %mV
TEMP_OFFSET = 40;           %°C
TEMP_GAIN = 0.1;            %°C/mV


%%  CURRENT_SENSE-mA
SHUNT_RESISTOR_GCU_CURRENT = 0.03;
INA_GAIN = 100;

%% GEARMOTOR_IS-Decimi di Ampere
%%lifetime coefficient
lt_k = 0.97;
%%chip temperature coefficients
a_p3sig = 3.29e-3;
a_m3sig = 3.43e-3;
b_p3sig = 4.18e-3;
b_m3sig = 4.01e-3;

T_amb = 25; %%°C
R_IS = 470; %%Ohm

%%only for script test
% T = T_amb;
% f_T_p3sig = (1+a_p3sig*(T-T_amb)) / (1+b_p3sig*(T-T_amb));
% f_T_m3sig = (1+a_m3sig*(T-T_amb)) / (1+b_m3sig*(T-T_amb));
% f_T_lt = (f_T_m3sig + f_T_p3sig*lt_k) / 2;

%%Test condition
I1_Lx = 12.4/2.2; %%Vbatt/res = [A]
I2_Lx = 12.4/2.2; %%Vbatt/res = [A]
I1_L0 = 0; %%A
I2_L0 = 0; %%A

%%sperimental IS value for H_bridge 1
I1_ISx = 250e-3/R_IS;
%%sperimental IS value for H_bridge 2
I2_ISx = 225e-3/R_IS;
%%sperimental IS offset value for H_bridge 1
IS1_offset = 89.7143e-3/R_IS; %%A
%%sperimental IS offset value for H_bridge 2
IS2_offset = 64.2143e-3/R_IS; %%A
%%dk1_ILIS specific for H-bridge 1 @T=T_amb @I_L = X A
dk1_ILIS_amb = (I1_Lx - I1_L0) / (I1_ISx - IS1_offset);
%%dk2_ILIS specific for h_brisge 2 @T=T_amb @I_L = X A
dk2_ILIS_amb = (I2_Lx - I2_L0) / (I2_ISx - IS2_offset);

%%dkILIS for 1 and 2, after offset, temperature and lifetime compensation
% dk1_ILIS_T = dk1_ILIS_amb * f_T_lt;
% dk2_ILIS_T = dk2_ILIS_amb * f_T_lt;


%%conversion
% I1_L = dk1_ILIS_T * ((H_B_1_value * ADC_LSB) / R_IS - IS1_offset);
% I2_L = dk2_ILIS_T * ((H_B_2_value * ADC_LSB) / R_IS - IS2_offset);


%% Offsets and gains

VoltageOffsetVector = [ACS725_offset, ACS725_offset, ACS725_offset, ACS725_offset, -TEMP_VOLTAGE_OFFSET/1000, 0, ACS725_offset];
ConversionGainVector = [ACS725_gain, ACS725_gain, ACS725_gain, ACS725_gain, TEMP_GAIN*1000, 1000/(SHUNT_RESISTOR_GCU_CURRENT*INA_GAIN), ACS725_gain];
ConversionOffsetVector = [0,0,0,0,-TEMP_OFFSET,0,0];
