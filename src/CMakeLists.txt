cmake_minimum_required(VERSION 3.13)

add_subdirectory(module)

include_directories(${PROJECT_SOURCE_DIR}/inc/module)

link_directories(${PROJECT_SOURCE_DIR}/src/module)


add_executable(${CMAKE_PROJECT_NAME}
    main.c
    )

target_link_libraries(${CMAKE_PROJECT_NAME} module pico_stdlib)

pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 0)

pico_add_extra_outputs(${CMAKE_PROJECT_NAME})

