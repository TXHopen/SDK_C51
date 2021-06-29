#ifndef __HW_TIMER0_H
#define __HW_TIMER0_H


#include "user_config_prj.h"

#ifdef TIMER0_CONFIG
//#ifndef GTIMER_CONFIG

#include "hw_config.h"

#define TIMER0_MODE_0  0X00
#define TIMER0_MODE_1  0X01
#define TIMER0_MODE_2  0X02
#define TIMER0_MODE_3  0X03

extern int (*pointer_interupt_timer0)(void *arg);


void Timer0Init(uint mode, uint us, void *callback);

void Timer0Init_NoOpen(uint mode, uint us, void *callback);
void Timer0Open(void);
void Timer0Close(void);


//#endif /* GTIMER_CONFIG */

#endif /* TIMER0_CONFIG */

#endif /* __HW_TIMER0_H */