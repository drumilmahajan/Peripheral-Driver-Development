#ifndef _HAL_GPIO_DRIVER_H
#define _HAL_GPIO_DRIVER_H

/* Including microprocesser specific header */
/* Here microprocessor is stm32f407vgt6 based discovery board */
#include "stm32f407xx.h"


/* Defining MACROS for GPIO pin Initilization. */

/* GPIO Mode Setting values */
#define GPIO_PIN_INPUT_MODE							((uint32_t) 0x00)
#define GPIO_PIN_OUPUT_MODE							((uint32_t) 0x01)
#define GPIO_PIN_ALT_FUN_MODE		 				((uint32_t) 0x02)
#define GPIO_PIN_ANALOG_MODE						((uint32_t) 0x03)

/* GPIO operation type selection values */
#define GPIO_PIN_OP_TYPE_PUSHPULL			 	((uint32_t) 0x00)
#define GPIO_PIN_OP_TYPE_OPEN_DRAIN			((uint32_t) 0x01)

/* GPIO speed type selection values */
#define GPIO_PIN_SPEED_LOW			 				((uint32_t) 0x00)
#define GPIO_PIN_SPEED_MEDIUM			 			((uint32_t) 0x01)
#define GPIO_PIN_SPEED_HIGH			 				((uint32_t) 0x02)
#define GPIO_PIN_SPEED_VERY_HIGH			 	((uint32_t) 0x03)

/* GPIO PULL UP/PULLDOWN selection values */
#define GPIO_PIN_NO_PULL_UP_DOWN				((uint32_t) 0x00)
#define GPIO_PIN_PULL_UP								((uint32_t) 0x01) 
#define GPIO_PIN_PULL_DOWN							((uint32_t) 0x02)

/* Redefining GPIO Port Address */
#define GPIO_PORT_A GPIOA
#define GPIO_PORT_B GPIOB 
#define GPIO_PORT_C GPIOC
#define GPIO_PORT_D GPIOD
#define GPIO_PORT_E GPIOE
#define GPIO_PORT_F GPIOF
#define GPIO_PORT_G GPIOG
#define GPIO_PORT_H GPIOH
#define GPIO_PORT_I GPIOI

/* Macros to enable clock for various GPIO Ports in RCC register */
#define _HAL_RCC_GPIOA_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 0))
#define _HAL_RCC_GPIOB_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 1))
#define _HAL_RCC_GPIOC_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 2))
#define _HAL_RCC_GPIOD_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 3))
#define _HAL_RCC_GPIOE_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 4))
#define _HAL_RCC_GPIOF_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 5))
#define _HAL_RCC_GPIOG_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 6))
#define _HAL_RCC_GPIOH_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 7))
#define _HAL_RCC_GPIOI_CLK_ENABLE()						(RCC->AHB1ENR |= (1 << 8))


/* Data structure initialization for GPIO Pin Initilization */

/**
* @brief GPIO pin configuration structure
*				 This structure will be filled and passed to driver by the application to
*				 initialize the GPIO pin.
*/

typedef struct
{
	uint32_t pin;
}

