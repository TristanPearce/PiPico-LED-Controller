#include "XmasRunnerLightingProgram.h"

#include <math.h>

XmasRunnerLightingProgram::~XmasRunnerLightingProgram()
{
}

XmasRunnerLightingProgram::XmasRunnerLightingProgram()
{
}

void XmasRunnerLightingProgram::OnEnable(LightingProgram::OnEnableArgs args)
{
}

void XmasRunnerLightingProgram::OnDisable(LightingProgram::OnDisableArgs args)
{
}

void XmasRunnerLightingProgram::OnUpdateStart(LightingProgram::OnUpdateStartArgs args)
{
    // update position
    m_position += m_velocity * args.DurationOfLastUpdateInSeconds;

    // bounce against edges
    if (m_position <= -1 / m_fadeMultiplier) 
    {
        m_velocity = abs(m_velocity);
        // change colour
        m_currentColourIndex = (m_currentColourIndex + 1) % (sizeof(m_christmasColours) / sizeof(m_christmasColours[0]));
    } 
    else if (m_position >= args.NumberOfPixels + 1 / m_fadeMultiplier)
    {
        m_velocity = -abs(m_velocity);
    }
}

void XmasRunnerLightingProgram::OnUpdateEnd(LightingProgram::OnUpdateEndArgs args)
{

}

Colour XmasRunnerLightingProgram::GetColourForPixel(uint index, LightingProgram::GetColourForPixelArgs args)
{
    float offset = abs(m_position - index);
    if(offset < 1 / m_fadeMultiplier)
        return m_christmasColours[m_currentColourIndex] * ((1 - ((offset) * m_fadeMultiplier)) * 255.0f);
    else
        return Colour::BLACK;
}