/*
 * timer1_spw.c
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */
#define TIMER1_NO_CLK        0x00
#define TIMER1_CLK_DIV1      0x01
#define TIMER1_CLK_DIV8      0x02
#define TIMER1_CLK_DIV64     0x03
#define TIMER1_CLK_DIV256    0x04
#define TIMER1_CLK_DIV1024   0x05
#define TIMER1_CLK_EXT_F     0x06
#define TIMER1_CLK_EXT_R     0x07

#define USE_CLK_DEV TIMER1_CLK_DIV8
#define TIMER_CLK_MASK 0xF8

#include "timer1_atmega328p_reg.h"
#include "timer1_spw.h"
#include "../../utils/custom_types.h"
void init_stop_watch(void)
{

}
/* get the stop watch counts*/
u16_t get_stop_watch_value(void)
{
     u16_t timer_value;
     timer_value = TCNT1H;
     timer_value <<= 8;
     timer_value |= TCNT1L; // timer_value holds the value of counts it count value every 0.5us
     timer_value >>= 1 ; // to get the value in us (/2)
     return  timer_value;
}
/* start counting */
void start_stop_watch(void)
{
	//enable clock for stop watch
	TCCR1B = (TCCR1B & TIMER_CLK_MASK) | USE_CLK_DEV ;
}
void stop_stop_watch(void)
{
	//disable clock for stop watch
	TCCR1B = (TCCR1B & TIMER_CLK_MASK) | TIMER1_NO_CLK ;
}
/* reset counts to zero*/
void reset_stop_watch(void)
{
	// set timer counts to Zero
	TCNT1H  = 0;
	TCNT1L  = 0;
}



