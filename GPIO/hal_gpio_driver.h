#ifndef _HAL_GPIO_DRIVER_H
#define _HAL_GPIO_DRIVER_H

// Including microprocesser specific header 
// Here microprocessor is stm32f407vgt6 based discovery board
#include "stm32f407xx.h"


// Defining MACROS for GPIO pin Initilization.

// GPIO Mode Setting values
#define GPIO_PIN_INPUT_MODE							((uint32_t) 0x00)
#define GPIO_PIN_OUPUT_MODE							((uint32_t) 0x01)
#define GPIO_PIN_ALT_FUN_MODE		 				((uint32_t) 0x02)
#define GPIO_PIN_ANALOG_MODE						((uint32_t) 0x03)

// GPIO operation type selection values
#define GPIO_PIN_OP_TYPE_PUSHPULL			 	((uint32_t) 0x00)
#define GPIO_PIN_OP_TYPE_OPEN_DRAIN			((uint32_t) 0x01)

// GPIO speed type selection values
#define GPIO_PIN_SPEED_LOW			 				((uint32_t) 0x00)
#define GPIO_PIN_SPEED_MEDIUM			 			((uint32_t) 0x01)
#define GPIO_PIN_SPEED_HIGH			 				((uint32_t) 0x02)
#define GPIO_PIN_SPEED_VERY_HIGH			 	((uint32_t) 0x03)