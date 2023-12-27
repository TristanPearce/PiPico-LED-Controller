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

const int NUMBER_OF_LEDS = 300;

const int WS2812_PIN = 16;

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