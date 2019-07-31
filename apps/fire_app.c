#define F_CPU 16000000UL
#include<util/delay.h>
#include "../mcal/usart/usart.h"
#include "../mcal/adc/adc.h"
void fire_serial_app(void)
{
	u8_t  text[10];
	u16_t digital_read;
	//delay for power stability
	_delay_ms(300);
	// init adc
    init_adc();
   //init uart
    init_usart(9600);
    _delay_ms(100);
   while(1)
   {
	   //measure temprture
	   digital_read = adc_channel_read(ADC_CH0);
	   //convert temprture to string
	   utoa(digital_read , text , 10);
	   // send temprture string through uart with a new line
	   usart_write_text_line(text);
	   //delay for a second
	   _delay_ms(1000);
   }


}

