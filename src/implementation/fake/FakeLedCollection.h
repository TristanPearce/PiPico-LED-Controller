#include "../../lighting/LedCollection.h"

class FakeLedCollection : LedCollection
{

public:
    void SetColour(Colour colour);
    void SetColour(Colour colour[]);
    void SetColour(uint index, Colour colour);

    uint GetNumberOfLeds();

    void SetBrightness(int8_t brightness);
    uint8_t GetBrightness();
};