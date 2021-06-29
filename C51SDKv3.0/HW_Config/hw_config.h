#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H

#include <stdio.h>
#include <intrins.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "reg52.h"
#include "hw_vartype.h"
#include "user_config_prj.h"




#ifdef IOCTRL_CONFIG
#include "hw_ioctrl.h"
#endif /* IOCTRL_CONFIG */

#ifdef TIMER0_CONFIG
//#ifndef GTIMER_CONFIG
#include "hw_Timer0.h"
//#endif /* GTIMER_CONFIG */
#endif /* TIMER0_CONFIG */

#ifdef TIMER1_CONFIG
//#ifndef GTIMER_CONFIG
#include "hw_Timer1.h"
//#endif /* GTIMER_CONFIG */
#endif /* TIMER1_CONFIG */

#ifdef TIMER2_CONFIG
#include "hw_Timer2.h"
#endif /* TIMER2_CONFIG */

#ifdef UART_CONFIG
#include "hw_UART.h"
#endif /* UART_CONFIG */

#ifdef MEMPOOL_CONFIG
#include "hw_MEMPool.h"
#endif /* MEMPOOL_CONFIG */

#ifdef GTIMER_CONFIG
#include "hw_Gtimer.h"
#endif /* GTIMER_CONFIG */





#ifdef LCD1602_CONFIG
#include "LCD1602.h"
#endif /* LCD1602_CONFIG */

#ifdef MAX541X_CONFIG
#include "MAX541x.h"
#endif /* MAX541X_CONFIG */

#ifdef MAX263_CONFIG
#include "max263.h"
#endif /* MAX263_CONFIG */

#ifdef KEY4X4_CONFIG
#include "independent_key_4.h"
#endif /* KEY4X4_CONFIG */

#ifdef AD0809_CONFIG
#include "ad0809.h"
#endif /* AD0809_CONFIG */

#ifdef AD9850_CONFIG
#include "ad9850.h"
#endif /* AD9850_CONFIG */

#ifdef PWM_CONFIG
#include "pwm.h"
#endif /* PWM_CONFIG */

#ifdef PWMGROUP_CONFIG
#include "PWMGroup.h"
#endif /* PWMGROUP_CONFIG */

#ifdef DHT11_CONFIG
#include "dht11.h"
#endif /* DHT11_CONFIG */

#ifdef DS1302_CONFIG
#include "ds1302.h"
#endif /* DS1302_CONFIG */

#ifdef DS18B20_CONFIG
#include "ds18b20.h"
#endif /* DS18B20_CONFIG */

#ifdef ESP8266_CONFIG
#include "esp8266.h"
#endif /* ESP8266_CONFIG */

#ifdef IIC_CONFIG
#include "iic.h"
#endif /* IIC_CONFIG */

#ifdef AT24C02_CONFIG
#include "at24c02.h"
#endif /* AT24C02_CONFIG */

#ifdef DIGITALTUBE6_CONFIG
#include "DigitalTube6.h"
#endif /* DIGITALTUBE6_CONFIG */

#ifdef MAX1241_CONFIG
#include "max1241.h"
#endif /* MAX1241_CONFIG */

#ifdef AD5320_CONFIG
#include "ad5320.h"
#endif /* AD5320_CONFIG */

#ifdef LCD12864_CONFIG
#include "lcd12864.h"
#endif /* LCD12864_CONFIG */

#ifdef HX711_CONFIG
#include "hx711.h"
#endif /* HX711_CONFIG */

#ifdef HCSR04_CONFIG
#include "hcsr04.h"
#endif /* HCSR04_CONFIG */

#ifdef DRV_SPI_CONFIG
#include "drv_spi.h"
#endif /* DRV_SPI_CONFIG */

#ifdef DRV_CC1101_CONFIG
#include "drv_cc1101.h"
#endif /* DRV_CC1101_CONFIG */

#ifdef ALONEBUTTON_CONFIG
#include "drv_button.h"
#endif /* ALONEBUTTON_CONFIG */







#ifdef SW_GDELAY_CONFIG
#include "sw_Gdelay.h"
#endif /* SW_GDELAY_CONFIG */

#ifdef SW_SOFTTIMER_CONFIG
#include "sw_SoftTimer.h"
#endif /* SW_SOFTTIMER_CONFIG */

#ifdef SW_GCAPTURE_CONFIG
#include "sw_GCapture.h"
#endif /* SW_GCAPTURE_CONFIG */



#define __CRITICAL_SECTION_SET__()   EA = 0
#define __CRITICAL_SECTION_CLEAR__() EA = 1


void bsp_gpio_config (void);
void bsp_init (void);

#endif /* __HW_CONFIG_H */
