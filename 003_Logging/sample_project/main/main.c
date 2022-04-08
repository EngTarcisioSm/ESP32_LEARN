#include <stdio.h>
#include "esp_log.h"

void app_main(void)
{
	esp_log_level_set("LOG", ESP_LOG_WARN);
	ESP_LOGE("LOG", "Isso é um erro!");
	ESP_LOGW("LOG", "Isso é um aviso!");
	ESP_LOGI("LOG", "Isso é uma informação!");
	ESP_LOGD("LOG", "Isso é uma mensagem de Debug!");
	ESP_LOGV("LOG", "Isso é um verbose");
}


