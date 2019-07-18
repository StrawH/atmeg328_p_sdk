/*
 * lcd.h
 *
 *  Created on: Jul 11, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#define DISPLAY_OFF_CMD (u8_t)0x08
#define DISPLAY_ON_CMD (u8_t)0x0E
#define DISPLAY_CLEAR_CMD (u8_t)0x01

#define MODE_4 0
#define MODE_8 1
void init_lcd(void);
// row started from 1
// col started from 1
void lcd_display_char(u8_t chr , u8_t row , u8_t col);
void lcd_display_char_cp(u8_t chr);
void lcd_display_text(u8_t* text , u8_t row , u8_t col);
void lcd_display_text_cp(u8_t* text);
void lcd_display_clear();
#endif /* HAL_LCD_LCD_H_ */
