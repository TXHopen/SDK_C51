#include "user_main.h"

/*-------------------------------------------------------------------------*/
uint8_t i = 0;
uint8_t j = 0;
uint8_t n = 0;

uint8_t m = 0;


static void test (void* arg)
{
	void* ptr = arg;
	if (j == 0) {
		P2 = 0X00;
		j = 1;
	} else {
		P2 = 0xFF;
		j = 0;
	}
}

static void func (void* arg)
{
	void* ptr = arg;
	if (i == 0) {
		P0 = 0X00;
		i = 1;
	} else {
		P0 = 0xFF;
		i = 0;
	}
	
	if (m < 30) {
		m++;
	} else {
		/*
		SOFTTimer_OBJJoin (1000, test, NULL);
		SOFTTimer_OBJRun (test);
		SOFTTimer_OBJRemove (func);
		*/
		//PWM_SetDUTY (10);
	}
}

static void timer (void* arg)
{
	void* ptr = arg;
	n++;
	if (n >= 100) {
		P1 = ~P1;
		n = 0;
	}
}


static void test1(void* arg)
{
	void* ptr = arg;
	PWMGroup_OBJSetDUTY (3, 50);
}


/*-------------------------------------------------------------------------*/

void user_main (void)
{
	PWMID ID;
	PWMID ID1;
	PWMID ID2;
	PWMID ID3;
	/*
	__CRITICAL_SECTION_SET__();
	SOFTTimer_OBJJoin (1000, func, NULL);
	SOFTTimer_OBJRun (func);
	
	GTimer_OBJJoin (timer, NULL);
	GTimer_OBJRun (timer);
	__CRITICAL_SECTION_CLEAR__();
	*/
	
	//PWM_Init (50);
	//PWM_Start ();
	
	PWMGroup_OBJJoin (&ID, IO_P3, IO_Bit7, 10);
	PWMGroup_OBJJoin (&ID1, IO_P3, IO_Bit6, 20);
	PWMGroup_OBJJoin (&ID2, IO_P3, IO_Bit5, 30);
	PWMGroup_OBJJoin (&ID3, IO_P3, IO_Bit4, 40);
	PWMGroup_OBJRun (ID);
	PWMGroup_OBJRun (ID1);
	PWMGroup_OBJRun (ID2);
	PWMGroup_OBJRun (ID3);
	
	SOFTTimer_OBJJoin (30000, test1, NULL);
	SOFTTimer_OBJRun (test1);
	
	while (1)
	{
		//io_ctrl_set_high (IO_P0, IO_Bit0);
	}
}








/*-------------------------------------------------------------------------*/









