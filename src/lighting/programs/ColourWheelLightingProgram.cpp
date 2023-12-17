#include "ColourWheelLightingProgram.h"

void ColourWheelLightingProgram::OnCreate(LightingProgramOnCreateArgs args)
{

}

void ColourWheelLightingProgram::OnDestroy(LightingProgramOnDestroyArgs args)
{

}

void ColourWheelLightingProgram::OnRunStart(LightingProgramOnRunStartArgs args)
{

}

void ColourWheelLightingProgram::OnRunEnd(LightingProgramOnRunEndArgs args)
{
    m_position += m_velocity;
}

Colour ColourWheelLightingProgram::GetColourForLed(uint index, LightingProgramGetColourForLedRunEndArgs args)
{
    return this->angleToColor(index + ((float)index * m_stepSize) + m_position);
}

Colour ColourWheelLightingProgram::angleToColor(float angle)
{
    // Normalize angle to be within [0, 360)
    angle = fmod(angle, 360.0);
    if (angle < 0) {
        angle += 360.0;
    }

    // Convert HSL to RGB
    float c = 1.0;
    float x = c * (1.0 - std::abs(fmod(angle / 60.0, 2.0) - 1.0));
    float m = 0.0;
    
    float r, g, b;
    if (angle < 60.0) {
        r = c;
        g = x;
        b = 0.0;
    } else if (angle < 120.0) {
        r = x;
        g = c;
        b = 0.0;
    } else if (angle < 180.0) {
        r = 0.0;
        g = c;
        b = x;
    } else if (angle < 240.0) {
        r = 0.0;
        g = x;
        b = c;
    } else if (angle < 300.0) {
        r = x;
        g = 0.0;
        b = c;
    } else {
        r = c;
        g = 0.0;
        b = x;
    }

    // Convert floats to RGB range (0-255)
    return Colour((uint)(r * 255.0f), (uint)(g * 255.0f), (uint)(b  * 255.0f));
}
