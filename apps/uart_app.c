/*
 * uart_app.c
 *
 *  Created on: Jul 21, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../hal/gps/gps.h"
#include "../hal/lcd/lcd.h"
void uart_app(void)
{
	gps_packet_t  rec_packet;
	init_lcd();
	init_gps();
	_delay_ms(100);
	while(1)
	{
		if(get_gps_reading())
		{
			rec_packet = get_gps_informations();
			lcd_display_text(rec_packet.lat , 1 , 1);
			lcd_display_text(rec_packet.lon , 2 , 1);
		}

		_delay_ms(1000);
	}
}

