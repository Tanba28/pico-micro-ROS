add_library(pico-microros-uart
    allocators.c
    microros_base.cpp
    transports/transports.cpp
    transports/stdio_transports.cpp
    transports/uart_transports.cpp
    transports/uart_dma_transports.cpp
)

target_link_directories(pico-microros-uart PUBLIC
    ${PROJECT_SOURCE_DIR}/libmicroros
)

target_link_libraries(pico-microros-uart 
    pico_stdlib 
    hardware_dma
    hardware_irq
    microros
    freertos
    )

target_include_directories(pico-microros-uart
    PUBLIC .
    PUBLIC ${PROJECT_SOURCE_DIR}/libmicroros/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/transports
    )