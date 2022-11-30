add_library(pico-Micro-ROS
    allocators.c
    microros_base.cpp
    transports/transports.cpp
    transports/stdio_transports.cpp
    transports/uart_transports.cpp
    transports/uart_dma_transports.cpp
)

target_link_directories(pico-Micro-ROS PUBLIC
    ${PROJECT_SOURCE_DIR}/libmicroros
)

target_link_libraries(pico-Micro-ROS
    pico_stdlib 
    hardware_dma
    hardware_irq
    microros
    pico-FreeRTOS
    )

target_include_directories(pico-Micro-ROS
    PUBLIC .
    PUBLIC ${PROJECT_SOURCE_DIR}/libmicroros/include
    PUBLIC ${PROJECT_SOURCE_DIR}/src/transports
    )