#include <stdio.h>
#include "string.h"
#include "esp_timer.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

esp_timer_handle_t xEsp_Timer_Handle;

void vTimerCallBack(void*args){
	static bool on;
	static uint16_t count = 0;
	on = !on;
	gpio_set_level(GPIO_NUM_4, on);
	count++;

	if(count >= 1001) {
		esp_timer_stop(xEsp_Timer_Handle);
		esp_timer_delete(xEsp_Timer_Handle);
	}
}

void app_main(void)
{
	gpio_pad_select_gpio(GPIO_NUM_4);

	gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);

	const esp_timer_create_args_t xEsp_Timer_Create_Args = {
			.callback = vTimerCallBack,
			.name = "My Timer"
	};

	//esp_timer_handle_t xEsp_Timer_Handle;

	esp_timer_create(&xEsp_Timer_Create_Args, &xEsp_Timer_Handle);

	esp_timer_start_periodic(xEsp_Timer_Handle, 1000000);

	printf("app started %lld \n", esp_timer_get_time());

	while(true){
		esp_timer_dump(stdout);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}

}
