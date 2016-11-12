#include "led.h"

/**
	* @brief : Initilizes the LEDs
	* @param None
	* @retval : None
	*/

void led_init() {

	gpio_pin_conf_t led_pin_conf;
	
	//Enable clock for the GPIO D
	_HAL_RCC_GPIOD_CLK_ENABLE();
	
	//Defining values in the struct for LED ORANGE
	led_pin_conf.pin = LED_ORANGE;
	led_pin_conf.mode = GPIO_PIN_OUPUT_MODE;
	led_pin_conf.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	led_pin_conf.speed = GPIO_PIN_SPEED_MEDIUM;
	led_pin_conf.pull = GPIO_PIN_NO_PULL_UP_DOWN;
	
	// Passing the values to the init function.
	hal_gpio_init(GPIOD, &led_pin_conf);
	
	//Doing the same for LED BLUE RED and GREEN
	led_pin_conf.pin = LED_BLUE;
	hal_gpio_init(GPIOD, &led_pin_conf);
	
	led_pin_conf.pin = LED_GREEN;
	hal_gpio_init(GPIOD, &led_pin_conf);
	
	led_pin_conf.pin = LED_RED;
	hal_gpio_init(GPIOD, &led_pin_conf);
	

}

int main(void) {

	// Initializing LED
	led_int();
}