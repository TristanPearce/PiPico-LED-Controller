#pragma once

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#include <stdio.h>

class IR {

public:

    enum Keys {
        Power = 116,
        Menu = 124,
        Test = 100,
        Back = 120,
        Plus = 96,
        Minus = 115,
        Rewind = 124,
        FastForward = 114,
        Play = 117,
        Zero = 109,
        One = 102,
        Two = 99,
        Three = 111,
        Four = 98,
        Five = 103,
        Six = 107,
        Seven = 104,
        Eight = 105,
        Nine = 106,
        Clear = 118
    };

    IR::Keys Receive(uint pin);

private:
    void captureSignal(uint32_t* timings, size_t max_timings, uint pin);
};