/*
 * STM32H723xx_gpio.c
 *
 *  Created on: Oct. 1, 2023
 *      Author: jbate
 */

#include "STM32H723xx_gpio.h"

/*
 * Peripheral clock setup
 */
void GPIO_peri_clock_control(GPIO_RegDef_t *p_gpio_x, uint8_t en_state) {

}


void GPIO_init(GPIO_Handle_t* p_gpio_handle) {

}


void GPIO_deinit(GPIO_RegDef_t *p_gpio_x) {

}


uint8_t GPIO_read_from_input_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin) {

}


uint16_t GPIO_read_from_input_port(GPIO_RegDef_t *p_gpio_x) {

}


void GPIO_write_to_output_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin, uint8_t val) {

}


void GPIO_write_to_output_port(GPIO_RegDef_t *p_gpio_x, uint16_t val) {

}


void GPIO_toggle_output_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin) {

}


void GPIO_irq_config(uint8_t irq_number, uint8_t irq_priority, uint8_t en_state) {

}


void GPIO_irq_handling(uint8_t pin) {

}

