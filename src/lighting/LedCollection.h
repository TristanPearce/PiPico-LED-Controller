#pragma once
#include "Colour.h"

class LedCollection
{

public:
    virtual void SetColour(Colour colour) = 0;
    virtual void SetColour(Colour colour[]) = 0;
    virtual void SetColour(uint index, Colour colour) = 0;

    virtual void SetBrightness(int8_t brightness) = 0;
    virtual uint8_t GetBrightness() = 0;

    virtual uint GetNumberOfLeds() = 0;
};