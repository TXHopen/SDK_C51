#ifndef __SW_GDELAY_H
#define __SW_GDELAY_H


#include "user_config_prj.h"

#ifdef SW_GDELAY_CONFIG

#include "hw_config.h"


void Gdelay_ms (uint ms);
void Gdelay_10ms (uint ms10);

void Gdelay_ns (uint ns);
void Gdelay_10ns (uint ns10);


#endif /* SW_GDELAY_CONFIG */

#endif /* __SW_GDELAY_H */
