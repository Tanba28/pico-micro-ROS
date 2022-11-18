add_library(pico-microros-uart
    transports.cpp
    allocators.c
    microros_base.cpp
)

target_link_libraries(pico-microros-uart pico_stdlib microros freertos)

target_include_directories(pico-microros-uart
    PUBLIC ${PROJECT_SOURCE_DIR}/libmicroros/include
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )