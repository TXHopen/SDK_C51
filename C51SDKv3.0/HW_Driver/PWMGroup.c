#include "PWMGroup.h"

#ifdef PWMGROUP_CONFIG








static char PWMGroupOBJ_Findinvain(void);
static char PWMGroupOBJ_push(uchar status);
static char PWMGroupOBJ_pop(uchar status);





PWMGROUP_Queue    PWMGroup_OBJ;


static int PWMGroup_function (void *arg) 
{
	void *ptr = arg;
	if (PWMGroup_OBJ.PWMGROUP_S_0 == 2) {
		PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS++;
		if (PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS == PWMGroup_OBJ.PWMGROUP_Arr[0].OutPosCYC) {
			io_ctrl_set_low (PWMGroup_OBJ.PWMGROUP_Arr[0].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[0].OutBit);
		} else if (PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS == 100) {
			io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[0].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[0].OutBit);
			PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS = 0;
		}
	}
	if (PWMGroup_OBJ.PWMGROUP_S_1 == 2) {
		PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS++;
		if (PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS == PWMGroup_OBJ.PWMGROUP_Arr[1].OutPosCYC) {
			io_ctrl_set_low (PWMGroup_OBJ.PWMGROUP_Arr[1].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[1].OutBit);
		} else if (PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS == 100) {
			io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[1].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[1].OutBit);
			PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS = 0;
		}
	}
	if (PWMGroup_OBJ.PWMGROUP_S_2 == 2) {
		PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS++;
		if (PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS == PWMGroup_OBJ.PWMGROUP_Arr[2].OutPosCYC) {
			io_ctrl_set_low (PWMGroup_OBJ.PWMGROUP_Arr[2].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[2].OutBit);
		} else if (PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS == 100) {
			io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[2].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[2].OutBit);
			PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS = 0;
		}
	}
	if (PWMGroup_OBJ.PWMGROUP_S_3 == 2) {
		PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS++;
		if (PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS == PWMGroup_OBJ.PWMGROUP_Arr[3].OutPosCYC) {
			io_ctrl_set_low (PWMGroup_OBJ.PWMGROUP_Arr[3].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[3].OutBit);
		} else if (PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS == 100) {
			io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[3].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[3].OutBit);
			PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS = 0;
		}
	}
	
	return 0;
}


char PWMGroup_Init (void)
{
	memset (&PWMGroup_OBJ, 0, sizeof(PWMGroup_OBJ));
	PWMGroup_OBJ.PWMGROUP_S_0 = 0;
	PWMGroup_OBJ.PWMGROUP_S_1 = 0;
	PWMGroup_OBJ.PWMGROUP_S_2 = 0;
	PWMGroup_OBJ.PWMGROUP_S_3 = 0;
	PWMGroup_OBJ.PWMGROUP_Arr[0].MemberID = -1;
	PWMGroup_OBJ.PWMGROUP_Arr[0].OutBit   =  IO_Bit0;
	PWMGroup_OBJ.PWMGROUP_Arr[0].OutPort  =  IO_P0;
	PWMGroup_OBJ.PWMGROUP_Arr[0].OutPosCYC= 50;
	PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS=  0;
	PWMGroup_OBJ.PWMGROUP_Arr[1].MemberID = -1;
	PWMGroup_OBJ.PWMGROUP_Arr[1].OutBit   =  IO_Bit0;
	PWMGroup_OBJ.PWMGROUP_Arr[1].OutPort  =  IO_P0;
	PWMGroup_OBJ.PWMGROUP_Arr[1].OutPosCYC= 50;
	PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS=  0;
	PWMGroup_OBJ.PWMGROUP_Arr[2].MemberID = -1;
	PWMGroup_OBJ.PWMGROUP_Arr[2].OutBit   =  IO_Bit0;
	PWMGroup_OBJ.PWMGROUP_Arr[2].OutPort  =  IO_P0;
	PWMGroup_OBJ.PWMGROUP_Arr[2].OutPosCYC= 50;
	PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS=  0;
	PWMGroup_OBJ.PWMGROUP_Arr[3].MemberID = -1;
	PWMGroup_OBJ.PWMGROUP_Arr[3].OutBit   =  IO_Bit0;
	PWMGroup_OBJ.PWMGROUP_Arr[3].OutPort  =  IO_P0;
	PWMGroup_OBJ.PWMGROUP_Arr[3].OutPosCYC= 50;
	PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS=  0;

	GTimer_OBJJoin (PWMGroup_function, NULL);
	
	return 0;
}


