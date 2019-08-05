/*
 * ultra_sonic_app.c
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../mcal/dio/mcal_dio.h"
#include "../mcal/usart/usart.h"
#include "../mcal/timer1_stop_watch/timer1_spw.h"
#include "../utils/custom_types.h"
#define TRIG_PIN dio_channel_rb0
#define ECHO_PIN dio_channel_rb1
void ultraSonic_app(void)
{
	u16_t time_us = 0 , distance = 0;
	u8_t text[10];
	_delay_ms(100);
	init_usart(9600);
	usart_write_text("distance:");
	_delay_ms(100);
	dio_set_channel_direction(TRIG_PIN , output);
	dio_set_channel_direction(ECHO_PIN , input);
	dio_set_channel_state(TRIG_PIN , low);
	while(1)
	{
		// send triger pulse
		dio_set_channel_state(TRIG_PIN , high);
		_delay_us(10);
		dio_set_channel_state(TRIG_PIN , low);
		// wait for echo pulse to start
		reset_stop_watch();
		while(dio_read_channel_state(ECHO_PIN) == 0);
		start_stop_watch();
		// wait for echo pulse to finsh
		while(dio_read_channel_state(ECHO_PIN) == 1);
        stop_stop_watch();
        // time for signal to travel from sensor to object and back again
        time_us = get_stop_watch_value();
        time_us = time_us>>1; // time from sensor to object
        distance = 0.331 * time_us; // distance in cm
        itoa(distance , text , 16);
        usart_write_text("distance:");
        usart_write_text_line(text);
        _delay_ms(1000);
	}
}

