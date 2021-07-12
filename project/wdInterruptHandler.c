#include <msp430.h>
#include "led.h"
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  if( blink_count % delay == 0){ /* turn on */
    led_changed = 1;
    green_led_on = 1;
  }
  else{ /* turn off */
    led_changed = 1;
    green_led_on = 0;
  }
  
  if (++blink_count == 250){ blink_count = 0; }
  
}
