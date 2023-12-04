
#pragma once
#include "../LightingProgram.h"

class FakeLightingProgram : public LightingProgram
{
public:
    void OnCreate(LightingProgramOnCreateArgs args);
    void OnDestroy(LightingProgramOnDestroyArgs args);

    void OnRunStart(LightingProgramOnRunStartArgs args);
    void OnRunEnd(LightingProgramOnRunEndArgs args);

};