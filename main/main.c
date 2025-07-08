/*
 * Author: Nachus01
 * Project: ESP32_DevKit-V1_Bringup
 * Version: 1.2.1.1
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "GPIOManager.h"

int buttonCurrentState = 0;
int buttonPreviousState = 1;
static const char *TAG = "GPIO demo";

void app_main(void)
{
    //initialize GPIO
    GPIOM_init();

    while(true)
    {
        buttonCurrentState = gpio_get_level(GPIO_NUM_22);
        if(buttonCurrentState)
        {
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

        GPIOM_followInput(GPIO_NUM_22, GPIO_NUM_23);

        vTaskDelay(10);
    }
}
