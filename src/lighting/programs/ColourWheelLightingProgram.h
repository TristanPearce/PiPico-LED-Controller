#include "../LightingProgram.h"

class ColourWheelLightingProgram : LightingProgram
{

public:
    void OnCreate(LightingProgramOnCreateArgs args);
    void OnDestroy(LightingProgramOnDestroyArgs args);

    void OnRunStart(LightingProgramOnRunStartArgs args);
    void OnRunEnd(LightingProgramOnRunEndArgs args);

    Colour GetColourForLed(uint index, LightingProgramGetColourForLedRunEndArgs args);
};