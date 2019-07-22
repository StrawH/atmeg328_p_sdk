/*
 * uart_app.c
 *
 *  Created on: Jul 21, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../mcal/usart/usart.h"
#include "../mcal/dio/mcal_dio.h"
void uart_app(void)
{
	dio_set_channel_direction(dio_channel_rd0 , input);
	dio_set_channel_direction(dio_channel_rd1 , output);
	init_usart(9600);
	usart_write_char('*');
	while(1)
	{
		usart_write_char('*');
		_delay_ms(1000);
	}
}

