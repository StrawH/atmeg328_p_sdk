/*
 * test_lcd_app.c
 *
 *  Created on: Jul 15, 2019
 *
 *      Author: mohamed
 */

#define F_CPU 16000000UL
#include "../hal/lcd/lcd.h"
int just_test(void)
{
	init_lcd();
	lcd_display_text("Gragh System" , 1 , 4);
}
