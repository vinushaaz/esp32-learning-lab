
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO          GPIO_NUM_2
#define BUTTON_GPIO       GPIO_NUM_18

#define BLINK_INTERVAL_MS 500
#define DEBOUNCE_MS       30

void app_main(void)
{
    // Configure LED output
    gpio_config_t led_config = {
        .pin_bit_mask = (1ULL << LED_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
                    gpio_config(&led_config);
    gpio_set_level(LED_GPIO, 0);

    // Configure button input with internal pull-up
    gpio_config_t button_config = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&button_config);

    int blink_enabled = 0;
    int led_state = 0;

    int last_button_read = 1;
    int stable_button_state = 1;

    TickType_t last_debounce_time = xTaskGetTickCount();
    TickType_t last_blink_time = xTaskGetTickCount();

    while (1)
    {
        TickType_t current_time = xTaskGetTickCount();

        int button_read = gpio_get_level(BUTTON_GPIO);

        // Detect button transition
        if (button_read != last_button_read)
        {
            last_debounce_time = current_time;
            last_button_read = button_read;
        }

        // Debounce confirmation
        if ((current_time - last_debounce_time) >=
            pdMS_TO_TICKS(DEBOUNCE_MS))
        {
            if (button_read != stable_button_state)
            {
                stable_button_state = button_read;

                // Button pressed = LOW
                if (stable_button_state == 0)
                {
                    blink_enabled = !blink_enabled;

                    printf("Blinking: %s\n",
                           blink_enabled ? "ON" : "OFF");

                    if (!blink_enabled)
                    {
                        led_state = 0;
                        gpio_set_level(LED_GPIO, 0);
                    }

                    last_blink_time = current_time;
                }
            }
        }

        // LED blinking control
        if (blink_enabled &&
            (current_time - last_blink_time) >=
            pdMS_TO_TICKS(BLINK_INTERVAL_MS))
        {
            led_state = !led_state;
            gpio_set_level(LED_GPIO, led_state);

            last_blink_time = current_time;
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
