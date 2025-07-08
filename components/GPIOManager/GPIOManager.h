/*
 * Author: Nachus01
 * Project: ESP32_DevKit-V1_Bringup
 * Version: 1.1.1.1
 *
 * SPDX-License-Identifier: Apache-2.0
 */

 //Dependencies
#include "driver/gpio.h"

//Function Prototypes
 void GPIOM_init();
 void GPIOM_followInput(gpio_num_t inputPin, gpio_num_t outputPin);