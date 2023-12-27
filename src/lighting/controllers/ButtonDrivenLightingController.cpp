#include "ButtonDrivenLightingController.h"

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_PIN 11

ButtonDrivenLightingController::ButtonDrivenLightingController(std::vector<LightingProgram*> programs, LedCollection *leds)
{
    m_programs = programs;
    m_leds = leds;

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
}

ButtonDrivenLightingController::~ButtonDrivenLightingController()
{
}

void ButtonDrivenLightingController::Enable()
{
    m_active = true;

    Colour cached_colour;

    m_programs[m_currentProgramIndex]->OnEnable(LightingProgram::OnEnableArgs());

    uint64_t start_time, end_time;
    double previous_run_time_in_seconds;

    while(m_active)
    {
        uint64_t start_time = time_us_64();

        LightingProgram::OnUpdateStartArgs onStartArgs = LightingProgram::OnUpdateStartArgs();
        onStartArgs.DurationOfLastUpdateInSeconds = previous_run_time_in_seconds;
        onStartArgs.NumberOfPixels = m_leds->GetNumberOfLeds();
        m_programs[m_currentProgramIndex]->OnUpdateStart(onStartArgs);

        for (uint i = 0; i < m_leds->GetNumberOfLeds(); ++i) {
            cached_colour = m_programs[m_currentProgramIndex]->GetColourForPixel(i, LightingProgram::GetColourForPixelArgs());
            m_leds->SetColour(i, cached_colour);
        }
        m_leds->Show();

        m_programs[m_currentProgramIndex]->OnUpdateEnd(LightingProgram::OnUpdateEndArgs());

        end_time = time_us_64();
        previous_run_time_in_seconds = (double)(end_time - start_time) / 1000000; 

        sleep_us(1000);

        if(isButtonPressed() && !m_isButtonPressed)
        {
            m_isButtonPressed = true;
            m_currentProgramIndex = (m_currentProgramIndex + 1) % m_programs.size();
            printf("Button has been pressed. Index is: %i.", m_currentProgramIndex);
        }
        else if (!isButtonPressed() && m_isButtonPressed)
        {
            m_isButtonPressed = false;
        }
    }

    m_programs[m_currentProgramIndex]->OnDisable(LightingProgram::OnDisableArgs());
}

void ButtonDrivenLightingController::Disable()
{
    m_active = false;
}

bool ButtonDrivenLightingController::isButtonPressed()
{
    return gpio_get(BUTTON_PIN);
}
