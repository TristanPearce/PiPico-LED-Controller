#include "FakeLightingProgram.h"

#include <iostream>

void FakeLightingProgram::OnCreate(LightingProgramOnCreateArgs args)
{
    std::cout << "Colour Wheel - On Create" << std::endl;
}

void FakeLightingProgram::OnDestroy(LightingProgramOnDestroyArgs args)
{
    std::cout << "Colour Wheel - On Destroy" << std::endl;
}

void FakeLightingProgram::OnRunStart(LightingProgramOnRunStartArgs args)
{
    std::cout << "Colour Wheel - On Run Start" << std::endl;
}

void FakeLightingProgram::OnRunEnd(LightingProgramOnRunEndArgs args)
{
    std::cout << "Colour Wheel - On Run End" << std::endl;
};