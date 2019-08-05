/*
 * h_bridge.c
 *
 *  Created on: Aug 1, 2019
 *      Author: mohamed
 */
#include "h_bridge.h"
#include "h_bridge_config.h"
#include "../../mcal/dio/mcal_dio.h"
void init_motors(void)
{
	dio_set_channel_direction(IN1_PIN , output);
	dio_set_channel_direction(IN2_PIN , output);
	dio_set_channel_direction(IN3_PIN , output);
	dio_set_channel_direction(IN4_PIN , output);
	dio_set_channel_state(IN1_PIN , low);
	dio_set_channel_state(IN2_PIN , low);
	dio_set_channel_state(IN3_PIN , low);
	dio_set_channel_state(IN4_PIN , low);
}
void move_forward(void)
{
	dio_set_channel_state(IN1_PIN , high);
	dio_set_channel_state(IN2_PIN , low);

	dio_set_channel_state(IN3_PIN , high);
	dio_set_channel_state(IN4_PIN , low);
}
void move_backward(void)
{
	dio_set_channel_state(IN1_PIN , low);
	dio_set_channel_state(IN2_PIN , high);

	dio_set_channel_state(IN3_PIN , low);
	dio_set_channel_state(IN4_PIN , high);
}
void move_clkwise(void)
{
	dio_set_channel_state(IN1_PIN , low);
	dio_set_channel_state(IN2_PIN , high);

	dio_set_channel_state(IN3_PIN , high);
	dio_set_channel_state(IN4_PIN , low);
}
void move_aclkwise(void)
{
	dio_set_channel_state(IN1_PIN , high);
	dio_set_channel_state(IN2_PIN , low);

	dio_set_channel_state(IN3_PIN , low);
	dio_set_channel_state(IN4_PIN , high);
}
void move_hold(void)
{
	dio_set_channel_state(IN1_PIN , low);
	dio_set_channel_state(IN2_PIN , low);
	dio_set_channel_state(IN3_PIN , low);
	dio_set_channel_state(IN4_PIN , low);
}
