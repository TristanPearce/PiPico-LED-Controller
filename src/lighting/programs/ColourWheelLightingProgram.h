#include "../LightingProgram.h"

#include <math.h>

class ColourWheelLightingProgram : public LightingProgram
{

public:
    void OnCreate(LightingProgramOnCreateArgs args);
    void OnDestroy(LightingProgramOnDestroyArgs args);

    void OnRunStart(LightingProgramOnRunStartArgs args);
    void OnRunEnd(LightingProgramOnRunEndArgs args);

    Colour GetColourForLed(uint index, LightingProgramGetColourForLedRunEndArgs args);

private:
    float m_stepSize = 360.0f / 300.0f; 
    float m_velocity = 1.0f;
    float m_position = 0.0f;

    Colour angleToColor(float angle);
};