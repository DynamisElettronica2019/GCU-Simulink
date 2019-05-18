#ifndef CONST_DEF_INCLUDE
#define CONST_DEF_INCLUDE

//Dimensione dei vettori
#define UART_SENT_DATA_WIDTH    40  //dimensione dei dati inviati via seriale dal modello
#define CAN_SENT_DATA_WIDTH     8    //dimensione del vettore dei dati inviati CAN
#define ADC_DATA_SIZE           9          //numero di segnali campionati dall'adc
#define UART_READ_DATA_WIDTH    10  //dimensione del vettore dei dati letto da seriale
#define CAN_READ_DATA_WIDTH     8    //dimensione del vettore dei dati letti CAN

//Periodi 
#define SEND_SERIAL_DATA_PERIOD 50     //periodo di invio dei dati su seriale 
#define SEND_CAN_DATA_PERIOD    50
#define TOGGLE_LED_PERIOD       500   //periodo di accensione del led
#define ADC_PERIOD              10           //periodo di campionamento dei sensori

//Modalità di lettura dei dati di input
#define UART_READ_MODE  2
#define CAN_READ_MODE   1
#define DEMO_READ_MODE  3

//Filtri impostati per il CAN
#define CAN_FILTER_NUMBER   14

//Define delle modalità di guida
//#define BOARD_DEBUG_MODE   0
//#define DEBUG_MODE		 1
//#define SETTINGS_MODE      2
#define SKIDPAD_MODE         3
#define AUTOX_MODE           4
#define ACCELERATION_MODE    5
#define ENDURANCE_MODE       6

//Define di accelerationFB
#define ACC_OFF             0
#define ACC_READY 			1
#define ACC_GO			    2



#endif
