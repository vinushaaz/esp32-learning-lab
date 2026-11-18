
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_err.h"
#include "driver/ledc.h"

#define SERVO_GPIO          18

#define SERVO_FREQUENCY     50
#define SERVO_RESOLUTION    LEDC_TIMER_14_BIT

#define SERVO_MIN_PULSE_US  1000
#define SERVO_MAX_PULSE_US  2000

#define PWM_PERIOD_US       20000
#define PWM_MAX_DUTY        16384

static const char *TAG = "SERVO";

/* Convert an angle into a PWM duty value */
static uint32_t servo_angle_to_duty(int angle)
{
    if (angle < 0) {
        angle = 0;
    }

    if (angle > 180) {
        angle = 180;
    }

    uint32_t pulse_width_us =
        SERVO_MIN_PULSE_US +
        ((SERVO_MAX_PULSE_US - SERVO_MIN_PULSE_US) * angle) / 180;

    uint32_t duty =
        (pulse_width_us * PWM_MAX_DUTY) / PWM_PERIOD_US;

    return duty;
}

/* Move the servo to the requested angle */
static void servo_set_angle(int angle)
{
    uint32_t duty = servo_angle_to_duty(angle);

    ESP_ERROR_CHECK(
        ledc_set_duty(
            LEDC_LOW_SPEED_MODE,
            LEDC_CHANNEL_0,
            duty
        )
    );

    ESP_ERROR_CHECK(
        ledc_update_duty(
            LEDC_LOW_SPEED_MODE,
            LEDC_CHANNEL_0
        )
    );

    ESP_LOGI(TAG, "Servo angle: %d degrees | Duty: %lu",
             angle, (unsigned long)duty);
}

void app_main(void)
{
    ESP_LOGI(TAG, "Starting ESP32 Servo Motor Project");

    /* STEP 1: Configure PWM timer */
    ledc_timer_config_t timer_config = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = SERVO_RESOLUTION,
        .freq_hz = SERVO_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK
    };

    ESP_ERROR_CHECK(ledc_timer_config(&timer_config));

    /* STEP 2: Configure PWM output channel */
    ledc_channel_config_t channel_config = {
        .gpio_num = SERVO_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0
    };

    ESP_ERROR_CHECK(ledc_channel_config(&channel_config));

    ESP_LOGI(TAG, "PWM configured successfully");

    /* STEP 3: Move servo repeatedly */
    while (1)
    {
        servo_set_angle(0);
        vTaskDelay(pdMS_TO_TICKS(1000));

        servo_set_angle(90);
        vTaskDelay(pdMS_TO_TICKS(1000));

        servo_set_angle(180);
        vTaskDelay(pdMS_TO_TICKS(1000));

        servo_set_angle(90);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
