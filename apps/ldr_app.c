#define F_CPU 16000000UL
#include<util/delay.h>
#include "../mcal/usart/usart.h"
#include "../mcal/adc/adc.h"
#define RN 10000.0 // 10k
void ldr_serial_app(void)
{
	double vm;
	u8_t  text[10];
	u32_t resistance;
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
	   vm = adc_read_voltage(ADC_CH0);
	   resistance = (vm *RN)/((5.0/vm) - 1);
	   //convert temprture to string
	   utoa(resistance , text , 10);
	   // send temprture string through uart with a new line
	   usart_write_text_line(text);
	   //delay for a second
	   _delay_ms(1000);
   }


}

