#pragma once

#include "../LightingController.h"
#include "../LightingProgram.h"
#include "../LedCollection.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"

class SingleProgramLightingController : public LightingController {

public:
    SingleProgramLightingController(LightingProgram* program, LedCollection* leds, bool shouldControllerDeleteProgram);
    ~SingleProgramLightingController();

    void Enable();
    void Disable();

private:
    LightingProgram* m_program;
    LedCollection* m_leds;
    bool m_shouldControllerDeleteProgram;
    bool m_active;
};