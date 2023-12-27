#pragma once

#include "../LightingController.h"
#include "../LightingProgram.h"
#include "../LedCollection.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include <vector>

class ButtonDrivenLightingController : public LightingController {

public:
    ButtonDrivenLightingController(std::vector<LightingProgram*> programs, LedCollection* leds);
    ~ButtonDrivenLightingController();

    void Enable();
    void Disable();

private:
    std::vector<LightingProgram*> m_programs;
    int m_currentProgramIndex = 0;
    
    LedCollection* m_leds;
    bool m_active;

    bool isButtonPressed();
    bool m_isButtonPressed = false;
};