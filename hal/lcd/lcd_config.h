/*
 * lcd_config.h
 *
 *  Created on: Jul 11, 2019
 *      Author: mohamed
 */
#include "../../mcal/dio/mcal_dio.h"
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_MODE MODE_4
//RW connected to ground write mode
#define LCD_RS  dio_channel_rb0
#define LCD_EN  dio_channel_rb1
#if LCD_MODE == MODE_8
	#define LCD_B0  dio_channel_rd0
	#define LCD_B1  dio_channel_rd1
	#define LCD_B2  dio_channel_rd2
	#define LCD_B3  dio_channel_rd3
#endif
#define LCD_B4  dio_channel_rb2
#define LCD_B5  dio_channel_rb3
#define LCD_B6  dio_channel_rb4
#define LCD_B7  dio_channel_rb5
#endif /* HAL_LCD_LCD_CONFIG_H_ */
