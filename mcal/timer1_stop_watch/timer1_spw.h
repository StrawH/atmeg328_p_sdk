/*
 * timer1_spw.h
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */
#include "../../utils/custom_types.h"
#ifndef MCAL_TIMER1_STOP_WATCH_TIMER1_SPW_H_
#define MCAL_TIMER1_STOP_WATCH_TIMER1_SPW_H_

void init_stop_watch(void);
/* get the stop watch counts*/
u16_t get_stop_watch_value(void);
/* start counting */
void start_stop_watch(void);
void stop_stop_watch(void);
/* reset counts to zero*/
void reset_stop_watch(void);

#endif /* MCAL_TIMER1_STOP_WATCH_TIMER1_SPW_H_ */
