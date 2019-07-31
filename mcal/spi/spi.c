/*
 * spi.c
 *
 *  Created on: Jul 25, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#include "../../mcal/dio/mcal_dio.h"
#include "../../utils/bit_math.h"
#include "spi_atmega328p_reg.h"
#include "spi.h"
#define SPEED_MASK 0xFC
#define SS_PIN   dio_channel_rb2 // slave select(SS)
#define MOSI_PIN dio_channel_rb3 // master out slave in(SDO)
#define MISO_PIN dio_channel_rb4 // master in slave out(SDi)
#define CLK_PIN  dio_channel_rb5
void init_spi(spi_mode_t mode, spi_transmit_edge_t transmit_edge, spi_clock_idle_t clock_idle)
{

	// select idel level
	if(clock_idle == SPI_CLK_IDLE_LOW)
	{
		CLR_BIT( SPCR , CPOL);
	}
	else
	{
		SET_BIT( SPCR , CPOL);
	}
	// sample edge
	if(transmit_edge == SPI_SAMPLE_RAISING_EDGE)
	{
		CLR_BIT( SPCR , MSTR);
	}
	else
	{
		SET_BIT( SPCR , MSTR);
	}
	// select mode
	if (mode == SPI_SLAVE)
	{
		dio_set_channel_direction(MOSI_PIN , input);
		dio_set_channel_direction(CLK_PIN  , input);
		dio_set_channel_direction(SS_PIN , input);
		dio_set_channel_direction(MISO_PIN , output);
		CLR_BIT(SPCR , MSTR); // select slave mode

	}
	else
	{
		dio_set_channel_direction(MOSI_PIN , output);
		dio_set_channel_direction(CLK_PIN  , output);
		dio_set_channel_direction(MISO_PIN , input);
		SET_BIT(SPCR , MSTR); // select master mode
        if(mode < SPI_MASTER_OSC_DIV2)
        {
        	CLR_BIT(SPSR , SPI2X); // half speed mode
        	SPCR = (SPCR & SPEED_MASK) | mode;
        }
        else
        {
        	SET_BIT(SPSR , SPI2X); // full speed mode
        	SPCR = (SPCR & SPEED_MASK) | (mode&0x03);
        }

	}
	//enable spi
	SET_BIT( SPCR , SPE);
}
void spi_write(u8_t cData)
{
	SPDR = cData;
	/* Wait for transmission complete */
	while(READ_BIT(SPSR , SPIF) == 0);
}
u8_t spi_read(u8_t dummy_byte)
{
	/* Wait for reception complete */
	SPDR = dummy_byte;
	while(READ_BIT(SPSR , SPIF) == 0);
	return SPDR;
}
