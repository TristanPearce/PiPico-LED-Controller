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

    uint64_t start_time, end_time;
    double previous_run_time_in_seconds;

    while(m_active)
    {
        uint64_t start_time = time_us_64();

        LightingProgram::OnUpdateStartArgs onStartArgs = LightingProgram::OnUpdateStartArgs();
        onStartArgs.DurationOfLastUpdateInSeconds = previous_run_time_in_seconds;
        onStartArgs.NumberOfPixels = m_leds->GetNumberOfLeds();
        m_program->OnUpdateStart(onStartArgs);

        for (uint i = 0; i < m_leds->GetNumberOfLeds(); ++i) {
            cached_colour = m_program->GetColourForPixel(i, LightingProgram::GetColourForPixelArgs());
            m_leds->SetColour(i, cached_colour);
        }
        m_leds->Show();

        m_program->OnUpdateEnd(LightingProgram::OnUpdateEndArgs());

        end_time = time_us_64();
        previous_run_time_in_seconds = (double)(end_time - start_time) / 1000000; 

        sleep_us(1000);
    }

    m_program->OnDisable(LightingProgram::OnDisableArgs());
}

void SingleProgramLightingController::Disable()
{
    m_active = false;
}
