#include <stdio.h>

#include <iostream>
#include <string>

#include <vector>
#include <cmath>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "protocols/ws2812.hpp"

using namespace std;

struct RGBColor {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

RGBColor HSVtoRGB(float hue, float saturation, float value) {
    int h_i = static_cast<int>(hue * 6);
    float f = hue * 6 - h_i;
    float p = value * (1 - saturation);
    float q = value * (1 - f * saturation);
    float t = value * (1 - (1 - f) * saturation);

    float r, g, b;
    switch (h_i) {
        case 0:
            r = value;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = value;
            b = p;
            break;
        case 2:
            r = p;
            g = value;
            b = t;
            break;
        case 3:
            r = p;
            g = q;
            b = value;
            break;
        case 4:
            r = t;
            g = p;
            b = value;
            break;
        default:
            r = value;
            g = p;
            b = q;
            break;
    }

    // Convert floats to RGB range (0-255)
    RGBColor rgbColor;
    rgbColor.r = static_cast<int>(r * 255);
    rgbColor.g = static_cast<int>(g * 255);
    rgbColor.b = static_cast<int>(b * 255);

    return rgbColor;
}



const int NUMBER_OF_LEDS = 300;

const int WS2812_PIN = 22;

int main() {

    stdio_init_all();
    sleep_ms(100);

    PIO pio = pio0;
    int statemachine = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, statemachine, offset, WS2812_PIN, 800000, false);

    double t = 0.0;
    double brightness = 0.1;
    RGBColor color;
    while (1) {
        double velocity = 0.001;
        for (uint i = 0; i < NUMBER_OF_LEDS; ++i) {
            color = HSVtoRGB(t, 1.0f, 0.5f);
            put_pixel(urgb_u32(color.r * brightness, color.g * brightness, color.b * brightness));
        }
        puts(to_string(t).c_str());
        sleep_ms(1);
        t += velocity;
        if (t > 1) {
            t -= 1.0;
        }
    }
}