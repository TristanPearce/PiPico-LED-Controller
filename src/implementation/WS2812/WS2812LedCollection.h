#pragma once

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include "../../protocols/ws2812.h"
#include "../../lighting/LedCollection.h"

#include "../../lighting/Colour.h"

class WS2812LedCollection : public LedCollection 
{
public:
    WS2812LedCollection(uint numberOfLeds, uint gpioPin);
    ~WS2812LedCollection();

    void SetColour(Colour colour);
    void SetColour(Colour colour[]);
    void SetColour(uint index, Colour colour);
    
    uint GetNumberOfLeds();

    void SetBrightness(int8_t brightness);
    uint8_t GetBrightness();

    void Show();

private:
    uint m_numberOfLeds;
    uint m_gpioPin;

    PIO m_pio;
    int m_statemachine;
    uint m_offset;

    int8_t m_brightness;

    Colour* m_colours;
};
