#include <stdint.h>
#include "hal_gpio_driver.h"


/* Static helper function*/
/* These static function won't be exposed to the application */

/**
	* @brief Configures the mode of a pin : input, output, alt or analog mode	
	* @param *GPIOx : GPIOx port base address
	* @param pin_no : GPIO pin number
	* @param mode 	: mode to be set/configured to the given pin
	* @retval None
	*/
static void hal_gpio_configure_pin_mode(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t mode) {
	GPIOx->MODER |= (mode << (2 * pin_no ));
}

/**
	* @brief Configures the output type, open drain or push pull. 
	* @param *GPIOx : GPIOx port base address
	* @param pin_no : GPIO pin number
	* @param op_type: output type to be configured with
	* @retval None
	*/
static void hal_gpio_configure_pin_otype(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t op_type) {
	GPIOx->OTYPER |= (op_type << pin_no);
}

/**
	* @brief Configures the speed of a pin : low, medium, high, very high	
	* @param *GPIOx : GPIOx port base address
	* @param pin_no : GPIO pin number
	* @param speed: speed the pin has to be configured to.
	* @retval None
	*/
static void hal_gpio_configure_pin_speed(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t speed) {
	GPIOx->OSPEEDR |= (speed << ( 2 * pin_no ));
}

/**
	* @brief Configures the pull up or pull down resistor. 
	* @param *GPIOx : GPIOx port base address
	* @param pin_no : GPIO pin number
	* @param pupd: pull up resistor or pull down resistor or nothing.
	* @retval None
	*/
static void hal_gpio_configure_pin_pupd(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t pupd) {
	GPIOx->PUPDR |= (pupd << ( 2 * pin_no ));
}

/* Non static functions, will be accesible to the application. */

/**
	* @brief : Initializes the GPIO pin
	* @param : *GPIOx : GPIOx port base register
	* @param : *gpio_pin_conf : Pointer to the pin conf structure sent by application
	* @retval : None.
*/
void hal_gpio_init(GPIO_TypeDef * GPIOx, gpio_pin_conf_t *gpio_pin_conf) {
	hal_gpio_configure_pin_mode(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->mode);
	hal_gpio_configure_pin_speed(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->speed);
	hal_gpio_configure_pin_otype(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->op_type);
	hal_gpio_configure_pin_pupd(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->pull);
}

/**
	* @brief: sets the alternate functionality of the given pin if alt fun is selected as the mode
	* @param *GPIOx : GPIOx port base address
	* @param  pin_no : GPIO pin number
	* @param: alt_fun_value : alternate function to be configured with 
	*/
void hal_gpio_set_alt_fun(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t alt_fun_val) { 
	if( pin_no <= 7 ) {
		GPIOx->AFR[0] |= ( alt_fun_val << ( 4 * pin_no ));
	}
	else {
		GPIOx->AFR[1] |= ( alt_fun_val << ( 4 * ( pin_no % 8 ) ));
	}
}

/**
  * @brief Read a value from a given pin. 
	* @param *GPIOx : GPIOx port base address
	* @param  pin_no : GPIO pin number
	* @retval uint8_t: Value read from the pin. 
	*/
uint8_t hal_gpio_read_from_pin(GPIO_TypeDef * GPIOx, uint16_t pin_no) {
	uint8_t value;
	
	/* Read value from IDR and shift it right by pin numbers.
		 AND it with 1 so that only the desired value is read. */
	value = ((GPIOx->IDR >> pin_no) & 0x00000001);
	return value;
}

/**
  * @brief Read a value from a given pin. 
	* @param *GPIOx : GPIOx port base address
	* @param  pin_no : GPIO pin number
	* @param value : value to be written to the given pin
	* @retval None.
	*/

void hal_gpio_write_to_pin(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint8_t value ) {
	if(value) {
		GPIOx->ODR |= (1 << pin_no);
	}
	else {
		GPIOx->ODR &= !(1 << pin_no);
	}
}

/**
	* @brief  Configure the interrupt for a given pin number   
	* @param  pin_no : GPIO pin number 
	* @param  edge_sel   :  Triggering edge slection value of type "int_edge_sel_t"
	* @retval None
	*/
void hal_gpio_configure_interrupt(uint16_t pin_no, int_edge_sel_t edge_sel) {

	
	// Selecting the interrupt edge as passed by the user
	if (edge_sel == INT_RISING_EDGE) {
		EXTI->RTSR |= ( 1 << pin_no ) ; 
	}
	else if (edge_sel == INT_FALLING_EDGE) {
		EXTI->FTSR |= ( 1 << pin_no ) ;
	}
	else if ( edge_sel == INT_RISING_FALLING_EDGE ) {
		EXTI->FTSR |= ( 1 << pin_no ) ;
		EXTI->RTSR |= ( 1 << pin_no ) ;
	}
	

	
	
}

/**
	* @brief  Enable the interrupt for a give pin number and irq number  
	* @param  pin_no : GPIO pin number 
	* @param  irq_no   :  irq_number to be enabled in NVIC 
	* @retval None
	*/
void hal_gpio_enable_interrupt(uint16_t pin_no, IRQn_Type irq_no) {
	
	// Unmaksing the interrupt so that it can be seen by Processor
	// that is enabling the interrupt at the EXTI side
	EXTI->IMR |= ( 1 << pin_no);
	// Enabling the inerrupt for the ginve IRQ number at NVIC side.
	NVIC_EnableIRQ(irq_no);
}

/**
	* @brief  Clear the sticky interrupt pending bit if set 
	* @param  pin_no : GPIO pin number 
	* @retval None
	*/
void 	hal_gpio_clear_interrupt(uint16_t pin_no) {
		// Clearing the interrupt after it has been serviced. 
		
		// If interrupt is pending
		if ( EXTI->PR & ( 1 << pin_no ))
			EXTI->PR |= ( 1 << pin_no );
}









