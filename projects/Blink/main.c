/*
 * freertos.c
 *
 * Created: 2018/4/6 6:41:22
 * Author : Pluto
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "croutine.h"

#define task1_TASK_PRIORITY					( tskIDLE_PRIORITY + 1 )

void vApplicationIdleHook( void );

void vTask1(void *pvParameters) 
{
	while (1) {
		PORTB = ~PORTB;
		vTaskDelay(1000 / portTICK_PERIOD_MS);		
	}
}

int main( void )
{
	DDRB = 0xff;
	xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL,
	task1_TASK_PRIORITY, NULL);

	vTaskStartScheduler();
	
	return 0;
}

void vApplicationIdleHook( void )
{
	vCoRoutineSchedule();
}
