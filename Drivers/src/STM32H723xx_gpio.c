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
 * @param p_GPIO_x GPIO register information
 * @param en_state Enable state - 1 for enable and 0 for disable
 */
void GPIO_peri_clock_control(GPIO_RegDef_t *p_GPIO_x, uint8_t en_state) {
	if(p_GPIO_x == NULL) 
		return;

    static GPIO_RegDef_t *const GPIOx_BASE_ADDRS[11] = {
        GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, NULL, GPIOJ, GPIOK
    };

    for(int i = 0; i < sizeof(GPIOx_BASE_ADDRS)/sizeof(GPIO_RegDef_t*); i++) {
    	if(p_GPIO_x != GPIOx_BASE_ADDRS[i])
    		continue;

        if(en_state == ENABLE)
            RCC->AHB4ENR |= (1 << i);
		else
            RCC->AHB4ENR &= ~(1 << i);

        break;
	}
}

/**
 * @brief Initializes the GPIO port
 * 
 * @param p_GPIO_handle GPIO Handle which has all the configuration information
 */
void GPIO_init(GPIO_Handle_t* p_GPIO_handle) {
	if(p_GPIO_handle == NULL)
		return;

	//Create pointers to the GPIO port and the pin configuration for easier access/readability
	GPIO_RegDef_t *gpiox = p_GPIO_handle->p_GPIO_x;
	GPIO_PinConfig_t *cfg = &(p_GPIO_handle->GPIO_pin_config);

	//For easy bit-shifting, dshift is 2*pin number, whereas sshift is just pin_number
	const uint8_t dshift = 2 * cfg->GPIO_pin_number;
	const uint8_t sshift = cfg->GPIO_pin_number;
		
	//Set mode
	if(cfg->GPIO_pin_mode <= GPIO_MODE_ANALOG) {
		gpiox->MODER &= ~(0x3 << dshift);
		gpiox->MODER |= cfg->GPIO_pin_mode << dshift;
	} else {
		//TODO: Code later for interrupt
	}

	//Set output speed - clear bits to 00 and then set
	gpiox->OSPEEDR &= ~(0x3 << dshift);
	gpiox->OSPEEDR = cfg->GPIO_pin_speed << dshift; 

	//Set output type - clear bits to 0 first and then set
	gpiox->OTYPER &= ~(0x1 << sshift);
	gpiox->OTYPER |= cfg->GPIO_pin_out_type << sshift;
	
	//Set pullup/pulldown resistor - clear bits to 00 and then set
	gpiox->PUPDR &= ~(0x3 << dshift);
	gpiox->PUPDR |= cfg->GPIO_pin_pupd_control << dshift;

	//Configure alt functionality - clear bits to 0000 and then set
	const uint8_t alt_no = cfg->GPIO_pin_number / 8;
	const uint8_t alt_shift = (cfg->GPIO_pin_number * 4)%32;
	gpiox->AFR[alt_no] &= ~(0xF << alt_shift);
	gpiox->AFR[alt_no] |= cfg->GPIO_pin_alt_func_mode << alt_shift;
}

/**
 * @brief De-initializes the GPIO port
 * 
 * @param p_GPIO_x GPIO port information
 */
void GPIO_deinit(GPIO_RegDef_t *p_GPIO_x) {
	if(p_GPIO_x == NULL) 
		return;

    static GPIO_RegDef_t *const GPIOx_BASE_ADDRS[11] = {
        GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, NULL, GPIOJ, GPIOK
    };	

    for(int i = 0; i < sizeof(GPIOx_BASE_ADDRS)/sizeof(GPIO_RegDef_t*); i++) {
    	if(p_GPIO_x != GPIOx_BASE_ADDRS[i])
    		continue;

		RCC->AHB4RSTR |= (1 << i);
		RCC->AHB4RSTR &= ~(1 << i);

        break;
	}
}

/**
 * @brief Reads the value of the given pin
 * 
 * @param p_GPIO_x GPIO port information
 * @param pin Pin to be read
 * @return uint8_t Value of the input associated with the pin
 */
uint8_t GPIO_read_from_input_pin(GPIO_RegDef_t *p_GPIO_x, uint8_t pin) {
	if(p_GPIO_x == NULL)
		return;
	
	return (p_GPIO_x->IDR >> pin) & 0x1;
}

/**
 * @brief Read the entire value of the GPIO port
 * 
 * @param p_GPIO_x GPIO port information
 * @return uint16_t Word containing the value of the GPIO port
 */
uint16_t GPIO_read_from_input_port(GPIO_RegDef_t *p_GPIO_x) {
	if(p_GPIO_x == NULL)
		return;
	
	return (uint16_t) p_GPIO_x->IDR;
}

/**
 * @brief Value to be written to the given pin, when configured as output
 * 
 * @param p_GPIO_x GPIO port information
 * @param pin Pin which will be read
 * @param val Output value - 1 for high, 0 for low
 */
void GPIO_write_to_output_pin(GPIO_RegDef_t *p_GPIO_x, uint8_t pin, uint8_t val) {
	if(p_GPIO_x == NULL)
		return;
	
	if(val == 1)
		p_GPIO_x->ODR |= (val << pin);
	else
		p_GPIO_x->ODR &= ~(val << pin);
}

/**
 * @brief Value to write to entire GPIO port, when configured as output
 * 
 * @param p_GPIO_x GPIO port information
 * @param val Word containing the value to be written to the GPIO port
 */
void GPIO_write_to_output_port(GPIO_RegDef_t *p_GPIO_x, uint16_t val) {
	if(p_GPIO_x == NULL)
		return;

	p_GPIO_x->ODR = val;
}

/**
 * @brief Toggle the output value of the given pin
 * 
 * @param p_GPIO_x GPIO port information
 * @param pin Pin to be toggled
 */
void GPIO_toggle_output_pin(GPIO_RegDef_t *p_GPIO_x, uint8_t pin) {
	if(p_GPIO_x == NULL)
		return;

	p_GPIO_x->ODR ^= (1 << pin);
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

