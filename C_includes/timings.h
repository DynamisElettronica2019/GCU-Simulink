#ifndef TIMINGS_H
#define TIMINGS_H

#define TIMINGS_NUM 23

#define DEFAULT_DELAY       20
#define DEFAULT_UP_REBOUND  15
#define DEFAULT_UP_BRAKE    20
#define DEFAULT_UP_PUSH_1_2 115
#define DEFAULT_UP_PUSH_2_3 100
#define DEFAULT_UP_PUSH_3_4 100
#define DEFAULT_UP_PUSH_4_5 100
     //down
#define DEFAULT_CLUTCH      70
#define DEFAULT_DN_PUSH     100
#define DEFAULT_DN_BRAKE    15
#define DEFAULT_DN_REBOUND  20
     //neutral
#define DEFAULT_NT_CLUTCH_DELAY 20
#define DEFAULT_NT_REBOUND_1_N  15
#define DEFAULT_NT_REBOUND_2_N  15
#define DEFAULT_NT_BRAKE_1_N    35
#define DEFAULT_NT_BRAKE_2_N    35
#define DEFAULT_NT_PUSH_1_N     22
#define DEFAULT_NT_PUSH_2_N     25
#define DEFAULT_NT_CLUTCH_1_N   300
#define DEFAULT_NT_CLUTCH_2_N   300
     //Multiple tries
#define DEFAULT_DOWN_TIME_CHECK 500
#define DEFAULT_UP_TIME_CHECK   500
#define DEFAULT_MAX_TRIES       2

typedef enum 
{
  //Neutral 1->N
  NT_PUSH_1_N,
  NT_CLUTCH_1_N,
  NT_REBOUND_1_N,
  NT_BRAKE_1_N,
  
  //Neutral 2->N
  NT_PUSH_2_N,
  NT_CLUTCH_2_N,
  NT_REBOUND_2_N,
  NT_BRAKE_2_N,
  
  //Downshift
  DN_PUSH,
  CLUTCH,
  DN_REBOUND,
  DN_BRAKE,
  
  //Upshift gear specific
  UP_PUSH_1_2,
  UP_PUSH_2_3,
  UP_PUSH_3_4,
  UP_PUSH_4_5,
  
  //Up generics
  DELAY,
  UP_REBOUND,
  UP_BRAKE,
  //neutral
  NT_CLUTCH_DELAY,

  //Multiple tries
  DOWN_TIME_CHECK,
  UP_TIME_CHECK,
  MAX_TRIES,

  //Keep Last
  TIMES_LAST
}time_id;

#endif
   