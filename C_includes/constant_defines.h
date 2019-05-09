#ifndef CONST_DEF_INCLUDE
#define CONST_DEF_INCLUDE


#define UART_SENT_DATA_WIDTH 40 //dimensione dei dati inviati via seriale dal modello
#define CAN_SENT_DATA_WIDTH 8
#define ADC_DATA_SIZE 9  //numero di segnali campionati dall'adc
#define UART_READ_DATA_WIDTH 10  //dimensione del vettore dei dati letto da seriale
#define CAN_READ_DATA_WIDTH 8

#define SEND_DATA_PERIOD 50     //periodo di invio dei dati su seriale 
#define TOGGLE_LED_PERIOD 500   //periodo di accensione del led


//modalit� di lettura dei dati di input
#define UART_READ_MODE 1
#define CAN_READ_MODE 2
#define DEMO_READ_MODE 3




#endif