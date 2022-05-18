#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/dac.h"


void app_main(void)
{
	dac_output_enable(DAC_CHANNEL_2);
	dac_output_voltage(DAC_CHANNEL_2, 1);

}
