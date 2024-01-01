#include "ws2812.h"

void ws2812_program_init(PIO pio, uint state_machine, uint offset, uint pin, WS2812BFrequency freq, WS2812BColourFormat colourFormat)
{
    pio_gpio_init(pio, pin); /* initialize pin for usage with the PIO */
    pio_sm_set_consecutive_pindirs(pio, state_machine, pin, 1, true); /* set pin direction. 1: number of pins. true: as output pin */
    pio_sm_config c = ws2812_program_get_default_config(offset); /* get default configuration */
    sm_config_set_sideset_pins(&c, pin); /* use pin as side set */
    sm_config_set_out_shift(&c, false, true, colourFormat); /* false: shift left. true: auto-pull. Number of bits based on rgb or rgbw */
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX); /* combine both FIFOs as TX_FIFO, so we have a bigger FIFO */
    /* calculate state machine clocking based on protocol needs */
    float div = clock_get_hz(clk_sys) / (freq * ws2812_NOF_CYCLES_FOR_1_BIT);
    sm_config_set_clkdiv(&c, div);
    /* initialize PIO and start it */
    pio_sm_init(pio, state_machine, offset, &c);
    pio_sm_set_enabled(pio, state_machine, true); /* true: enable pio */
}

int ws2812_transfer(PIO pio, uint state_machine, void *sourceAddress, size_t nofBytes)
{
  uint32_t *p = (uint32_t*)sourceAddress;
  for(int i=0; i<nofBytes/sizeof(uint32_t); i++) { /* without DMA: writing one after each other */
    pio_sm_put_blocking(pio, state_machine, *p);
    p++;
  }
  return 0; /* ok */
}
