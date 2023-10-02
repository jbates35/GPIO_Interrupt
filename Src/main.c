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

#include "STM32H723xx_defines.h"
#include "STM32H723xx_gpio.h"

#define YELLOW_LED (1 << 0)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
  RCC_RegDef_t *rcc = RCC;
  GPIOE_PCLK_EN();

  GPIO_RegDef_t *gpioe = GPIOE;

  //Set yellow LED for blinking later
  gpioe->MODER |= (01 << 0);

  //Shitty counter for now
  int i = 0;
  int yled_state = 0;

  /* Loop forever */ 
  for(;;) {
    if(i++<300000)
      continue;

    i = 0;

    if(yled_state == 0) {
      yled_state = 1;
      gpioe->ODR |= (1 << 0);
    } else {
      yled_state = 0;
      gpioe->ODR &= ~(1 << 0);
    }
  }
}
