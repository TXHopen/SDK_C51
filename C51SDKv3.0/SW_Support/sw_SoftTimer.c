#include "sw_SoftTimer.h"

#ifdef SW_SOFTTIMER_CONFIG


#ifndef GTIMER_CONFIG
#define GTIMER_CONFIG
#endif /* GTIMER_CONFIG */





static char TimerOBJBUDY_Findinvain(void);
static char TimerOBJBUDY_push(uchar status);
static char TimerOBJBUDY_pop(uchar status);
/* ------------------------------------------------------------ */



static SOFTTimerOBJBUDY   TimerOBJBUDY;


/* ------------------------------------------------------------ */


int SOFTTimer_callback (void *arg)
{
	void *ptr = arg;

	uchar i = 0;
	
	//SOFTTimer_Stop();

	if (TimerOBJBUDY.OBJStatus_0 == 2) {
		TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_remain_ms -= 1;
		if (TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_remain_ms == 0) {
			TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_remain_ms  = TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_ms;
			TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_func(TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_arg);
		}
	}

	if (TimerOBJBUDY.OBJStatus_1 == 2) {
		TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_remain_ms -= 1;
		if (TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_remain_ms == 0) {
			TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_remain_ms  = TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_ms;
			TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_func(TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_arg);
		}
	}

	if (TimerOBJBUDY.OBJStatus_2 == 2) {
		TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_remain_ms -= 1;
		if (TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_remain_ms == 0) {
			TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_remain_ms  = TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_ms;
			TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_func(TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_arg);
		}
	}

	if (TimerOBJBUDY.OBJStatus_3 == 2) {
		TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_remain_ms -= 1;
		if (TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_remain_ms == 0) {
			TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_remain_ms  = TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_ms;
			TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_func(TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_arg);
		}
	}

	//SOFTTimer_Start();
	

	return 0;
}



/* ------------------------------------------------------------ */

void SOFTTimer_Init(void)
{
	
	memset (&TimerOBJBUDY, 0, sizeof(TimerOBJBUDY));
	//TimerOBJBUDY.budy_status = 0x00;
	GTimer_OBJJoin(SOFTTimer_callback, NULL);

}

void SOFTTimer_Start()
{

	GTimer_OBJRun (SOFTTimer_callback);

}

void SOFTTimer_Stop()
{

	GTimer_OBJPause (SOFTTimer_callback);

}

char SOFTTimer_OBJJoin(uint timer_ms, void* callback, void* arg)
{
	char status = TimerOBJBUDY_Findinvain();
	if (status < 0) {
		return -1;
	} else {
		TimerOBJBUDY.TimerOBJ[status].SoftTimer_obj_ms        = timer_ms/10;
		TimerOBJBUDY.TimerOBJ[status].SoftTimer_obj_remain_ms = timer_ms/10;
		TimerOBJBUDY.TimerOBJ[status].SoftTimer_obj_func      = callback;
		TimerOBJBUDY.TimerOBJ[status].SoftTimer_obj_arg       = arg;

		TimerOBJBUDY_push(status);
	}
	return 0;
}

char SOFTTimer_OBJRemove(void* callback)
{
	
	if (TimerOBJBUDY.OBJStatus_0 != 0) {
		if (TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY_pop(0);
			return 0;
		}
	}
	if (TimerOBJBUDY.OBJStatus_1 != 0) {
		if (TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY_pop(1);
			return 1;
		}
	}
	if (TimerOBJBUDY.OBJStatus_2 != 0) {
		if (TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY_pop(2);
			return 2;
		}
	}
	if (TimerOBJBUDY.OBJStatus_3 != 0) {
		if (TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY_pop(3);
			return 3;
		}
	}

	return -1;
}

char SOFTTimer_OBJPause(void* callback)
{
	if (TimerOBJBUDY.OBJStatus_0 == 2) {
		if (TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_0 = 1;
			return 0;
		}
	}
	if (TimerOBJBUDY.OBJStatus_1 == 2) {
		if (TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_1 = 1;
			return 1;
		}
	}
	if (TimerOBJBUDY.OBJStatus_2 == 2) {
		if (TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_2 = 1;
			return 2;
		}
	}
	if (TimerOBJBUDY.OBJStatus_3 == 2) {
		if (TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_3 = 1;
			return 3;
		}
	}
	
	return -1;
}

char SOFTTimer_OBJRun(void* callback)
{
	if (TimerOBJBUDY.OBJStatus_0 == 1) {
		if (TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_0 = 2;
			return 0;
		}
	}
	if (TimerOBJBUDY.OBJStatus_1 == 1) {
		if (TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_1 = 2;
			return 1;
		}
	}
	if (TimerOBJBUDY.OBJStatus_2 == 1) {
		if (TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_2 = 2;
			return 2;
		}
	}
	if (TimerOBJBUDY.OBJStatus_3 == 1) {
		if (TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_func == callback ) {
			TimerOBJBUDY.OBJStatus_3 = 2;
			return 3;
		}
	}
	
	return -1;
}


/* ------------------------------------------------------------ */

static char TimerOBJBUDY_Findinvain(void)
{
	uchar status = -1;

	if (TimerOBJBUDY.OBJStatus_0 == 0) {
		status = 0;
	} else if (TimerOBJBUDY.OBJStatus_1 == 0) {
		status = 1;
	} else if (TimerOBJBUDY.OBJStatus_2 == 0) {
		status = 2;
	} else if (TimerOBJBUDY.OBJStatus_3 == 0) {
		status = 3;
	} else {
		status = -1;
	}

	return status;
}

static char TimerOBJBUDY_push(uchar status)
{

	switch (status)
	{
		case 0:TimerOBJBUDY.OBJStatus_0 = 1;break;
		case 1:TimerOBJBUDY.OBJStatus_1 = 1;break;
		case 2:TimerOBJBUDY.OBJStatus_2 = 1;break;
		case 3:TimerOBJBUDY.OBJStatus_3 = 1;break;
		default:break;
	}

	return 0;
}

static char TimerOBJBUDY_pop(uchar status)
{
	
	switch (status)
	{
		case 0:TimerOBJBUDY.OBJStatus_0 = 0;
		       TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_func = NULL;
		       TimerOBJBUDY.TimerOBJ[0].SoftTimer_obj_arg  = NULL;
		       break;
		case 1:TimerOBJBUDY.OBJStatus_1 = 0;
		       TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_func = NULL;
		       TimerOBJBUDY.TimerOBJ[1].SoftTimer_obj_arg  = NULL;
		       break;
		case 2:TimerOBJBUDY.OBJStatus_2 = 0;
		       TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_func = NULL;
		       TimerOBJBUDY.TimerOBJ[2].SoftTimer_obj_arg  = NULL;
		       break;
		case 3:TimerOBJBUDY.OBJStatus_3 = 0;
		       TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_func = NULL;
		       TimerOBJBUDY.TimerOBJ[3].SoftTimer_obj_arg  = NULL;
		       break;
		default:break;
	}

	return 0;
}


/* ------------------------------------------------------------ */

#endif /* SW_SOFTTIMER_CONFIG */