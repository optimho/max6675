# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/michael/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(max6675 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(max6675 max6675_example.c)
#add_executable(max6675 max6675.c )

pico_set_program_name(max6675 "max6675")
pico_set_program_version(max6675 "0.1")

pico_enable_stdio_uart(max6675 1)
pico_enable_stdio_usb(max6675 0)

# Add the standard library to the build
target_link_libraries(max6675 pico_stdlib)

# Add any user requested libraries
target_link_libraries(max6675
        pico_stdlib
        hardware_spi
        )

pico_add_extra_outputs(max6675)

