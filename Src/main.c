/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Jimmy Bates
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "STM32H723xx_gpio.h"
#include "STM32H723xx_defines.h"

#define YELLOW_LED (1 << 0)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void project_init(void);

int main(void)
{
	project_init();

	for(;;) {  }
}

void project_init() {

	//GPIO initialization
	GPIO_Handle_t gpio_handle;
	GPIO_PinConfig_t *cfg = &(gpio_handle.GPIO_pin_config);

	//Enable peripheral clock for GPIO E
	GPIO_peri_clock_control(GPIOE, ENABLE);

	//LED Setup for GPIO E Pin 0
	gpio_handle.p_GPIO_x = GPIOE;
	cfg->GPIO_pin_mode = GPIO_MODE_OUT;
	cfg->GPIO_pin_number = 0;
	cfg->GPIO_pin_out_type = GPIO_OP_TYPE_PP;
	cfg->GPIO_pin_pupd_control = GPIO_PUPDR_NONE;
	cfg->GPIO_pin_speed = GPIO_SPEED_LOW;
	cfg->GPIO_pin_alt_func_mode = 0;
	GPIO_init(&gpio_handle);

}
