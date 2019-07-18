/*
 * lcd.c
 *
 *  Created on: Jul 11, 2019
 *      Author: mohamed
 */
#include <util/delay.h>
#include "../../utils/custom_types.h"
#include "../../utils/bit_math.h"
#include "../../mcal/dio/mcal_dio.h"
#include "lcd.h"
#include "lcd_config.h"

static void send_instruction(u8_t instruction);
static void send_instruction_4bits(u8_t instruction);
static void send_data(u8_t data);
static void set_xy_cursor_pos(u8_t row , u8_t col);

void init_lcd(void)
{
#if LCD_MODE == MODE_8

#endif
	dio_set_channel_direction(LCD_RS, output);
	dio_set_channel_direction(LCD_EN, output);
	dio_set_channel_direction(LCD_B4, output);
	dio_set_channel_direction(LCD_B5, output);
	dio_set_channel_direction(LCD_B6, output);
	dio_set_channel_direction(LCD_B7, output);
	dio_set_channel_state(LCD_EN , low);
	_delay_ms(20); // wait more than 15ms
	send_instruction_4bits(0x03); // 0011
	_delay_ms(5);   // wait more than 4.1ms
	send_instruction_4bits(0x03);
    _delay_us(200); //wait more than 100us
    send_instruction_4bits(0x03);
    _delay_us(200);
    send_instruction_4bits(0x02);
    // the screen now working in 4 bit mode
    send_instruction(0x28);
    _delay_us(200);
    send_instruction(DISPLAY_OFF_CMD);
    _delay_us(200);
    send_instruction(DISPLAY_CLEAR_CMD);
    _delay_ms(2);
    send_instruction(0x06);
    _delay_us(1000);
    send_instruction(DISPLAY_ON_CMD);
    _delay_us(200);
}
static void send_instruction_4bits(u8_t instruction)
{
	dio_set_channel_state(LCD_RS , low);
	//put the instruction
	dio_set_channel_state(LCD_B4 , READ_BIT(instruction , 0));
	dio_set_channel_state(LCD_B5 , READ_BIT(instruction , 1));
	dio_set_channel_state(LCD_B6 , READ_BIT(instruction , 2));
	dio_set_channel_state(LCD_B7 , READ_BIT(instruction , 3));
	//enable pulse
	dio_set_channel_state(LCD_EN , low);
	dio_set_channel_state(LCD_EN , high);
	_delay_us(1); //enable cycle time
	dio_set_channel_state(LCD_EN , low);
	_delay_us(100);
}
static void send_instruction(u8_t instruction)
{
	dio_set_channel_state(LCD_RS , low);
	//sent high nipple
	dio_set_channel_state(LCD_B4 , READ_BIT(instruction , 4));
	dio_set_channel_state(LCD_B5 , READ_BIT(instruction , 5));
	dio_set_channel_state(LCD_B6 , READ_BIT(instruction , 6));
	dio_set_channel_state(LCD_B7 , READ_BIT(instruction , 7));
	//enable pulse
	dio_set_channel_state(LCD_EN , low);
	dio_set_channel_state(LCD_EN , high);
	_delay_us(1); //enable cycle time
	dio_set_channel_state(LCD_EN , low);
	_delay_us(100);
	//sent low nipple
	dio_set_channel_state(LCD_B4 , READ_BIT(instruction , 0));
	dio_set_channel_state(LCD_B5 , READ_BIT(instruction , 1));
	dio_set_channel_state(LCD_B6 , READ_BIT(instruction , 2));
	dio_set_channel_state(LCD_B7 , READ_BIT(instruction , 3));
	//enable pulse
	dio_set_channel_state(LCD_EN , low);
	dio_set_channel_state(LCD_EN , high);
	_delay_us(1); //enable cycle time
	dio_set_channel_state(LCD_EN , low);
	_delay_us(100);
}
static void send_data(u8_t data)
{
	dio_set_channel_state(LCD_RS , high);
	//sent high nipple
	dio_set_channel_state(LCD_B4 , READ_BIT(data , 4));
	dio_set_channel_state(LCD_B5 , READ_BIT(data , 5));
	dio_set_channel_state(LCD_B6 , READ_BIT(data , 6));
	dio_set_channel_state(LCD_B7 , READ_BIT(data , 7));
	//enable pulse
	dio_set_channel_state(LCD_EN , low);
	dio_set_channel_state(LCD_EN , high);
	_delay_us(1); //enable cycle time
	dio_set_channel_state(LCD_EN , low);
	_delay_us(100);
	//sent low nipple
	dio_set_channel_state(LCD_B4 , READ_BIT(data , 0));
	dio_set_channel_state(LCD_B5 , READ_BIT(data , 1));
	dio_set_channel_state(LCD_B6 , READ_BIT(data , 2));
	dio_set_channel_state(LCD_B7 , READ_BIT(data , 3));
	//enable pulse
	dio_set_channel_state(LCD_EN , low);
	dio_set_channel_state(LCD_EN , high);
	_delay_us(1); //enable cycle time
	dio_set_channel_state(LCD_EN , low);
	_delay_us(100);
}
static void set_xy_cursor_pos(u8_t row , u8_t col)
{
	u8_t ddram_address;
	ddram_address = 0x40 * (row-1) + (col-1);
	SET_BIT(ddram_address , 7);
	send_instruction(ddram_address);
	_delay_us(100);
}
void lcd_display_char(u8_t chr , u8_t row , u8_t col)
{
	set_xy_cursor_pos(row , col);
	send_data(chr);
}
void lcd_display_char_cp(u8_t chr)
{
	send_data(chr);
}
void lcd_display_text(u8_t* text , u8_t row , u8_t col)
{
	u8_t i=0;
	set_xy_cursor_pos(row , col); //set initial pos
	for(i= 0 ; text[i]!=0 ; i++ )
	{
		send_data(text[i]);
		// lcd_display_char(text[i] , row , col++);
	}
}
void lcd_display_text_cp(u8_t* text)
{
	u8_t i=0;
	for(i= 0 ; text[i]!=0 ; i++ )
	{
		send_data(text[i]);
	}
}

void lcd_display_clear()
{
	send_instruction(DISPLAY_CLEAR_CMD);
	_delay_ms(2);
}
