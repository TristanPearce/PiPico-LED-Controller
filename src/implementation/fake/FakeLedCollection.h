#include "../../lighting/LedCollection.h"

class FakeLedCollection : LedCollection
{

public:
    void SetColour(Colour colour);
    u_int64_t GetNumberOfLeds();

};