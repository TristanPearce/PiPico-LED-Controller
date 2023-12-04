#pragma once

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

class LightingProgram 
{

public:
    virtual void OnCreate(LightingProgramOnCreateArgs args) = 0;
    virtual void OnDestroy(LightingProgramOnDestroyArgs args) = 0;

    virtual void OnRunStart(LightingProgramOnRunStartArgs args) = 0;
    virtual void OnRunEnd(LightingProgramOnRunEndArgs args) = 0;
};