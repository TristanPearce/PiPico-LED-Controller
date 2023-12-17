#pragma once

#include "../LightingProgram.h"

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include <math.h>
#include <random>



class ChristmasLightingProgram {
public:
    void OnCreate(LightingProgramOnCreateArgs args);
    void OnDestroy(LightingProgramOnDestroyArgs args);

    void OnRunStart(LightingProgramOnRunStartArgs args);
    void OnRunEnd(LightingProgramOnRunEndArgs args);

    Colour GetColourForLed(uint index, LightingProgramGetColourForLedRunEndArgs args);

private:
    Colour m_christmasColours[2] = {Colour::RED, Colour::GREEN};
};