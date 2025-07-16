/*
 * Author: Nachus01
 * Project: ESP32_DevKit-V1_Bringup
 * Version: 1.1.1.1
 * 
 * Component name: GPIOManager
 * Component shortname: GPIOM
 *
 * SPDX-License-Identifier: Apache-2.0
 */

 //#includes
 #include "GPIOManager.h"
#include "esp_log.h"
static const char *GPIOTAG = "GPIO_Debug";

 //Function Definitions
  void GPIOM_init()
  {
    
    //Configure Input
    gpio_set_direction(GPIO_NUM_22,GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_22,GPIO_PULLDOWN_ONLY); //Pulldown: 3v3 is a boolean "true", everything else is a boolean "false"

    //Configure Output
    gpio_set_direction(GPIO_NUM_23,GPIO_MODE_OUTPUT);
  }

  void GPIOM_followInput(gpio_num_t inputPin, gpio_num_t outputPin)
  {
    int inputState = 0;
    inputState = gpio_get_level(inputPin);
    gpio_set_level(outputPin,inputState);
  }
