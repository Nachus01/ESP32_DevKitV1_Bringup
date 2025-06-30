/*
 * Author: Nachus01
 * Project: ESP32_DevKit-V1_Bringup
 * Version: 1.1.1.1
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

int buttonCurrentState = 0;
int buttonPreviousState = 1;
static const char *TAG = "GPIO demo";

void app_main(void)
{
    //Configure Input
    gpio_set_direction(GPIO_NUM_22,GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_22,GPIO_PULLUP_ONLY);

    //Configure Output
    gpio_set_direction(GPIO_NUM_26,GPIO_MODE_OUTPUT);

    while(true)
    {
        buttonCurrentState = gpio_get_level(GPIO_NUM_22);
        if(buttonCurrentState)
        {
            gpio_set_level(GPIO_NUM_26,buttonCurrentState);
            if (buttonPreviousState)
            {
                //do nothing
            }
            else
            {
                ESP_LOGI(TAG, "The button became pressed, Turning the LED ON!");
                buttonPreviousState = 1;
            }
        }
        else
        {
            gpio_set_level(GPIO_NUM_26,buttonCurrentState);
            if (buttonPreviousState)
            {
                ESP_LOGI(TAG, "The button became de-pressed, Turning the LED OFF!");
                buttonPreviousState = 0;
            }
            else
            {
                //do nothing
            }
        }

       vTaskDelay(10);
    }
}
