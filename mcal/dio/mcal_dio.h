/*
 * mcal_dio.h
 *
 *  Created on: Jul 4, 2019
 *      Author: mohamed
 */

#include "../../utils/custom_types.h"
#ifndef MCAL_DIO_MCAL_DIO_H_
#define MCAL_DIO_MCAL_DIO_H_
typedef enum
{
	dio_channel_rb0=0,
	dio_channel_rb1,
	dio_channel_rb2,
	dio_channel_rb3,
	dio_channel_rb4,
	dio_channel_rb5,
#ifdef USE_INTERNAL_OSC
	dio_channel_rb6,
	dio_channel_rb7,
#endif

	dio_channel_rc0 =8,
	dio_channel_rc1,
	dio_channel_rc2,
	dio_channel_rc3,
	dio_channel_rc4,
	dio_channel_rc5,
	dio_channel_rc6,
	dio_channel_rc7,

	dio_channel_rd0 =16,
	dio_channel_rd1,
	dio_channel_rd2,
	dio_channel_rd3,
	dio_channel_rd4,
	dio_channel_rd5,
	dio_channel_rd6,
	dio_channel_rd7

}dio_channel_t;
typedef enum
{
	dio_portb,
	dio_portc,
	dio_portd
}dio_port_t;
typedef enum
{
	input,
	output,
	input_pullup // activate the internal pull up resistor of the pin when it's configured as input
}dio_channel_dir_t;
typedef enum
{
	low ,
	high
}dio_channel_state_t;

void dio_set_channel_direction(dio_channel_t channel , dio_channel_dir_t dir );
void dio_set_channel_state(dio_channel_t channel , dio_channel_state_t state );
dio_channel_state_t dio_read_channel_state(dio_channel_t channel);
void dio_set_port_direction(dio_port_t port , u8_t dir );
void dio_set_port_state(dio_port_t port , u8_t state );


#endif /* MCAL_DIO_MCAL_DIO_H_ */
