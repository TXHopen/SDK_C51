#ifndef __SW_SOFTTIMER_H
#define __SW_SOFTTIMER_H


#include "user_config_prj.h"

#ifdef SW_SOFTTIMER_CONFIG

#include "hw_config.h"




typedef struct SOFTTimer
{
	uint SoftTimer_obj_ms;
	uint SoftTimer_obj_remain_ms;
	void (*SoftTimer_obj_func)(void *arg);
	void *SoftTimer_obj_arg;
} SOFTTimerOBJ;


typedef struct SOFTTimerBUDY
{
	uchar         OBJStatus_0;
	uchar         OBJStatus_1;
	uchar         OBJStatus_2;
	uchar         OBJStatus_3;
	SOFTTimerOBJ  TimerOBJ[4];
} SOFTTimerOBJBUDY;



extern void (*SoftTimer_obj_func)(void *arg);
                                                        
void SOFTTimer_Init();
void SOFTTimer_Start();
void SOFTTimer_Stop();
char SOFTTimer_OBJJoin(uint timer_ms, void* callback, void* arg);
char SOFTTimer_OBJRemove(void* callback);
char SOFTTimer_OBJPause(void* callback);
char SOFTTimer_OBJRun(void* callback);


#endif /* SW_SOFTTIMER_CONFIG */

#endif /* __SW_SOFTTIMER_H */
