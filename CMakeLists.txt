cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(hello_freertos)
pico_sdk_init()

add_executable(hello_freertos
    main.c
    FreeRTOS-Kernel/tasks.c
    FreeRTOS-Kernel/queue.c
    FreeRTOS-Kernel/list.c
    FreeRTOS-Kernel/timers.c
    FreeRTOS-Kernel/event_groups.c
    FreeRTOS-Kernel/stream_buffer.c
    FreeRTOS-Kernel/portable/MemMang/heap_4.c      # ← Make sure this is here
    FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c
)

target_include_directories(hello_freertos PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    FreeRTOS-Kernel/include
    FreeRTOS-Kernel/portable/GCC/ARM_CM4F
)

target_link_libraries(hello_freertos
    pico_stdlib
    hardware_structs    # For scb_hw access
)

pico_enable_stdio_usb(hello_freertos 1)
pico_enable_stdio_uart(hello_freertos 0)
pico_add_extra_outputs(hello_freertos)
