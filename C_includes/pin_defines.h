#ifndef PINDEF_INCLUDE
#define PINDEF_INCLUDE

#include "main.h"
//se il nome del pin e della define coincidono, commentare la riga della define
//(segnandosi però che il nome è uguale)

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

//Definizione pin per livello olio
#define L_OIL_GPIO_Port UserButton_GPIO_Port
#define L_OIL_Pin       UserButton_Pin

//Definizione pin per EEPROM
#define hi2cEeprom hi2c1
#define EEPROM_WP_GPIO_Port     GreenLed_GPIO_Port
#define EEPROM_WP_Pin           GreenLed_Pin



//Definizione pwm per clutch
#define TIM_CLUTCH_CHANNEL TIM_CHANNEL_4
#define hClutchTim htim4
#define CCR_CLUTCH CCR4

//Definizione pwm per buzzer
#define TIM_BUZZER_CHANNEL TIM_CHANNEL_4
#define hBuzzerTim htim4
#define CCR_BUZZER CCR4

//Definizione pwm per pompa benzina
#define TIM_PUMP_CHANNEL  TIM_CHANNEL_1
#define hPumpTim htim1
#define CCR_PUMP CCR1

//Definizione pwm per stop light
#define TIM_STOP_CTRL_CHANNEL	TIM_CHANNEL_4
#define hStopTim htim1
#define CCR_STOP_CTRL	CCR4

//Definizione uart utilizzata per debug
#define huartDebug huart3

//Definizione del CAN utilizzato
#define hcan_active hcan1

//Definizione timer utilizzato per logica
#define htim_1khz htim2
#define TIM_1KHZ TIM2

//Definizione ADC per sensori
#define hadc_sensors hadc1
#define ADC_SENSORS ADC1

//Definizione pin per KEYON
#define KEY_ON_GPIO_Port	KEY_CTRL_GPIO_Port
#define KEY_ON_Pin			KEY_CTRL_Pin

//Definizione led ausiliari su scheda
//#define RedLed_GPIO_Port RedLed_GPIO_Port 
//#define BlueLed_GPIO_Port BlueLed_GPIO_Port
//#define GreenLed_GPIO_Port GreenLed_GPIO_Port
//#define RedLed_Pin RedLed_Pin
//#define BlueLed_Pin BlueLed_Pin
//#define GreenLed_Pin GreenLed_Pin


#endif
