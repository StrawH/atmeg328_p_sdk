/*
 * led_app.c
 *
 *  Created on: Jul 14, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../mcal/dio/mcal_dio.h"
int flashing_app(void)
{
	dio_set_channel_direction(dio_channel_rb5 , output);
	while(1)
	{
		dio_set_channel_state(dio_channel_rb5 , high);
		_delay_ms(100);
		dio_set_channel_state(dio_channel_rb5 , low);
		_delay_ms(100);
	}
	return 0;
}

