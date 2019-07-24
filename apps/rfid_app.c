/*
 * rfid_app.c
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../hal/rfid/rfid.h"
#include "../mcal/usart/usart.h"
void rfid_app(void)
{
    char *prams;
    init_rfid();
	_delay_ms(100);
	while(1)
	{
		if(get_rfid_reading())
		{
			prams =get_rfid_record();
            usart_write_text(prams);
			usart_write_text("\n\r");
		}

	}
}


