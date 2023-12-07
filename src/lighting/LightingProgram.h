#pragma once

#include "Colour.h"

struct LightingProgramOnCreateArgs
{

};

struct LightingProgramOnDestroyArgs
{

};

struct LightingProgramOnRunStartArgs
{

};

struct LightingProgramOnRunEndArgs
{

};

struct LightingProgramGetColourForLedRunEndArgs
{

};

class LightingProgram 
{

public:
    virtual void OnCreate(LightingProgramOnCreateArgs args) = 0;
    virtual void OnDestroy(LightingProgramOnDestroyArgs args) = 0;

    virtual void OnRunStart(LightingProgramOnRunStartArgs args) = 0;
    virtual void OnRunEnd(LightingProgramOnRunEndArgs args) = 0;

    virtual Colour GetColourForLed(uint index, LightingProgramGetColourForLedRunEndArgs args) = 0;
};