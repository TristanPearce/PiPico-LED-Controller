/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#pragma once


#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/dma.h"
#include "ws2812.pio.h"

enum WS2812BFrequency 
{
    KHZ_800 = 800000,
    KHZ_400 = 400000
};

enum WS2812BColourFormat 
{
    RGB_888 = 24, // 24 bits
    RGBW_8888 = 32 // 32 bits
};

void ws2812_program_init(PIO pio, uint state_machine, uint offset, uint pin, WS2812BFrequency freq, WS2812BColourFormat colourFormat);

int ws2812_transfer(PIO pio, uint state_machine, void* sourceAddress, size_t nofBytes);