add_executable(example main.cpp microros_task.cpp posix.c)

target_link_libraries(example pico-microros-uart freertos pico_stdlib )

pico_enable_stdio_usb(example 1)
pico_enable_stdio_uart(example 0)
add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)

pico_add_extra_outputs(example)