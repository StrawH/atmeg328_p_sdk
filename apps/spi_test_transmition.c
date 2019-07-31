/*
 * spi_test_transmition.c
 *
 *  Created on: Jul 29, 2019
 *      Author: mohamed
 */
#define F_CPU  16000000UL
#include <util/delay.h>
#include "../mcal/spi/spi.h"

void test_SPI_sending(void)
{
	u8_t i = 0x20;
	_delay_ms(100);
	init_spi(SPI_MASTER_OSC_DIV128 , SPI_CLK_IDLE_LOW , SPI_SAMPLE_RAISING_EDGE);
	while(1)
	{
		spi_write(i);
		i++;
		_delay_ms(1000);
	}
}
