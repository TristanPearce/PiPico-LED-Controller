#include "WS2812LedCollection.h"

WS2812LedCollection::WS2812LedCollection(uint64_t numberOfLeds, uint32_t gpioPin)
{
    this->m_numberOfLeds = numberOfLeds;
    this->m_gpioPin = gpioPin;

    m_pio = pio0;
    m_statemachine = 0;
    m_offset = pio_add_program(m_pio, &ws2812_program);

    ws2812_program_init(m_pio, m_statemachine, m_offset, m_gpioPin, 800000, false);
}

void WS2812LedCollection::SetColour(Colour colour)
{
    for(int i = 0; i < this->m_numberOfLeds; i++)
    {
        put_pixel((uint32_t)colour);
    }
}

u_int64_t WS2812LedCollection::GetNumberOfLeds()
{
    return 0;
}
