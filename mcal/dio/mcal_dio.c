/*
 * mcal_dio.c
 *
 *  Created on: Jul 4, 2019
 *      Author: mohamed
 */
#define PORT_SIZE 8
#include "../../utils/bit_math.h"
#include "../../utils/custom_types.h"
#include "mcal_dio.h"
#include "dio_atmega328p_reg.h"


void dio_set_channel_direction(dio_channel_t channel , dio_channel_dir_t dir )
{
   u8_t pin_number = channel%PORT_SIZE;
   dio_port_t port =  channel/PORT_SIZE;
   switch (port) {
	case dio_portb:
		if(dir == input)
		{
            CLR_BIT(DDRB , pin_number);
		}
		else if (dir == output)
		{
			SET_BIT(DDRB,pin_number);
		}else if(dir == input_pullup)
		{
			CLR_BIT(DDRB , pin_number); //config pin as input
			SET_BIT(PORTB,pin_number);//active pull-up
		}
		break;
	case dio_portc:
		if(dir == input)
		{
			CLR_BIT(DDRC , pin_number);
		}
		else if (dir == output)
		{
			SET_BIT(DDRC , pin_number);
		}
		else if(dir == input_pullup)
		{
			CLR_BIT(DDRC , pin_number);
			SET_BIT(PORTC,pin_number);//active pull-up
		}
		break;
	case dio_portd:
		if(dir == input)
		{
			CLR_BIT(DDRD , pin_number);
		}
		else if (dir == output)
		{
			SET_BIT(DDRD , pin_number);
		}
		else if(dir == input_pullup)
		{
			CLR_BIT(DDRD , pin_number);
			SET_BIT(PORTD,pin_number);//active pull-up
		}
		break;
	default:
		break;
    }
}
void dio_set_channel_state(dio_channel_t channel , dio_channel_state_t state )
{
   u8_t pin_number = channel%PORT_SIZE;
   dio_port_t port =  channel/PORT_SIZE;
   switch (port) {
	case dio_portb:
		if(state == low)
		{
            CLR_BIT(PORTB , pin_number);
		}
		else
		{
			SET_BIT(PORTB , pin_number);
		}
		break;
	case dio_portc:
		if(state == low)
		{
			CLR_BIT(PORTC , pin_number);
		}
		else
		{
			SET_BIT(PORTC , pin_number);
		}
		break;
	case dio_portd:
		if(state == low)
		{
			CLR_BIT(PORTD , pin_number);
		}
		else
		{
			SET_BIT(PORTD , pin_number);
		}
		break;
	default:
		break;
    }
}

dio_channel_state_t dio_read_channel_state(dio_channel_t channel)
{
	u8_t pin_number = channel%PORT_SIZE;
	dio_port_t port =  channel/PORT_SIZE;
	dio_channel_state_t channel_val = low;
	switch (port) {
		case dio_portb:
			channel_val = READ_BIT(PINB , pin_number);
			break;
		case dio_portc:
			channel_val = READ_BIT(PINC , pin_number);
			break;
		case dio_portd:
			channel_val = READ_BIT(PIND , pin_number);
			break;
		default:
			break;
	}
	return channel_val;

}
void dio_set_port_direction(dio_port_t port , u8_t dir )
{
	switch (port) {
		case dio_portb:
			DDRB = dir;
			break;
		case dio_portc:
			DDRC = dir;
			break;
		case dio_portd:
			DDRD = dir;
			break;
		default:
			break;
	}
}
void dio_set_port_state(dio_port_t port , u8_t state )
{
	switch (port) {
		case dio_portb:
			PORTB = state;
			break;
		case dio_portc:
			PORTC = state;
			break;
		case dio_portd:
			PORTD = state;
			break;
		default:
			break;
	}
}
