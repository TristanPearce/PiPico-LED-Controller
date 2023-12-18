#pragma once

#include "../LightingProgram.h"

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include <math.h>
#include <random>



class ChristmasLightingProgram : public LightingProgram {
public:

    ChristmasLightingProgram();
    ~ChristmasLightingProgram();

    void OnEnable(LightingProgram::OnEnableArgs args);
    void OnDisable(LightingProgram::OnDisableArgs args);

    void OnUpdateStart(LightingProgram::OnUpdateStartArgs args);
    void OnUpdateEnd(LightingProgram::OnUpdateEndArgs args);

    Colour GetColourForPixel(uint index, LightingProgram::GetColourForPixelArgs args);

private:
    Colour m_christmasColours[2] = {Colour::RED, Colour::GREEN};
};