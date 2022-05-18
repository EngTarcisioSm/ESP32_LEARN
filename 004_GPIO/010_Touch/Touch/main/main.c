#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/touch_pad.h"

void app_main(void)
{
	uint16_t u16Val1;
	uint16_t u16Val2;
	uint16_t u16Val3;

	touch_pad_init();

	touch_pad_set_voltage(TOUCH_HVOLT_2V7, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_0V5);

	touch_pad_config(TOUCH_PAD_NUM9, -1);

//	while(true) {
//		touch_pad_read(TOUCH_PAD_NUM9, &u16Val);
//
//		printf("val = %d\n", u16Val);
//
//		vTaskDelay( 1000 / portTICK_PERIOD_MS );
//	}

	touch_pad_filter_start(10);


	while(true) {
		touch_pad_read_filtered( TOUCH_PAD_NUM9, &u16Val1 );
		touch_pad_read_raw_data( TOUCH_PAD_NUM9, &u16Val2 );
		touch_pad_read( TOUCH_PAD_NUM9, &u16Val3 );

		printf("val filtered = %d\n", u16Val1 );
		printf("val raw = %d\n", u16Val2 );
		printf("val = %d\n", u16Val3 );
		printf("\n");

		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}
}
