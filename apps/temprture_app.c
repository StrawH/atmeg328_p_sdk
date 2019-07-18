#include <util/delay.h>
#include "../utils/custom_types.h"
#include "../hal/lcd/lcd.h"
#include "../mcal/dio/mcal_dio.h"
#include "../mcal/adc/adc.h"
#define FAN_PIN dio_channel_rd0
#define HEATER_PIN dio_channel_rd1
#define TEMPRTURE_PIN ADC_CH0

void init_system(void);
void turn_heater_on(void);
void turn_fan_on(void);
void turn_off_all(void);
double read_temprture(adc_channel_t channel);
void lcd_update_temprture(double new_temprture);
void lcd_update_sp(u8_t new_temprture);
void temprture_app(void)
{
	double temprture = 0;
     u8_t set_point = 23;
	 init_system();
	 lcd_update_sp(set_point);
     while(1)
     {
    	 temprture = read_temprture(TEMPRTURE_PIN);
    	 lcd_update_temprture(temprture);
    	 if(temprture > set_point)
    	 {
    		 turn_fan_on();
    	 }
    	 else if (temprture < set_point)
		{
    		 turn_heater_on();
		}
    	 else
    	 {
    		 turn_off_all();
    	 }
    	 _delay_ms(1000);
     }
}
void init_system(void)
{
	_delay_ms(100);
	init_adc();
	init_lcd();
	dio_set_channel_direction(FAN_PIN , output);
	dio_set_channel_direction(HEATER_PIN , output);
	dio_set_channel_state(FAN_PIN , low);
	dio_set_channel_state(HEATER_PIN , low);
}
void turn_heater_on(void)
{
	dio_set_channel_state(FAN_PIN , low);
	dio_set_channel_state(HEATER_PIN , high);
}
void turn_fan_on(void)
{
	dio_set_channel_state(FAN_PIN , high);
	dio_set_channel_state(HEATER_PIN , low);
}
void turn_off_all(void)
{
	dio_set_channel_state(FAN_PIN , low);
	dio_set_channel_state(HEATER_PIN , low);
}
double read_temprture(adc_channel_t channel)
{
	double voltage;
	double temprture;
	voltage = adc_read_voltage(channel);
	temprture = voltage * 100;
	return temprture;
}
void lcd_update_temprture(double new_temprture)
{
	char text[10];
	lcd_display_text("tem:" , 2 , 1);
	lcd_display_text_cp(dtostrf(new_temprture,5,2,text));
	lcd_display_char_cp(0b11011111);
	lcd_display_char_cp('C');
}
void lcd_update_sp(u8_t new_sp)
{
	char text[6];
	lcd_display_text("set point:" , 1 , 1);
	lcd_display_text_cp(itoa(new_sp,text,10));
	lcd_display_char_cp(0b11011111);
	lcd_display_char_cp('C');
}


