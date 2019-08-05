/*
 * timer1_atmega328p_reg.h
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_TIMER1_STOP_WATCH_TIMER1_ATMEGA328P_REG_H_
#define MCAL_TIMER1_STOP_WATCH_TIMER1_ATMEGA328P_REG_H_

#define TCCR1A  *((volatile u8_t *)0x80)
#define TCCR1B  *((volatile u8_t *)0x81)
#define TCCR1C  *((volatile u8_t *)0x82)

#define TCNT1H  *((volatile u8_t *)0x85)
#define TCNT1L  *((volatile u8_t *)0x84)


#define OCR1AH  *((volatile u8_t *)0x89)
#define OCR1AL  *((volatile u8_t *)0x88)

#define OCR1BH  *((volatile u8_t *)0x8B)
#define OCR1BL  *((volatile u8_t *)0x8A)

#define ICR1H  *((volatile u8_t *)0x87)
#define ICR1L  *((volatile u8_t *)0x86)

#endif /* MCAL_TIMER1_STOP_WATCH_TIMER1_ATMEGA328P_REG_H_ */
