# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "$ENV{PICO_SDK_PATH}")

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(couch_leds C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(couch_leds src/main.cpp )

pico_set_program_name(couch_leds "couch_leds")
pico_set_program_version(couch_leds "0.1")

pico_enable_stdio_uart(couch_leds 1)
pico_enable_stdio_usb(couch_leds 1)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(couch_leds ${CMAKE_CURRENT_LIST_DIR}/src/protocols/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/protocols/generated)

# Add the standard library to the build
target_link_libraries(couch_leds
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(couch_leds PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/src
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(couch_leds
        hardware_spi
        hardware_i2c
        hardware_dma
        hardware_pio
        hardware_interp
        hardware_timer
        hardware_clocks
        pico_cyw43_arch_none
        )

pico_add_extra_outputs(couch_leds)