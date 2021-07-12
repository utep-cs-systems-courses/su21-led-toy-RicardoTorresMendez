#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

unsigned char led_changed = 0;
unsigned char green_led_on = 0, red_led_on = 0;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= green_led_on ? LED_GREEN : 0;

    ledFlags |= red_led_on ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
}