char PWMGroup_Start (void)
{
	
	GTimer_OBJRun (PWMGroup_function);
	
	return 0;
}

char PWMGroup_Stop (void)
{

	GTimer_OBJPause (PWMGroup_function);
	
	return 0;
}



/* ------------------------------------------------------------ */

char PWMGroup_OBJJoin (PWMID *ID, IOPort outPort, IOBit outBit, uint8_t outDuty)
{
	char status = -1;
	status = PWMGroupOBJ_Findinvain ();
	if (status < 0) {
		return -1;
	} else {
		PWMGroup_OBJ.PWMGROUP_Arr[status].MemberID = status;
		PWMGroup_OBJ.PWMGROUP_Arr[status].OutPort  = outPort;
		PWMGroup_OBJ.PWMGROUP_Arr[status].OutBit   = outBit;
		PWMGroup_OBJ.PWMGROUP_Arr[status].OutPosCYC= outDuty;
		PWMGroup_OBJ.PWMGROUP_Arr[status].OutCurPOS= 0;

		io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[status].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[status].OutBit);
		*ID                                        = status;

		PWMGroupOBJ_push (status);
	}
	
	return status;
}

char PWMGroup_OBJRemove (PWMID ID)
{

	switch (ID)
	{
		case 0:if (PWMGroup_OBJ.PWMGROUP_S_0 != 0) {
                   PWMGroupOBJ_pop (0);
		       }
			   break;
		case 1:if (PWMGroup_OBJ.PWMGROUP_S_1 != 0) {
                   PWMGroupOBJ_pop (1);
		       }
			   break;
		case 2:if (PWMGroup_OBJ.PWMGROUP_S_2 != 0) {
                   PWMGroupOBJ_pop (2);
		       }
			   break;
		case 3:if (PWMGroup_OBJ.PWMGROUP_S_3 != 0) {
                   PWMGroupOBJ_pop (3);
		       }
			   break;
		default:return -1;
		       break;
	}
	
	return 0;
}

char PWMGroup_OBJRun (PWMID ID)
{

	switch (ID)
	{
		case 0:if (PWMGroup_OBJ.PWMGROUP_S_0 == 1) {
                   PWMGroup_OBJ.PWMGROUP_S_0  = 2;
		       }
			   break;
		case 1:if (PWMGroup_OBJ.PWMGROUP_S_1 == 1) {
                   PWMGroup_OBJ.PWMGROUP_S_1  = 2;
		       }
			   break;
		case 2:if (PWMGroup_OBJ.PWMGROUP_S_2 == 1) {
                   PWMGroup_OBJ.PWMGROUP_S_2  = 2;
		       }
			   break;
		case 3:if (PWMGroup_OBJ.PWMGROUP_S_3 == 1) {
                   PWMGroup_OBJ.PWMGROUP_S_3  = 2;
		       }
			   break;
		default:return -1;
		       break;
	}
	
	return 0;
}

char PWMGroup_OBJPause (PWMID ID)
{
	switch (ID)
	{
		case 0:if (PWMGroup_OBJ.PWMGROUP_S_0 == 2) {
                   PWMGroup_OBJ.PWMGROUP_S_0              = 1;
				   PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[0].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[0].OutBit);
		       }
			   break;
		case 1:if (PWMGroup_OBJ.PWMGROUP_S_1 == 2) {
                   PWMGroup_OBJ.PWMGROUP_S_1              = 1;
				   PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[1].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[1].OutBit);
		       }
			   break;
		case 2:if (PWMGroup_OBJ.PWMGROUP_S_2 == 2) {
                   PWMGroup_OBJ.PWMGROUP_S_2              = 1;
				   PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[2].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[2].OutBit);
		       }
			   break;
		case 3:if (PWMGroup_OBJ.PWMGROUP_S_3 == 2) {
                   PWMGroup_OBJ.PWMGROUP_S_3              = 1;
				   PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[3].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[3].OutBit);
		       }
			   break;
		default:return -1;
		       break;
	}
	
	return 0;
}

