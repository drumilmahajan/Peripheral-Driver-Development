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

/**
	* @brief  Turns ON the led which is connected on the given pin  
	* @param  *GPIOx : Base address of the GPIO Port
	* @param  Pin : pin number of the LED
	* @retval None
	*/
void led_turn_on(GPIO_TypeDef *GPIOx, uint16_t pin)
{
	hal_gpio_write_to_pin(GPIOx,pin, 1);
	
}

/**
	* @brief  Turns OFF the led which is connected on the given pin  
	* @param  *GPIOx : Base address of the GPIO Port
	* @param  Pin : pin number of the LED
	* @retval None
	*/
void led_turn_off(GPIO_TypeDef *GPIOx, uint16_t pin)
{
	hal_gpio_write_to_pin(GPIOx,pin, 0);
	
}

/**
	* @brief  Toggels the led which is connected on the given pin  
	* @param  *GPIOx : Base address of the GPIO Port
	* @param  Pin : pin number of the LED
	* @retval None
	*/
void led_toggle(GPIO_TypeDef *GPIOx, uint16_t pin)
{
	if(hal_gpio_read_from_pin(GPIOx,pin))
	{
		 hal_gpio_write_to_pin(GPIOx,pin, 0);
	}else
	{
		 hal_gpio_write_to_pin(GPIOx,pin, 1);
		
	}
	
}

int main(void) {
	
	// Interator variable
	uint32_t i;

	// Initializing LED
	led_init();
	
	//While loop that runs forever
	while(1) {
		
		// Turn On both LEDS
		for(i = 0; i < 50000; i++) {
		led_turn_on(GPIOD, LED_ORANGE);
		led_turn_on(GPIOD, LED_BLUE);
		}
		
		// Turn OFF Both LEDs for 500000 clock cycles
		for(i = 0; i < 50000; i++){
			led_turn_off(GPIOD, LED_ORANGE);
			led_turn_off(GPIOD, LED_BLUE);
		}
		
		
		
	}
}
