/*
 * seven_seg.h
 *
 *  Created on: Jul 10, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEG_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEG_H_
#define COM_ANODE 0
#define COM_CATHOD 1
void init_seven_segment(void);
void display_digit(u8_t digit);
#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEG_H_ */
