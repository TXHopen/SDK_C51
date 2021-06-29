#include "hw_Gtimer.h"

#ifdef GTIMER_CONFIG


/* ------------------------------------------------------------ */

static GTimerQueue   GTimerOBJ;




static char GTimer_function (void *arg) 
{
	void *ptr = arg;

	if (GTimerOBJ.GTimer0_s == 2) {
		GTimerOBJ.GTimerGroup[0].member_func_pointer (GTimerOBJ.GTimerGroup[0].member_func_arg);
	}
	if (GTimerOBJ.GTimer1_s == 2) {
		GTimerOBJ.GTimerGroup[1].member_func_pointer (GTimerOBJ.GTimerGroup[1].member_func_arg);
	}
	if (GTimerOBJ.GTimer2_s == 2) {
		GTimerOBJ.GTimerGroup[2].member_func_pointer (GTimerOBJ.GTimerGroup[2].member_func_arg);
	}
	if (GTimerOBJ.GTimer3_s == 2) {
		GTimerOBJ.GTimerGroup[3].member_func_pointer (GTimerOBJ.GTimerGroup[3].member_func_arg);
	}

	return 0;
}





static char GTimerOBJ_Findinvain(void);
static char GTimerOBJ_push(uchar status);
static char GTimerOBJ_pop(uchar status);
/* ------------------------------------------------------------ */

void GTimer_Init (void)
{
	memset (&GTimerOBJ, 0, sizeof(GTimerOBJ));
	GTimerOBJ.GTimer0_s = 0;
	GTimerOBJ.GTimer1_s = 0;
	GTimerOBJ.GTimer2_s = 0;
	GTimerOBJ.GTimer3_s = 0;
	Timer2Init(TIMER2_MODE_TIMING, 10000, GTimer_function);
}

void GTimer_Start (void)
{
	
}

void GTimer_Stop (void)
{
	
}





char GTimer_OBJJoin (void* funcptr, void* funcarg)
{
	char status = -1;
	status = GTimerOBJ_Findinvain ();
	if (status < 0) {
		return -1;
	} else {
		GTimerOBJ.GTimerGroup[status].member_func_pointer = funcptr;
		GTimerOBJ.GTimerGroup[status].member_func_arg     = funcarg;
		GTimerOBJ_push (status);
	}

	return 0;
}



char GTimer_OBJRemove (void* funcptr)
{
	if (GTimerOBJ.GTimer0_s != 0) {
		if (GTimerOBJ.GTimerGroup[0].member_func_pointer == funcptr) {
			GTimerOBJ_pop (0);
			return 0;
		}
	}
	if (GTimerOBJ.GTimer1_s != 0) {
		if (GTimerOBJ.GTimerGroup[1].member_func_pointer == funcptr) {
			GTimerOBJ_pop (1);
			return 1;
		}
	}
	if (GTimerOBJ.GTimer2_s != 0) {
		if (GTimerOBJ.GTimerGroup[2].member_func_pointer == funcptr) {
			GTimerOBJ_pop (2);
			return 2;
		}
	}
	if (GTimerOBJ.GTimer3_s != 0) {
		if (GTimerOBJ.GTimerGroup[3].member_func_pointer == funcptr) {
			GTimerOBJ_pop (3);
			return 3;
		}
	}
	return -1;
}


char GTimer_OBJRun (void* funcptr)
{
	if (GTimerOBJ.GTimer0_s == 1) {
		if (GTimerOBJ.GTimerGroup[0].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer0_s = 2;
			return 0;
		}
	}
	if (GTimerOBJ.GTimer1_s == 1) {
		if (GTimerOBJ.GTimerGroup[1].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer1_s = 2;
			return 1;
		}
	}
	if (GTimerOBJ.GTimer2_s == 1) {
		if (GTimerOBJ.GTimerGroup[2].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer2_s = 2;
			return 2;
		}
	}
	if (GTimerOBJ.GTimer3_s == 1) {
		if (GTimerOBJ.GTimerGroup[3].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer3_s = 2;
			return 3;
		}
	}
	
	return -1;
}

char GTimer_OBJPause (void* funcptr)
{
	if (GTimerOBJ.GTimer0_s == 2) {
		if (GTimerOBJ.GTimerGroup[0].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer0_s = 1;
			return 0;
		}
	}
	if (GTimerOBJ.GTimer1_s == 2) {
		if (GTimerOBJ.GTimerGroup[1].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer1_s = 1;
			return 1;
		}
	}
	if (GTimerOBJ.GTimer2_s == 2) {
		if (GTimerOBJ.GTimerGroup[2].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer2_s = 1;
			return 2;
		}
	}
	if (GTimerOBJ.GTimer3_s == 2) {
		if (GTimerOBJ.GTimerGroup[3].member_func_pointer == funcptr) {
			GTimerOBJ.GTimer3_s = 1;
			return 3;
		}
	}
	
	return -1;
}




/* ------------------------------------------------------------ */

static char GTimerOBJ_Findinvain(void)
{
	uchar status = -1;

	if (GTimerOBJ.GTimer0_s == 0) {
		status = 0;
	} else if (GTimerOBJ.GTimer1_s == 0) {
		status = 1;
	} else if (GTimerOBJ.GTimer2_s == 0) {
		status = 2;
	} else if (GTimerOBJ.GTimer3_s == 0) {
		status = 3;
	} else {
		status = -1;
	}

	return status;
}

static char GTimerOBJ_push(uchar status)
{

	switch (status)
	{
		case 0:GTimerOBJ.GTimer0_s = 1;break;
		case 1:GTimerOBJ.GTimer1_s = 1;break;
		case 2:GTimerOBJ.GTimer2_s = 1;break;
		case 3:GTimerOBJ.GTimer3_s = 1;break;
		default:break;
	}

	return 0;
}

static char GTimerOBJ_pop(uchar status)
{
	
	switch (status)
	{
		case 0:GTimerOBJ.GTimer0_s = 0;
		       GTimerOBJ.GTimerGroup[0].member_func_pointer = NULL;
		       GTimerOBJ.GTimerGroup[0].member_func_arg     = NULL;
			   break;
		case 1:GTimerOBJ.GTimer1_s = 0;
		       GTimerOBJ.GTimerGroup[1].member_func_pointer = NULL;
		       GTimerOBJ.GTimerGroup[1].member_func_arg     = NULL;
			   break;
		case 2:GTimerOBJ.GTimer2_s = 0;
		       GTimerOBJ.GTimerGroup[2].member_func_pointer = NULL;
		       GTimerOBJ.GTimerGroup[2].member_func_arg     = NULL;
			   break;
		case 3:GTimerOBJ.GTimer3_s = 0;
		       GTimerOBJ.GTimerGroup[3].member_func_pointer = NULL;
		       GTimerOBJ.GTimerGroup[3].member_func_arg     = NULL;
			   break;
		default:break;
	}

	return 0;
}













#endif /* GTIMER_CONFIG */