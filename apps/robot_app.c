/*
 * robot_app.c
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../hal/h_bridge/h_bridge.h"
#include "../mcal/usart/usart.h"
void robot_app_task(void)
{
    u8_t rec_char = 0;
	_delay_ms(100);
	init_motors();
	init_usart(9600);
	_delay_ms(5000);
    while(1)
    {
         if(usart_data_available())
         {
        	 rec_char = usart_read_char();
        	 if(rec_char ==  'F')
        	 {
        		 move_forward();
        	 }
        	 else if(rec_char ==  'B')
			 {
				 move_backward();
			 }
        	 else if(rec_char ==  'L')
			 {
        		 move_clkwise();
			 }
        	 else if(rec_char ==  'R')
			 {
				 move_aclkwise();
			 }
        	 else if(rec_char ==  'S')
			 {
				 move_hold();
			 }

         }
    }
}

