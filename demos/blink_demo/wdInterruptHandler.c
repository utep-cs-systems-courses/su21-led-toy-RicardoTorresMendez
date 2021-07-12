#include <msp430.h>
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count >= 50){
    green_on &= 0;
    led_changed = 1;
    if(blink_count >= 100){
      green_on |= 1;
      led_changed = 1;
      blink_count = 0;
    }
    led_update();
  }
}
