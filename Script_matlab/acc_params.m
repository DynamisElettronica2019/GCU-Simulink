classdef acc_params < Simulink.IntEnumType
 enumeration
    RAMP_START       (0)
    RAMP_END         (1)
    RAMP_TIME        (2)
    %% MANTAIN THE ORDER!!!!!!!!!
    RPM_LIMIT_1_2    (3)
    RPM_LIMIT_2_3    (4)
    RPM_LIMIT_3_4    (5)
    RPM_LIMIT_4_5    (6)
    SPEED_LIMIT_1_2  (7)
    SPEED_LIMIT_2_3  (8)
    SPEED_LIMIT_3_4  (9)
    SPEED_LIMIT_4_5  (10)
    TPS_START_LIMIT  (11)
    END_GEAR         (12)
 end    
end