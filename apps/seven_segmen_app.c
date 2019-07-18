/*
 * seven_segmen_app.c
 *
 *  Created on: Jul 10, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include<util/delay.h>
#include "../utils/custom_types.h"
#include "../hal/seven_segment/seven_seg.h"
#include "../mcal/dio/mcal_dio.h"
#define EXIT_BUTTON dio_channel_rb0
#define ENTER_BUTTON dio_channel_rb1
#define CAPACITY 5
int sevensegment_app(void)
{
	_delay_ms(100);
	//variable declaritions
	u8_t no_of_cars = 0 ;
	bool_t is_car_existed = false;
	//init for hardware
	dio_set_channel_direction(EXIT_BUTTON , input);
	dio_set_channel_direction(ENTER_BUTTON , input);
	init_seven_segment();
	display_digit(no_of_cars);
	//super loop
	while(1)
	{
        if(dio_read_channel_state(EXIT_BUTTON) == high)
        {
        	if(no_of_cars>0)no_of_cars--;
        	display_digit(no_of_cars);
        	while(dio_read_channel_state(EXIT_BUTTON) == high);
        }
        if(dio_read_channel_state(ENTER_BUTTON) == high)
		{
        	_delay_ms(15);
		    if(dio_read_channel_state(ENTER_BUTTON) == high)
		    {
				if(is_car_existed == false)
				{
					if(no_of_cars<CAPACITY)no_of_cars++;
					display_digit(no_of_cars);
					is_car_existed = true;
				}
		    }
        }
        else
        {
        	_delay_ms(10);
        	if(dio_read_channel_state(ENTER_BUTTON) == low)
        	{
        		is_car_existed = false;
        	}
        }


	}
	return 0;
}

