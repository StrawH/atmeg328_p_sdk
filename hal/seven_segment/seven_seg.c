/*
 * seven_seg.c
 *
 *  Created on: Jul 10, 2019
 *      Author: mohamed
 *
 */
#include "../../utils/custom_types.h"
#include "../../utils/bit_math.h"
#include "../../mcal/dio/mcal_dio.h"
#include "seven_seg.h"
#include "seven_seg_config.h"
const u8_t digits_values_cathod[]=
{63,6, 91, 79, 102, 109, 125, 7, 127, 111};
void display_digit_private(u8_t digit);

void init_seven_segment(void)
{
	dio_set_channel_direction(SEG_PINA , output);
	dio_set_channel_direction(SEG_PINB , output);
	dio_set_channel_direction(SEG_PINC , output);
	dio_set_channel_direction(SEG_PIND , output);
	dio_set_channel_direction(SEG_PINE , output);
	dio_set_channel_direction(SEG_PINF , output);
	dio_set_channel_direction(SEG_PING , output);
	#if SEVEN_SEGMENT_TYPE == COM_CATHOD
		display_digit_private(0);
	#elif SEVEN_SEGMENT_TYPE == COM_ANODE
		display_digit_private(255);
	#else
		# warning "you choose the type of the seven segment #define SEVEN_SEGMENT_TYPE COM_CATHOD"
	#endif
}
void display_digit(u8_t digit)
{
     if(digit>=0 && digit<10)
     {

        #if SEVEN_SEGMENT_TYPE == COM_CATHOD
    	     display_digit_private(digits_values_cathod[digit]);
	    #else
    	     display_digit_private(~digits_values_cathod[digit]);
        #endif

     }
	 dio_set_channel_state(dio_channel_rb0 , low);
	 dio_set_channel_state(dio_channel_rb0 , high);

}

void display_digit_private(u8_t digit)
{
	dio_set_channel_state(SEG_PINA , READ_BIT(digit , 0));
	dio_set_channel_state(SEG_PINB , READ_BIT(digit , 1));
	dio_set_channel_state(SEG_PINC , READ_BIT(digit , 2));
	dio_set_channel_state(SEG_PIND , READ_BIT(digit , 3));
	dio_set_channel_state(SEG_PINE , READ_BIT(digit , 4));
	dio_set_channel_state(SEG_PINF , READ_BIT(digit , 5));
	dio_set_channel_state(SEG_PING , READ_BIT(digit , 6));
}

