#pragma once

#include "Colour.h"

class LightingProgram 
{

public:

    struct OnEnableArgs {};
    virtual void OnEnable(LightingProgram::OnEnableArgs args) = 0;

    struct OnDisableArgs {};
    virtual void OnDisable(LightingProgram::OnDisableArgs args) = 0;

    struct OnUpdateStartArgs {};
    virtual void OnUpdateStart(LightingProgram::OnUpdateStartArgs args) = 0;

    struct OnUpdateEndArgs {};
    virtual void OnUpdateEnd(LightingProgram::OnUpdateEndArgs args) = 0;

    struct GetColourForPixelArgs {};
    virtual Colour GetColourForPixel(uint pixel_index, LightingProgram::GetColourForPixelArgs args) = 0;
};