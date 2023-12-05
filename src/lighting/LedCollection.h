#pragma once
#include "Colour.h"

class LedCollection
{

public:
    virtual void SetColour(Colour colour) = 0;

    virtual u_int64_t GetNumberOfLeds() = 0;
};