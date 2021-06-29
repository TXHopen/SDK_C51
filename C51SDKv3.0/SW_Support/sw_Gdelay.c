#include "sw_Gdelay.h"

#ifdef SW_GDELAY_CONFIG

void Gdelay_ms (uint ms)
{
	uchar i = 0;
	if (ms <= 0) {
		return ;
	}
	while (ms--)
	{
		for(i=0; i<110; i++);
	}
}

void Gdelay_ns (uint ns)
{
	if (ns <= 0) {
		return ;
	}
	while (ns--)
	{
		_nop_();
	}
}



void Gdelay_10ms (uint ms10)
{
	uint i = 0;
	if (ms10 <= 0) {
		return ;
	}
	while (ms10--)
	{
		for(i=0; i<1100; i++);
	}
}

void Gdelay_10ns (uint ns10)
{
	if (ns10 <= 0) {
		return ;
	}
	while (ns10--)
	{
		_nop_();_nop_();
		_nop_();_nop_();
		_nop_();_nop_();
		_nop_();_nop_();
	}
}




#endif /* SW_GDELAY_CONFIG */