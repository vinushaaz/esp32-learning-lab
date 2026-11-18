
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"

#define LDR_ADC_CHANNEL ADC_CHANNEL_6

static const char *TAG = "LDR";

void app_main(void)
{
    adc_oneshot_unit_handle_t adc_handle;

    adc_oneshot_unit_init_cfg_t init_config = {
        .unit_id = ADC_UNIT_1,
    };

    ESP_ERROR_CHECK(
        adc_oneshot_new_unit(&init_config, &adc_handle)
    );

    adc_oneshot_chan_cfg_t channel_config = {
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_12,
    };

    ESP_ERROR_CHECK(
        adc_oneshot_config_channel(
            adc_handle,
            LDR_ADC_CHANNEL,
            &channel_config
        )
    );

    ESP_LOGI(TAG, "LDR initialized");

    while (1)
    {
        int adc_raw = 0;

        esp_err_t result = adc_oneshot_read(
            adc_handle,
            LDR_ADC_CHANNEL,
            &adc_raw
        );

        if (result == ESP_OK)
        {
            ESP_LOGI(TAG, "ADC Reading: %d", adc_raw);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
