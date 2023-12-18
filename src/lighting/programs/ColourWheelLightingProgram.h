#include "../LightingProgram.h"

#include <math.h>

class ColourWheelLightingProgram : public LightingProgram
{

public:
    void OnEnable(LightingProgram::OnEnableArgs args);
    void OnDisable(LightingProgram::OnDisableArgs args);

    void OnUpdateStart(LightingProgram::OnUpdateStartArgs args);
    void OnUpdateEnd(LightingProgram::OnUpdateEndArgs args);

    Colour GetColourForPixel(uint index, LightingProgram::GetColourForPixelArgs args);

private:
    float m_stepSize = 360.0f / 300.0f; 
    float m_velocity = 1.0f;
    float m_position = 0.0f;

    Colour angleToColor(float angle);
};