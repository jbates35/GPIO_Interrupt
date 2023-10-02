/*
 * STM32H723xx_gpio.h
 *
 *  Created on: Oct. 1, 2023
 *      Author: jbates
 */

#ifndef INC_STM32H723XX_GPIO_H_
#define INC_STM32H723XX_GPIO_H_

#include "STM32H723xx_defines.h"

typedef struct {
	uint8_t GPIO_pin_number;
	uint8_t GPIO_pin_mode;
	uint8_t GPIO_pin_speed;
	uint8_t GPIO_pin_pupd_control;
	uint8_t GPIO_pin_out_type;
	uint8_t GPIO_pin_alt_func_mode;
} GPIO_PinConfig_t;

typedef struct {
	GPIO_RegDef_t *p_GPIO_x;				//Holds the base address of the GPIO port which the pin belongs
	GPIO_PinConfig_t GPIO_pin_config;	//Holds the GPIO pin configuration settings
} GPIO_Handle_t;

/*
 * Peripheral clock setup
 */
void GPIO_peri_clock_control(GPIO_RegDef_t *p_gpio_x, uint8_t en_state);

/*
 * Init and de-init of GPIO
 */
void GPIO_init(GPIO_Handle_t* p_gpio_handle);
void GPIO_deinit(GPIO_RegDef_t *p_gpio_x);

/*
 * Data read and write
 */
uint8_t GPIO_read_from_input_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin);
uint16_t GPIO_read_from_input_port(GPIO_RegDef_t *p_gpio_x);
void GPIO_write_to_output_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin, uint8_t val);
void GPIO_write_to_output_port(GPIO_RegDef_t *p_gpio_x, uint16_t val);
void GPIO_toggle_output_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin);

/*
 * IRQ configuration and IRQ handling
 */
void GPIO_irq_config(uint8_t irq_number, uint8_t irq_priority, uint8_t en_state);
void GPIO_irq_handling(uint8_t pin);

#endif /* INC_STM32H723XX_GPIO_H_ */
