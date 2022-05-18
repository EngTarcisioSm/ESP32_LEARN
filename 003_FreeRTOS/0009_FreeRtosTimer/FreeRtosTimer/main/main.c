#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "esp_system.h"

void vOn_Timer(TimerHandle_t xTimer) {
	printf( "timer hit %lld \n", esp_timer_get_time()/1000 );
}


void app_main(void)
{
	printf("app started %lld \n", esp_timer_get_time()/1000 );

	TimerHandle_t xTimer = xTimerCreate(
			"my timer",
			pdMS_TO_TICKS(3000),
			true,
			NULL,
			vOn_Timer);

	xTimerStart(xTimer, 0);
}
