#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

void hello_task(void *pvParameters) {
    printf("Hello, FreeRTOS World!\n");
    printf("Task: %s\n", pcTaskGetName(NULL));
    printf("Free heap: %d bytes\n", xPortGetFreeHeapSize());
    vTaskDelete(NULL);
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    xTaskCreate(hello_task, "HelloTask", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    return -1;
}

extern void vPortSVCHandler(void);
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);

void isr_svcall(void)  { vPortSVCHandler(); }
void isr_pendsv(void)  { xPortPendSVHandler(); }
void isr_systick(void) { xPortSysTickHandler(); }
