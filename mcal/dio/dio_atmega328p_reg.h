/*
 * dio_atmega328p_reg.h
 *
 *  Created on: Jul 4, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_DIO_DIO_ATMEGA328P_REG_H_
#define MCAL_DIO_DIO_ATMEGA328P_REG_H_
#define PINB  *((volatile u8_t *)0x23)
#define DDRB  *((volatile u8_t *)0x24)
#define PORTB *((volatile u8_t *)0x25)

#define PINC  *((volatile u8_t *)0x26)
#define DDRC  *((volatile u8_t *)0x27)
#define PORTC *((volatile u8_t *)0x28)

#define PIND  *((volatile u8_t *)0x29)
#define DDRD  *((volatile u8_t *)0x2A)
#define PORTD *((volatile u8_t *)0x2B)

#endif /* MCAL_DIO_DIO_ATMEGA328P_REG_H_ */
