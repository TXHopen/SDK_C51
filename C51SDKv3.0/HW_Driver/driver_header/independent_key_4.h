#ifndef __INDEPENDENT_KEY_4_H
#define __INDEPENDENT_KEY_4_H


#include "user_config_prj.h"

#ifdef KEY4X4_CONFIG

#include "hw_config.h"

#define GPIO_KEY            P0

u8 KeyDown(void);


#endif /* KEY4X4_CONFIG */

#endif /* __INDEPENDENT_KEY_4_H */
