add_library(pico-microros-uart pico_uart_transport.c)

target_link_libraries(pico-microros-uart pico_stdlib microros)

target_include_directories(pico-microros-uart
    PUBLIC ${PROJECT_SOURCE_DIR}/include/
    PUBLIC ${PROJECT_SOURCE_DIR}/libmicroros/include
    )