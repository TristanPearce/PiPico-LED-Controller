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

#include "lighting/LightingProgram.h"
#include "lighting/programs/ColourWheelLightingProgram.h"
#include "lighting/programs/ChristmasLightingProgram.h"

#include "lighting/Colour.h"

#include "implementation/WS2812/WS2812LedCollection.h"

const int NUMBER_OF_LEDS = 300;

const int WS2812_PIN = 22;

// int main() {

//     stdio_init_all();
//     sleep_ms(100);

//     LedCollection* leds_ptr;
//     leds_ptr = new WS2812LedCollection(NUMBER_OF_LEDS, WS2812_PIN);

//     LightingProgram* program_ptr;
//     program_ptr = new ChristmasLightingProgram();

//     LightingController* controller_ptr;
//     controller_ptr = new SingleProgramLightingController(program_ptr, leds_ptr, false);

//     //controller_ptr->Enable();
    


//     delete controller_ptr;
//     delete program_ptr;
//     delete leds_ptr;

//     return 0;
// }

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#include "ir_remote/IR.h"

const uint IR_PIN = 16;

int main() {
    stdio_init_all();

    gpio_init(IR_PIN);
    gpio_set_dir(IR_PIN, GPIO_IN);

    while (1) {
        IR ir = IR();

        IR::Keys code = ir.Receive(IR_PIN);

        switch (code)
        {
        case IR::Keys::Power :
            printf("Power");
            break;
        case IR::Keys::Zero :
            printf("0");
            break;
        case IR::Keys::One:
            printf("1");
            break;

        default:
            break;
        }


        sleep_ms(500);  // Adjust the sleep duration as needed
    }

    return 0;
}
