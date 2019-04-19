#ifndef PINDEF_INCLUDE
#define PINDEF_INCLUDE

#include "main.h"

//Definizione pin per GearMotor
#define GPIO_GEAR_MOTOR LED_4_GIALLO_GPIO_Port
#define GPIO_GEAR_MOTOR_B LED_2_GIALLO_GPIO_Port //provvisorio
#define GEAR_MOTOR_IN1 LED_4_GIALLO_Pin
#define GEAR_MOTOR_IN2 LED_2_GIALLO_Pin
#define GEAR_MOTOR_INHIBIT LED_3_GIALLO_Pin

//Definizione pin per EFI
#define EFI_UPCUT_GPIO_PORT   LED_1_GIALLO_GPIO_Port
#define EFI_RPM_LIMITER_GPIO_PORT LED_5_ROSSO_GPIO_Port
#define EFI_UPCUT_Pin   LED_1_GIALLO_Pin
#define EFI_RPM_LIMITER_Pin LED_5_ROSSO_Pin

#endif
