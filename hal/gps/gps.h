/*
 * gps.h
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef HAL_GPS_GPS_H_
#define HAL_GPS_GPS_H_
typedef struct
{
	u8_t lat[12];
	u8_t lon[12];
	u8_t time[12];
	bool_t is_valid_reading;
}gps_packet_t;

void init_gps();
bool_t get_gps_reading();
gps_packet_t get_gps_informations();

#endif /* HAL_GPS_GPS_H_ */
