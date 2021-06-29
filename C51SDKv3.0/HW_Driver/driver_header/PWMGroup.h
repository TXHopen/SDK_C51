#ifndef __PWMGROUP_H
#define __PWMGROUP_H


#include "user_config_prj.h"

#ifdef PWMGROUP_CONFIG

#include "hw_config.h"
#include "hw_ioctrl.h"


typedef uint8_t     PWMID;


typedef struct _PWMGROUP_Member
{
	PWMID           MemberID;
	IOPort          OutPort;
	IOBit           OutBit;
	uint8_t         OutPosCYC;
	uint8_t         OutCurPOS;
} PWMGROUP_Member;


typedef struct _PWMGROUP_Queue
{
	uint8_t         PWMGROUP_S_0;
	uint8_t         PWMGROUP_S_1;
	uint8_t         PWMGROUP_S_2;
	uint8_t         PWMGROUP_S_3;
	PWMGROUP_Member PWMGROUP_Arr[4];
} PWMGROUP_Queue;






char PWMGroup_Init (void);
char PWMGroup_Start (void);
char PWMGroup_Stop (void);
char PWMGroup_OBJJoin (PWMID* ID, IOPort outPort, IOBit outBit, uint8_t outDuty);
char PWMGroup_OBJRemove (PWMID ID);
char PWMGroup_OBJRun (PWMID ID);
char PWMGroup_OBJPause (PWMID ID);
char PWMGroup_OBJSetDUTY (PWMID ID, uint8_t duty);



#endif /* PWMGROUP_CONFIG */

#endif /* __PWM_ONE_H */
