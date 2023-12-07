#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "protocols/ws2812.h"

#include "lighting/LightingProgram.h"
#include "lighting/programs/FakeLightingProgram.h"

#include "lighting/Colour.h"

#include "implementation/WS2812/WS2812LedCollection.h"


void angleToColor(float angle, uint* out_r, uint* out_g, uint* out_b,float brightness = 0.2f) {
    // Normalize angle to be within [0, 360)
    angle = fmod(angle, 360.0);
    if (angle < 0) {
        angle += 360.0;
    }

    // Convert HSL to RGB
    float c = 1.0;
    float x = c * (1.0 - std::abs(fmod(angle / 60.0, 2.0) - 1.0));
    float m = 0.0;
    
    float r, g, b;
    if (angle < 60.0) {
        r = c;
        g = x;
        b = 0.0;
    } else if (angle < 120.0) {
        r = x;
        g = c;
        b = 0.0;
    } else if (angle < 180.0) {
        r = 0.0;
        g = c;
        b = x;
    } else if (angle < 240.0) {
        r = 0.0;
        g = x;
        b = c;
    } else if (angle < 300.0) {
        r = x;
        g = 0.0;
        b = c;
    } else {
        r = c;
        g = 0.0;
        b = x;
    }

    // Convert floats to RGB range (0-255)
    *out_r = (uint)((r * brightness) * 255.0f);
    *out_g = (uint)((g * brightness) * 255.0f);
    *out_b = (uint)((b * brightness) * 255.0f);
}



const int NUMBER_OF_LEDS = 300;

const int WS2812_PIN = 22;

int main() {

    stdio_init_all();
    sleep_ms(100);

    WS2812LedCollection leds(NUMBER_OF_LEDS, WS2812_PIN);


    // Define the color and velocity variables
    uint r = 0;
    uint g = 0;
    uint b = 0;
    double brightness = 0.4f;

    float angle = 0.0f;
    float velocity = 30.0f;
    float stepSize = 360.0f / 300.0f; 

    Colour color(20, 10, 0);

    r = 50;
    g = 50;
    b = 50;

    while (true) {
        uint64_t start_time = time_us_64();

        for (uint i = 0; i < NUMBER_OF_LEDS; ++i) {
            angleToColor(angle + ((float)i * stepSize), &r, &g, &b, brightness);
            color.setR(r);
            color.setG(g);
            color.setB(b);
            leds.SetColour(i, color);
        }

        leds.Show();

        uint64_t end_time = time_us_64();
        uint64_t elapsed_time_us = (end_time - start_time);

        angle += velocity * (1.0f / elapsed_time_us * 100);

        if(angle > 360)
            angle -= 360;

        sleep_us(1000);

        std::cout << "Loop duration: " << elapsed_time_us << " us." << std::endl;
    }

    return 0;
}