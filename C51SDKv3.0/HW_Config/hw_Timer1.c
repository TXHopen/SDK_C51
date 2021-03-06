#include "hw_Timer1.h"

#ifdef TIMER1_CONFIG

//#ifndef GTIMER_CONFIG


static u8 timer_h;
static u8 timer_l;

static bit mode_flg = 0;

int (*pointer_interupt_timer1)(void *arg);

static int interupt_timer_function (void *arg) 
{
	void *ptr = arg;
	return 0;
}



/*******************************************************************************
* 函 数 名         : Timer1Init
* 函数功能		   : 定时器1初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer1Init(uint mode, uint us, void *callback)
{
	switch (mode)
	{
		case TIMER1_MODE_0:TMOD   |= 0X00;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		case TIMER1_MODE_1:TMOD   |= 0X10;
		                   timer_h = (65536-us) / 256;
		                   timer_l = (65536-us) % 256;
		                   break;
		case TIMER1_MODE_2:TMOD   |= 0X20;
		                   timer_h = (256-us) % 256;
		                   timer_l = timer_h;
		                   break;
		default:return ;   break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer1 = interupt_timer_function;
	} else {
		pointer_interupt_timer1 = callback;
	}
	
	TH1   = timer_h;	//给定时器赋初值
	TL1   = timer_l;	
	ET1=1;//打开定时器1中断允许
	EA=1;//打开总中断
	TR1=1;//打开定时器			
}




void Timer1Init_NoOpen(uint mode, uint us, void *callback)
{
	TR1   = 0;//关闭定时器
	ET1   = 0;//关闭定时器1中断允许
	switch (mode)
	{
		case TIMER1_MODE_0:TMOD   |= 0X00;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		case TIMER1_MODE_1:TMOD   |= 0X10;
		                   timer_h = (65536-us) / 256;
		                   timer_l = (65536-us) % 256;
		                   break;
		case TIMER1_MODE_2:TMOD   |= 0X20;
		                   timer_h = (256-us) % 256;
		                   timer_l = timer_h;
		                   mode_flg = 1;
		                   break;
		default:return ;   break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer1 = interupt_timer_function;
	} else {
		pointer_interupt_timer1 = callback;
	}
	
	TH1   = timer_h;	//给定时器赋初值
	TL1   = timer_l;	
	ET1   = 0;//关闭定时器1中断允许
	EA    = 1;//打开总中断
	TR1   = 0;//打开定时器
}

void Timer1Open(void)
{
	TH1   = timer_h;	//给定时器赋初值
	TL1   = timer_l;
	ET1   = 1;//打开定时器0中断允许
	TR1   = 1;//打开定时器
}

void Timer1Close(void)
{
	TR1   = 0;//关闭定时器
	ET1   = 0;//关闭定时器0中断允许
	TH1   = timer_h;	//给定时器赋初值
	TL1   = timer_l;	
}

void Timer1Pause(void)
{
	TR1   = 0;//关闭定时器
	ET1   = 0;//关闭定时器0中断允许
}

void Timer1Start(void)
{
	ET1   = 1;//打开定时器0中断允许
	TR1   = 1;//打开定时器
}





/*******************************************************************************
* 函 数 名         : void Timer1() interrupt 3
* 函数功能		   : 定时器0中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer1() interrupt 3
{
	if (mode_flg == 0) {
		TH1 = timer_h;	//给定时器赋初值
		TL1 = timer_l;
	}
	
	pointer_interupt_timer1(NULL);
}



//#endif /* GTIMER_CONFIG */
#endif /* TIMER1_CONFIG */

