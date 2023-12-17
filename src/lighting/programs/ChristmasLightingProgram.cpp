#include "ChristmasLightingProgram.h"

void ChristmasLightingProgram::OnCreate(LightingProgramOnCreateArgs args)
{
}

void ChristmasLightingProgram::OnDestroy(LightingProgramOnDestroyArgs args)
{
}

void ChristmasLightingProgram::OnRunStart(LightingProgramOnRunStartArgs args)
{
}

void ChristmasLightingProgram::OnRunEnd(LightingProgramOnRunEndArgs args)
{
    sleep_ms(500);
}

Colour ChristmasLightingProgram::GetColourForLed(uint index, LightingProgramGetColourForLedRunEndArgs args)
{
    int isTurnedOn = rand() % 4;
    int colourIndex = rand() % (sizeof(m_christmasColours) / sizeof(m_christmasColours[0]));

    if(isTurnedOn > 2)
        return m_christmasColours[colourIndex];
    else
        return Colour::BLACK; 
}
