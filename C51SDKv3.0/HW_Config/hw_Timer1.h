#ifndef __HW_TIMER1_H
#define __HW_TIMER1_H


#include "user_config_prj.h"

#ifdef TIMER1_CONFIG
//#ifndef GTIMER_CONFIG

#include "hw_config.h"

#define TIMER1_MODE_0  0X00
#define TIMER1_MODE_1  0X01
#define TIMER1_MODE_2  0X02

extern int (*pointer_interupt_timer1)(void *arg);



void Timer1Init(uint mode, uint us, void *callback);
void Timer1Init_NoOpen(uint mode, uint us, void *callback);
void Timer1Open(void);
void Timer1Close(void);
void Timer1Pause(void);
void Timer1Start(void);


//#endif /* GTIMER_CONFIG */

#endif /* TIMER1_CONFIG */

#endif /* __HW_TIMER1_H */