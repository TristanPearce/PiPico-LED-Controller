#include "FakeLedCollection.h"

#include <iostream>

void FakeLedCollection::SetColour(Colour colour)
{
    std::cout << "Fake Led Collection set single colour." << std::endl;
}

void FakeLedCollection::SetColour(Colour colour[])
{
    std::cout << "Fake Led Collection set array of colours." << std::endl;
}

void FakeLedCollection::SetColour(uint index, Colour colour)
{
    std::cout << "Fake Led Collection set single index to colour." << std::endl;
}

uint FakeLedCollection::GetNumberOfLeds()
{
    std::cout << "Fake Led Collection returned number of Leds." << std::endl;
    return 0;
}

uint8_t FakeLedCollection::GetBrightness()
{
    std::cout << "Fake Led Collection returned current brightness." << std::endl;
    return 0;
}

void FakeLedCollection::Show()
{
    std::cout << "Fake Led Collection showed." << std::endl;
}

void FakeLedCollection::SetBrightness(int8_t brightness)
{
    std::cout << "Fake Led Collection set brightness." << std::endl;
}
