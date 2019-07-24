/*
 * rfid.h
 *
 *  Created on: Jul 22, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef HAL_RFID_RFID_H_
#define HAL_RFID_RFID_H_

void init_rfid(void);
bool_t get_rfid_reading(void);
char* get_rfid_record(void);

#endif /* HAL_RFID_RFID_H_ */
