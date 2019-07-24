/*
 * gps.c
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#include <util/delay.h>
#include "../../utils/custom_types.h"
#include "../../mcal/dio/mcal_dio.h"
#include "../../mcal/usart/usart.h"
#include "gps.h"
static gps_packet_t last_gps_reading;
void init_gps()
{
	dio_set_channel_direction(dio_channel_rd0 , input);
	dio_set_channel_direction(dio_channel_rd1 , output);
	init_usart(9600);
	_delay_ms(100);
	last_gps_reading.is_valid_reading = false;
}
bool_t get_gps_reading()
{
    u8_t state = 0 , rec_char=0;
    u32_t loop_counts = 0;
    bool_t has_catched = false;

    while(loop_counts<1000 && has_catched == false) // the waiting time hasn't exceed 1000ms
    {
    	if(usart_data_available())
    	{
    		rec_char = usart_read_char();
    		if(rec_char == 'G' && state == 0)state=1;
    		else if(rec_char == 'G' && state == 1)state=2;
    		else if(rec_char == 'A' && state == 2)state=3;
    		else state =0;
    	}
    	else
    	{
            _delay_us(1000);
    	}
    	loop_counts++;
    	if(state == 3)
    	{
    		// start of frame catched
    		has_catched = true;
    		u8_t comma_counter = 0;
    		u8_t next_index = 0;
    		while(comma_counter<6)
    		{
    			//,123519,4807.038,N,01131.000,E,
    			//1      2        3 4         5  6
    			// 01     0        0 0         0  0
    			//,,,,,,
    			if(usart_data_available())
    			{
    			   rec_char = usart_read_char();
    			   if(rec_char == ',')
    			   {
    				   comma_counter++;
    				   // another condition
    				   if(comma_counter!=3 && comma_counter!=5)
    				   {
    					   if(comma_counter==2)last_gps_reading.time[next_index]=0;
    					   else if(comma_counter==4)last_gps_reading.lat[next_index]=0;
    					   else if(comma_counter==6)last_gps_reading.lon[next_index]=0;
    					   next_index = 0;
    				   }
    			   }
    			   else
    			   {
    				   if(comma_counter == 1)
    				   {
    					   last_gps_reading.time[next_index] = rec_char;
    					   next_index++;
    				   }
    				   else if(comma_counter <4)
    				   {
						   last_gps_reading.lat[next_index] = rec_char;
						   next_index++;
					   }
    				   else if(comma_counter <6)
					   {
						   last_gps_reading.lon[next_index] = rec_char;
						   next_index++;
					   }
    			   }
    			}
    		}
    	}

    }
    return has_catched;
}
gps_packet_t get_gps_informations()
{
     return last_gps_reading;
}


