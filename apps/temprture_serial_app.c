#define F_CPU 16000000UL
#include<util/delay.h>
#include "../mcal/usart/usart.h"
#include "../mcal/adc/adc.h"

void t_serial_app(void)
{
	double voltage;
	u8_t temprture , text[10];
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
	   voltage = adc_read_voltage(ADC_CH0);
	   temprture = 100*voltage;
	   //convert temprture to string
	   itoa(temprture , text , 10);
	   // send temprture string through uart with a new line
	   usart_write_text_line(text);
	   //delay for a second
	   _delay_ms(1000);
   }


}
