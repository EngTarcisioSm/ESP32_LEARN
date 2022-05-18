#include <stdio.h>
#include "esp_log.h"

void app_main(void)
{
	esp_log_level_set("LOG", ESP_LOG_WARN);
	ESP_LOGE("LOG", "Isso � um erro!");
	ESP_LOGW("LOG", "Isso � um aviso!");
	ESP_LOGI("LOG", "Isso � uma informa��o!");
	ESP_LOGD("LOG", "Isso � uma mensagem de Debug!");
	ESP_LOGV("LOG", "Isso � um verbose");
}


