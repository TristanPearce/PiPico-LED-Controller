#pragma once

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "../../protocols/ws2812.h"
#include "../../lighting/LedCollection.h"

#include "../../lighting/Colour.h"

class WS2812LedCollection : LedCollection 
{
public:
    WS2812LedCollection(uint64_t numberOfLeds, uint32_t gpioPin);
    void SetColour(Colour colour);
    u_int64_t GetNumberOfLeds();

private:
    uint64_t m_numberOfLeds;
    uint32_t m_gpioPin;

    PIO m_pio;
    int m_statemachine;
    uint m_offset;
};
