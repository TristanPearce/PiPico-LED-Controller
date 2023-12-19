#pragma once

#include "../../lighting/LightingProgram.h"

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include <math.h>
#include <random>



class XmasRunnerLightingProgram : public LightingProgram {
public:

    XmasRunnerLightingProgram();
    ~XmasRunnerLightingProgram();

    void OnEnable(LightingProgram::OnEnableArgs args);
    void OnDisable(LightingProgram::OnDisableArgs args);

    void OnUpdateStart(LightingProgram::OnUpdateStartArgs args);
    void OnUpdateEnd(LightingProgram::OnUpdateEndArgs args);

    Colour GetColourForPixel(uint index, LightingProgram::GetColourForPixelArgs args);

private:
    Colour m_christmasColours[2] = {Colour::RED, Colour::GREEN};
    int m_currentColourIndex = 0;
    
    float m_velocity = 10;
    float m_position = 0;
    float m_fadeMultiplier = 0.1f;
};