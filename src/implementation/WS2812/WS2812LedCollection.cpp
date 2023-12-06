#include "WS2812LedCollection.h"

WS2812LedCollection::WS2812LedCollection(uint numberOfLeds, uint gpioPin)
{
    m_numberOfLeds = numberOfLeds;
    m_gpioPin = gpioPin;

    m_pio = pio0;
    m_statemachine = 0;
    m_offset = pio_add_program(m_pio, &ws2812_program);

    m_colours = new Colour[m_numberOfLeds];

    ws2812_program_init(m_pio, m_statemachine, m_offset, m_gpioPin, 800000, false);
}

WS2812LedCollection::~WS2812LedCollection()
{
    delete m_colours;
    m_colours = NULL;
}

void WS2812LedCollection::SetColour(Colour colour)
{
    for(int i = 0; i < this->m_numberOfLeds; i++)
    {
         m_colours[i] = colour;
    }
    PushToHardware();
}

void WS2812LedCollection::SetColour(Colour colours[])
{
    for(int i = 0; i < this->m_numberOfLeds; i++)
    {
        m_colours[i] = colours[i];
    }
    PushToHardware();
}

void WS2812LedCollection::SetColour(uint index, Colour colour)
{

}

uint WS2812LedCollection::GetNumberOfLeds()
{
    return m_numberOfLeds;
}

uint8_t WS2812LedCollection::GetBrightness()
{
    return m_brightness;
}

void WS2812LedCollection::SetBrightness(int8_t brightness)
{
    m_brightness = brightness;
}

// PRIVATE //

void WS2812LedCollection::PushToHardware()
{
    for(int i = 0; i < this->m_numberOfLeds; i++)
    {
        put_pixel((uint32_t)(m_colours[i]));
    }
}
