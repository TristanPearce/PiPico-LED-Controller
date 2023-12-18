#include "IR.h"

IR::Keys IR::Receive(uint pin)
{
    uint32_t timings[34];  // Adjust the array size based on your needs
    captureSignal(timings, sizeof(timings) / sizeof(timings[0]), pin);

    uint midPoint = 21;

    uint code = 0;

        printf("Signal captured. Durations (us): ");
        for (size_t i = 0; i < sizeof(timings) / sizeof(timings[0]); i++) {
            printf("%u ", timings[i]);
        }
        printf("\n");

    for (size_t i = 16; i < 23; i++) {
        code <<= 1;
        if(timings[i] > midPoint)
            code |=  1;
    }

    return static_cast<IR::Keys>(code);
}

void IR::captureSignal(uint32_t *timings, size_t max_timings, uint pin)
{
    size_t count = 0;
    while (count < max_timings) {
        if (gpio_get(pin)) {
            uint32_t duration = 0;
            sleep_us(50);  // Wait for the start of the pulse

            while (gpio_get(pin)) {
                duration++;
                sleep_us(50);
            }

            timings[count++] = duration;

            // Wait for the end of the pulse
            sleep_us(50);
        }
        sleep_us(10);  // Adjust the sleep duration as needed
    }
}