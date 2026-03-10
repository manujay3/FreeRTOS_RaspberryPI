#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* Minimal FreeRTOS configuration for RP2350 */
#define configUSE_PREEMPTION                    1
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCPU_CLOCK_HZ                      150000000
#define configTICK_RATE_HZ                      1000
#define configMAX_PRIORITIES                    3
#define configMINIMAL_STACK_SIZE                128
#define configTOTAL_HEAP_SIZE                   (4 * 1024)  
#define configMAX_TASK_NAME_LEN                 10
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1

/* Memory allocation */
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configSUPPORT_STATIC_ALLOCATION         0

/* ARM Cortex-M specific */
#define configPRIO_BITS                         4
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
#define configKERNEL_INTERRUPT_PRIORITY         (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/* Hook functions - DISABLED for now */
#define configUSE_MALLOC_FAILED_HOOK            0
#define configCHECK_FOR_STACK_OVERFLOW          0

/* Include functions */
#define INCLUDE_vTaskPrioritySet                0
#define INCLUDE_uxTaskPriorityGet               0
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    0
#define INCLUDE_vTaskDelayUntil                 0
#define INCLUDE_vTaskDelay                      1

/* DISABLE configASSERT for now */
#define configASSERT(x)

#endif /* FREERTOS_CONFIG_H */