char PWMGroup_OBJSetDUTY (PWMID ID, uint8_t duty)
{
	switch (ID)
	{
		case 0:if (PWMGroup_OBJ.PWMGROUP_S_0 != 0) {
                   PWMGroup_OBJ.PWMGROUP_Arr[0].OutPosCYC = duty;
				   PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[0].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[0].OutBit);
		       }
			   break;
		case 1:if (PWMGroup_OBJ.PWMGROUP_S_1 != 0) {
                   PWMGroup_OBJ.PWMGROUP_Arr[1].OutPosCYC = duty;
				   PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[1].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[1].OutBit);
		       }
			   break;
		case 2:if (PWMGroup_OBJ.PWMGROUP_S_2 != 0) {
                   PWMGroup_OBJ.PWMGROUP_Arr[2].OutPosCYC = duty;
				   PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[2].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[2].OutBit);
		       }
			   break;
		case 3:if (PWMGroup_OBJ.PWMGROUP_S_3 != 0) {
                   PWMGroup_OBJ.PWMGROUP_Arr[3].OutPosCYC = duty;
				   PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS = 0;
				   io_ctrl_set_high (PWMGroup_OBJ.PWMGROUP_Arr[3].OutPort, PWMGroup_OBJ.PWMGROUP_Arr[3].OutBit);
		       }
			   break;
		default:return -1;
		       break;
	}
	
	return 0;
}




/* ------------------------------------------------------------ */

static char PWMGroupOBJ_Findinvain(void)
{
	uchar status = -1;

	if (PWMGroup_OBJ.PWMGROUP_S_0 == 0) {
		status = 0;
	} else if (PWMGroup_OBJ.PWMGROUP_S_1 == 0) {
		status = 1;
	} else if (PWMGroup_OBJ.PWMGROUP_S_2 == 0) {
		status = 2;
	} else if (PWMGroup_OBJ.PWMGROUP_S_3 == 0) {
		status = 3;
	} else {
		status = -1;
	}

	return status;
}

static char PWMGroupOBJ_push(uchar status)
{

	switch (status)
	{
		case 0:PWMGroup_OBJ.PWMGROUP_S_0 = 1;break;
		case 1:PWMGroup_OBJ.PWMGROUP_S_1 = 1;break;
		case 2:PWMGroup_OBJ.PWMGROUP_S_2 = 1;break;
		case 3:PWMGroup_OBJ.PWMGROUP_S_3 = 1;break;
		default:break;
	}

	return 0;
}

static char PWMGroupOBJ_pop(uchar status)
{
	
	switch (status)
	{
		case 0:PWMGroup_OBJ.PWMGROUP_S_0 = 0;
		       PWMGroup_OBJ.PWMGROUP_Arr[0].MemberID   = -1;
			   PWMGroup_OBJ.PWMGROUP_Arr[0].OutPort    =  IO_P0;
			   PWMGroup_OBJ.PWMGROUP_Arr[0].OutBit     =  IO_Bit0;
			   PWMGroup_OBJ.PWMGROUP_Arr[0].OutPosCYC  = 50;
			   PWMGroup_OBJ.PWMGROUP_Arr[0].OutCurPOS  =  0;
			   break;
		case 1:PWMGroup_OBJ.PWMGROUP_S_1 = 0;
		       PWMGroup_OBJ.PWMGROUP_Arr[1].MemberID   = -1;
			   PWMGroup_OBJ.PWMGROUP_Arr[1].OutPort    =  IO_P0;
			   PWMGroup_OBJ.PWMGROUP_Arr[1].OutBit     =  IO_Bit0;
			   PWMGroup_OBJ.PWMGROUP_Arr[1].OutPosCYC  = 50;
			   PWMGroup_OBJ.PWMGROUP_Arr[1].OutCurPOS  =  0;
			   break;
		case 2:PWMGroup_OBJ.PWMGROUP_S_2 = 0;
		       PWMGroup_OBJ.PWMGROUP_Arr[2].MemberID   = -1;
			   PWMGroup_OBJ.PWMGROUP_Arr[2].OutPort    =  IO_P0;
			   PWMGroup_OBJ.PWMGROUP_Arr[2].OutBit     =  IO_Bit0;
			   PWMGroup_OBJ.PWMGROUP_Arr[2].OutPosCYC  = 50;
			   PWMGroup_OBJ.PWMGROUP_Arr[2].OutCurPOS  =  0;
			   break;
		case 3:PWMGroup_OBJ.PWMGROUP_S_3 = 0;
		       PWMGroup_OBJ.PWMGROUP_Arr[3].MemberID   = -1;
			   PWMGroup_OBJ.PWMGROUP_Arr[3].OutPort    =  IO_P0;
			   PWMGroup_OBJ.PWMGROUP_Arr[3].OutBit     =  IO_Bit0;
			   PWMGroup_OBJ.PWMGROUP_Arr[3].OutPosCYC  = 50;
			   PWMGroup_OBJ.PWMGROUP_Arr[3].OutCurPOS  =  0;
			   break;
		default:break;
	}

	return 0;
}











#endif /* PWMGROUP_CONFIG */