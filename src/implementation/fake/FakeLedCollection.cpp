#include "FakeLedCollection.h"

#include <iostream>

void FakeLedCollection::SetColour(Colour colour)
{
    std::cout << "Fake Led Collection set to: " << std::endl;
}

u_int64_t FakeLedCollection::GetNumberOfLeds()
{
    return 0;
}
