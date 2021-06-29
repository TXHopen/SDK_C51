#ifndef __HW_GTIMER_H
#define __HW_GTIMER_H

#include "user_config_prj.h"

#ifdef GTIMER_CONFIG



#include "hw_config.h"


typedef struct _GTimer_Member
{
	void (*member_func_pointer)(void* arg);
	void  *member_func_arg;
} GTimerMember;


typedef struct _GTimer_Queue
{
	uint8_t      GTimer0_s;
	uint8_t      GTimer1_s;
	uint8_t      GTimer2_s;
	uint8_t      GTimer3_s;
	GTimerMember GTimerGroup[4];
} GTimerQueue;




void GTimer_Init (void);
void GTimer_Start (void);
void GTimer_Stop (void);

char GTimer_OBJJoin (void* funcptr, void* funcarg);
char GTimer_OBJRemove (void* funcptr);
char GTimer_OBJRun (void* funcptr);
char GTimer_OBJPause (void* funcptr);

#endif /* GTIMER_CONFIG */

#endif /* __HW_GTIMER_H */