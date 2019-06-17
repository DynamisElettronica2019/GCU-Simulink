ADC_LSB = 3.3/4095;

%%  ACS725-Decimi di ampere
ACS725_gain = 10/0.264;

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
T = T_amb;
I1_ISx = 0;
I2_ISx = 0;

f_T_p3sig = (1+a_p3sig*(T-T_amb)) / (1+b_p3sig*(T-T_amb));
f_T_m3sig = (1+a_m3sig*(T-T_amb)) / (1+b_m3sig*(T-T_amb));
f_T_lt = (f_T_m3sig + f_T_p3sig*lt_k) / 2;

%%Test condition
I1_Lx = 0; %%A
I2_Lx = 0; %%A
I1_L0 = 0; %%A
I2_L0 = 0; %%A

%%sperimental IS offset value for H_bridge 1
IS1_offset = 0; %%A
%%sperimental IS offset value for H_bridge 2
IS2_offset = 0; %%A
%%dk1_ILIS specific for H-bridge 1 @T=T_amb @I_L = X A
dk1_ILIS_amb = (I1_Lx - I1_L0) / (I1_ISx - IS1_offset);
%%dk2_ILIS specific for h_brisge 2 @T=T_amb @I_L = X A
dk2_ILIS_amb = (I2_Lx - I2_L0) / (I2_ISx - IS2_offset);

%%dkILIS for 1 and 2, after offset, temperature and lifetime compensation
dk1_ILIS_T = dk1_ILIS_amb * f_T_lt;
dk2_ILIS_T = dk2_ILIS_amb * f_T_lt;


%% Offsets and gains
VoltageGainVector = ADC_LSB * ones(1,9);
VoltageOffsetVector = [0, 0, 0, 0, -TEMP_VOLTAGE_OFFSET/1000, 0, 0, 0, 0];
ConversionGainVector = [ACS725_gain, ACS725_gain, ACS725_gain, ACS725_gain,TEMP_GAIN*1000,1000/(SHUNT_RESISTOR_GCU_CURRENT*INA_GAIN), IL_gain, IL_gain, ACS725_gain];
ConversionOffsetVector = [0,0,0,0,-TEMP_OFFSET,0,IL_offset,IL_offset,0];
%GainVector = [ACS725_gain, ACS725_gain, ACS725_gain, ACS725_gain, TEMPERATURE_gain, CURRENT_SENSE_gain, IS_gain, IS_gain, ACS725_gain];
%OffsetVector = [0, 0, 0, 0, TEMPERATURE_offset, 0, IS_offset, IS_offset, 0];
%IS_to_IL_vector = [1, 1, 1, 1, 1, 1, IS_to_IL, IS_to_IL, 1]; 
