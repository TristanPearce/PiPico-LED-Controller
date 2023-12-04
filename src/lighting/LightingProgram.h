#pragma once

class LightingProgramOnCreateArgs
{

};

class LightingProgramOnDestroyArgs
{

};

class LightingProgramOnRunStartArgs
{

};

class LightingProgramOnRunEndArgs
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