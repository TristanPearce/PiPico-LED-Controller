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

#include "lighting/LightingController.h"
#include "lighting/controllers/SingleProgramLightingController.h"
#include "lighting/controllers/ButtonDrivenLightingController.h"

#include "lighting/LightingProgram.h"
#include "lighting/programs/ColourWheelLightingProgram.h"
#include "lighting/programs/ChristmasLightingProgram.h"

#include "programs/xmas/XmasRunnerLightingProgram.h"

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

    LedCollection* leds_ptr;
    leds_ptr = new WS2812LedCollection(NUMBER_OF_LEDS, WS2812_PIN);

    LightingProgram* christmasLightingProgram;
    christmasLightingProgram = new ChristmasLightingProgram();

    LightingProgram* xmasRunnerProgram;
    xmasRunnerProgram = new XmasRunnerLightingProgram();

    LightingProgram* colourWheelLightingProgram;
    colourWheelLightingProgram = new ColourWheelLightingProgram();

    std::vector<LightingProgram*> programs = std::vector<LightingProgram*>();
    programs.push_back(christmasLightingProgram);
    programs.push_back(xmasRunnerProgram);
    programs.push_back(colourWheelLightingProgram);

    LightingController* controller_ptr;
    controller_ptr = new ButtonDrivenLightingController(programs, leds_ptr);

    controller_ptr->Enable();
    
    delete controller_ptr;

    delete christmasLightingProgram;
    delete xmasRunnerProgram;
    delete colourWheelLightingProgram;

    delete leds_ptr;

    return 0;
}