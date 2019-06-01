ADC_LSB = 3.3/4095;

%%  ACS725-Decimi di ampere
ACS725_gain = 10*ADC_LSB/0.264;

%%  TEMPERATURE-°C
TEMP_EFI_gain = -0.35572*ADC_LSB;
TEMP_EFI_offset = 190.95;

%%  CURRENT_SENSE-mA
SHUNT_RESISTOR_GCU_CURRENT = 0.03;
INA_GAIN = 100;
CURRENT_SENSE_gain = 1000*ADC_LSB/(SHUNT_RESISTOR_GCU_CURRENT * INA_GAIN);

%% GEARMOTOR_IS-Decimi di Ampere
IS_offset = 170*10^-6;
dk_ILIS = 19.5*10^3;
R = 499;
IS_gain = ADC_LSB/R;
IS_to_IL = 10*dk_ILIS;

GainVector = [ACS725_gain, ACS725_gain, ACS725_gain, ACS725_gain, TEMP_EFI_gain, CURRENT_SENSE_gain, IS_gain, IS_gain, ACS725_gain];
OffsetVector = [0, 0, 0, 0, TEMP_EFI_offset, 0, IS_offset, IS_offset, 0];
IS_to_IL_vector = [1, 1, 1, 1, 1, 1, IS_to_IL, IS_to_IL, 1]; 
