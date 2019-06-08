classdef autoX_params < Simulink.IntEnumType
 enumeration
    AUTOX_RAMP_START       (0)
    AUTOX_RAMP_END         (1)
    AUTOX_RAMP_TIME        (2)
    %% MANTAIN THE ORDER!!!!!!!!!
    AUTOX_RPM_LIMIT_1_2    (3)
    AUTOX_RPM_LIMIT_2_3    (4)
    AUTOX_RPM_LIMIT_3_4    (5)
    AUTOX_RPM_LIMIT_4_5    (6)
    AUTOX_SPEED_LIMIT_1_2  (7)
    AUTOX_SPEED_LIMIT_2_3  (8)
    AUTOX_SPEED_LIMIT_3_4  (9)
    AUTOX_SPEED_LIMIT_4_5  (10)
    AUTOX_TPS_START_LIMIT  (11)
    AUTOX_END_GEAR         (12)
 end    
end