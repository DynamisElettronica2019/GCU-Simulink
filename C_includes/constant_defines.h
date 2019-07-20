#ifndef CONST_DEF_INCLUDE
#define CONST_DEF_INCLUDE

//Dimensione dei vettori
#define UART_SENT_DATA_WIDTH    		40  //dimensione dei dati inviati via seriale dal modello
#define UART_SENT_EEPROM_DATA_WIDTH 19 	//dimensione dei dati inviati via serial al programma eeprom
#define I2C_SENT_EEPROM_DATA_WIDTH 	16	//dimensione dei dati da scrivere via i2c su eeprom
#define CAN_SENT_DATA_WIDTH     		8   //dimensione del vettore dei dati inviati CAN
#define ADC_DATA_SIZE           		9   //numero di segnali campionati dall'adc
#define UART_READ_DATA_WIDTH    		10  //dimensione del vettore dei dati letto da seriale
#define UART_READ_EEPROM_DATA_WIDTH 20 	//dimensione del vettore dei dati letto da seriale per eeprom
#define CAN_READ_DATA_WIDTH     		8   //dimensione del vettore dei dati letti CAN

//Periodi 
#define SEND_SERIAL_DATA_PERIOD 50     //periodo di invio dei dati su seriale 
#define SEND_CAN_DATA_PERIOD    10
#define TOGGLE_LED_PERIOD       500   //periodo di accensione del led
#define ADC_PERIOD              1           //periodo di campionamento dei sensori

//Modalità di lettura dei dati di input
#define UART_READ_MODE  1
#define CAN_READ_MODE   2
#define DEMO_READ_MODE  3

//Filtri impostati per il CAN
#define CAN_FILTER_NUMBER   14

//Set e Reset del comando KeyOn, upCut e rpmLimiter
#define KEY_ON_SET   1
#define KEY_ON_RESET 0
#define UPCUT_SET 	 0
#define UPCUT_RESET  1
#define RPM_SET      0
#define RPM_RESET    1

//Define delle modalità di guida
//#define BOARD_DEBUG_MODE   0
//#define DEBUG_MODE		   1
//#define SETTINGS_MODE	   2
#define SKIDPAD_MODE	   3
#define AUTOX_MODE         2
#define ACCELERATION_MODE  1
#define ENDURANCE_MODE	   0

//Define di accelerationFB
#define ACC_OFF 			0
#define ACC_READY 			1
#define ACC_GO			    2

//Define dei comandi autoX
#define AUTOX_DEFAULT       0
#define AUTOX_READY         1
#define AUTOX_GO            2

//Define dei comandi antistall
#define ANTISTALL_ON        1
#define ANTISTALL_OFF       0

//Velocità di uscita da release
#define RELEASE_END_SPEED   10
#define SLIP_TARGET         7

//Retry logic
#define RETRY_DELAY         350

#endif
