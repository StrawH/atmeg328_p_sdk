/*
 * h_bridge.h
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */

#ifndef HAL_H_BRIDGE_H_BRIDGE_H_
#define HAL_H_BRIDGE_H_BRIDGE_H_
void init_motors(void);
void move_forward(void);
void move_backward(void);
void move_clkwise(void);
void move_aclkwise(void);
void move_hold(void);
#endif /* HAL_H_BRIDGE_H_BRIDGE_H_ */
