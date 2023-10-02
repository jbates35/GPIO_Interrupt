/*
 * STM32H723xx_gpio.c
 *
 *  Created on: Oct. 1, 2023
 *      Author: jbate
 */

#include "STM32H723xx_gpio.h"

#include <stdio.h>

/*
 * Peripheral clock setup
 */

/**
 * @brief Allows the clock for the given GPIO port to be enabled or disabled
 * 
 * @param p_gpio_x GPIO register information
 * @param en_state Enable state - 1 for enable and 0 for disable
 */
void GPIO_peri_clock_control(GPIO_RegDef_t *p_gpio_x, uint8_t en_state) {
    static GPIO_RegDef_t *const GPIOx_BASE_ADDRS[11] = {
        GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, NULL, GPIOJ, GPIOK
    };

    for(int i = 0; i < sizeof(GPIOx_BASE_ADDRS)/sizeof(GPIO_RegDef_t*); i++) {
        if(p_gpio_x == GPIOx_BASE_ADDRS[i] && en_state == ENABLE) {
            RCC->AHB4ENR |= (1 << i);
            break;
        } else if (p_gpio_x == GPIOx_BASE_ADDRS[i] && en_state == DISABLE) {
            RCC->AHB4ENR &= ~(1 << i);
            break;
        }
    }
} 

/**
 * @brief Initializes the GPIO port
 * 
 * @param p_gpio_handle GPIO Handle which has all the configuration information
 */
void GPIO_init(GPIO_Handle_t* p_gpio_handle) {

}

/**
 * @brief De-initializes the GPIO port
 * 
 * @param p_gpio_x GPIO port information
 */
void GPIO_deinit(GPIO_RegDef_t *p_gpio_x) {

}

/**
 * @brief Reads the value of the given pin
 * 
 * @param p_gpio_x GPIO port information
 * @param pin Pin to be read
 * @return uint8_t Value of the input associated with the pin
 */
uint8_t GPIO_read_from_input_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin) {

}

/**
 * @brief Read the entire value of the GPIO port
 * 
 * @param p_gpio_x GPIO port information
 * @return uint16_t Word containing the value of the GPIO port
 */
uint16_t GPIO_read_from_input_port(GPIO_RegDef_t *p_gpio_x) {

}

/**
 * @brief Value to be written to the given pin, when configured as output
 * 
 * @param p_gpio_x GPIO port information
 * @param pin Pin which will be read
 * @param val Output value - 1 for high, 0 for low
 */
void GPIO_write_to_output_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin, uint8_t val) {

}

/**
 * @brief Value to write to entire GPIO port, when configured as output
 * 
 * @param p_gpio_x GPIO port information
 * @param val Word containing the value to be written to the GPIO port
 */
void GPIO_write_to_output_port(GPIO_RegDef_t *p_gpio_x, uint16_t val) {

}

/**
 * @brief Toggle the output value of the given pin
 * 
 * @param p_gpio_x GPIO port information
 * @param pin Pin to be toggled
 */
void GPIO_toggle_output_pin(GPIO_RegDef_t *p_gpio_x, uint8_t pin) {

}

/**
 * @brief Configure the IRQ for the given pin
 * 
 * @param irq_number IRQ number to be configured
 * @param irq_priority Priority of the IRQ
 * @param en_state State of the IRQ - 1 for enable, 0 for disable
 */
void GPIO_irq_config(uint8_t irq_number, uint8_t irq_priority, uint8_t en_state) {

}

/**
 * @brief Set the IRQ handling for the given pin
 * 
 * @param pin Pin to have IRQ handling set
 */
void GPIO_irq_handling(uint8_t pin) {

}

