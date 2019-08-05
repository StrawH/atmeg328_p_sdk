/*
 * pwm_app.c
 *
 *  Created on: Aug 4, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include "util/delay.h"
#include "../mcal/timer1_pwm/timer1_pwm.h"
void test_pwm(void)
{
	int i = 0;
	init_pwm(50 , enable_both , pulse_noninverted);
	pwm_change_duty(oc1a_ch , 127);
	pwm_change_duty(oc1b_ch , 200);
	// angle 0 duty 9 (ton*255/200000)
	// angle 180 duty 31 (ton*255/200000)
	while(1)
	{
		for(i = 71 ; i < 243 ; i++)
		{
			pwm_change_duty(oc1a_ch , 243);
			_delay_ms(500);
		}
		for(i = 243 ; i >= 71 ; i--)
		{
			pwm_change_duty(oc1a_ch , i);
			_delay_ms(500);
		}
	}
}

