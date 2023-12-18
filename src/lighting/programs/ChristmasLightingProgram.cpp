#include "ChristmasLightingProgram.h"

ChristmasLightingProgram::~ChristmasLightingProgram()
{
}

ChristmasLightingProgram::ChristmasLightingProgram()
{
}

void ChristmasLightingProgram::OnEnable(LightingProgram::OnEnableArgs args)
{
}

void ChristmasLightingProgram::OnDisable(LightingProgram::OnDisableArgs args)
{
}

void ChristmasLightingProgram::OnUpdateStart(LightingProgram::OnUpdateStartArgs args)
{
}

void ChristmasLightingProgram::OnUpdateEnd(LightingProgram::OnUpdateEndArgs args)
{
    sleep_ms(500);
}

Colour ChristmasLightingProgram::GetColourForPixel(uint index, LightingProgram::GetColourForPixelArgs args)
{
    int isTurnedOn = rand() % 4;
    int colourIndex = rand() % (sizeof(m_christmasColours) / sizeof(m_christmasColours[0]));

    if(isTurnedOn > 2)
        return m_christmasColours[colourIndex];
    else
        return Colour::BLACK;
}
