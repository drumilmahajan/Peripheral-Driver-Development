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
	* @brief Configures the mode of a pin : input, output, alt or analog mode	
	* @param *GPIOx : GPIOx port base address
	* @param pin_no : GPIO pin number
	* @param op_type: output type to be configured with
	* @retval None
	*/
static void hal_gpio_configure_pin_otype(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t op_type) {
	GPIOx->OTYPER |= (op_type << pin_no);
}

/**
	* @brief Configures the mode of a pin : input, output, alt or analog mode	
	* @param *GPIOx : GPIOx port base address
	* @param pin_no : GPIO pin number
	* @param speed: speed the pin has to be configured to.
	* @retval None
	*/
static void hal_gpio_configure_pin_speed(GPIO_TypeDef * GPIOx, uint16_t pin_no, uint32_t speed) {
	GPIOx->OSPEEDR |= (speed << ( 2 * pin_no ));
}