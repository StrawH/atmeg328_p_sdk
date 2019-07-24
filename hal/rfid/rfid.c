/*
 * rfid.c
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../utils/custom_types.h"
#include "../../mcal/dio/mcal_dio.h"
#include "../../mcal/usart/usart.h"
#include "rfid.h"
 u8_t rfid_packet[20];
void init_rfid(void)
{
	dio_set_channel_direction(dio_channel_rd0 , input);
	dio_set_channel_direction(dio_channel_rd1 , output);
	init_usart(9600);
	_delay_ms(100);
}
bool_t get_rfid_reading(void)
{
     u32_t loop_counts = 0;
     u8_t rec_char , next_index = 0;
     bool_t is_catched = false , packet_started = false;
     while(loop_counts<100 && is_catched == false)
     {
    	 if(usart_data_available())
		 {
			rec_char = usart_read_char();
			if(rec_char == 0x02)
			{
				next_index = 0;
				packet_started = true;

			}
			else if(rec_char == 0x03 && packet_started == true)
			{
				rfid_packet[next_index] = 0;
				packet_started = false;
				is_catched = true;
			}
			else if(packet_started == true)
			{
				rfid_packet[next_index] = rec_char;
				next_index++;
			}
		}//if data available
    	else
    	 {
    		_delay_ms(1);
    	 }
    	 loop_counts++;
     }//while
     return is_catched;
}
char* get_rfid_record(void)
{
	return rfid_packet;
}
