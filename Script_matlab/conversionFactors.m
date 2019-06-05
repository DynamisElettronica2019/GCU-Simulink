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
IS_offset = 170*10^-6;
dk_ILIS = 19.5*10^3;
R_gearMotor = 470;
IL_gain = 10*dk_ILIS/R_gearMotor;
IL_offset = -10*dk_ILIS*IS_offset;

VoltageGainVector = ADC_LSB * ones(1,9);
VoltageOffsetVector = [0, 0, 0, 0, -TEMP_VOLTAGE_OFFSET/1000, 0, 0, 0, 0];
ConversionGainVector = [ACS725_gain, ACS725_gain, ACS725_gain, ACS725_gain,TEMP_GAIN*1000,1000/(SHUNT_RESISTOR_GCU_CURRENT*INA_GAIN), IL_gain, IL_gain, ACS725_gain];
ConversionOffsetVector = [0,0,0,0,-TEMP_OFFSET,0,IL_offset,IL_offset,0];
%GainVector = [ACS725_gain, ACS725_gain, ACS725_gain, ACS725_gain, TEMPERATURE_gain, CURRENT_SENSE_gain, IS_gain, IS_gain, ACS725_gain];
%OffsetVector = [0, 0, 0, 0, TEMPERATURE_offset, 0, IS_offset, IS_offset, 0];
%IS_to_IL_vector = [1, 1, 1, 1, 1, 1, IS_to_IL, IS_to_IL, 1]; 
