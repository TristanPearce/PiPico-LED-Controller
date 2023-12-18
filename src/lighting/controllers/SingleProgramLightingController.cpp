#include "SingleProgramLightingController.h"

SingleProgramLightingController::SingleProgramLightingController(LightingProgram * program, LedCollection * leds, bool shouldControllerDeleteProgram)
{
    m_program = program;
    m_leds = leds;
    m_shouldControllerDeleteProgram = shouldControllerDeleteProgram;
}

SingleProgramLightingController::~SingleProgramLightingController()
{
    if(m_shouldControllerDeleteProgram)
        delete m_program;
}

void SingleProgramLightingController::Enable()
{
    m_active = true;

    Colour cached_colour;

    m_program->OnEnable(LightingProgram::OnEnableArgs());

    while(m_active)
    {
        uint64_t start_time = time_us_64();

        m_program->OnUpdateStart(LightingProgram::OnUpdateStartArgs());

        for (uint i = 0; i < m_leds->GetNumberOfLeds(); ++i) {
            cached_colour = m_program->GetColourForPixel(i, LightingProgram::GetColourForPixelArgs());
            m_leds->SetColour(i, cached_colour);
        }
        m_leds->Show();

        m_program->OnUpdateEnd(LightingProgram::OnUpdateEndArgs());

        uint64_t end_time = time_us_64();
        uint64_t elapsed_time_us = (end_time - start_time);

        sleep_us(1000);

        std::cout << "Loop duration: " << elapsed_time_us << " us." << std::endl;
    }

    m_program->OnDisable(LightingProgram::OnDisableArgs());
}

void SingleProgramLightingController::Disable()
{
    m_active = false;
}
