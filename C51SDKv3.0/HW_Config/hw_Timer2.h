#ifndef __HW_TIMER2_H
#define __HW_TIMER2_H


#include "user_config_prj.h"

#ifdef TIMER2_CONFIG

#include "hw_config.h"

#define TIMER2_MODE_CAPTURE  0X00
#define TIMER2_MODE_TIMING   0X01


extern int (*pointer_interupt_timer2)(void *arg);



void Timer2Init(uint mode, uint us, void *callback);
void Timer2Init_NoOpen(uint mode, uint us, void *callback);
void Timer2Open(void);
void Timer2Close(void);
void Timer2Pause(void);
void Timer2Start(void);



#endif /* TIMER2_CONFIG */

#endif /* __HW_TIMER2_H */