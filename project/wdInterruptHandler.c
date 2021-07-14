#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT(){  /* 250 interrupts/sec */
  static char blink_count = 0;

  if( blink_count % 1 == 0 ){ green_on(); }
  else{ green_off(); }

  if (++blink_count == 250){ blink_count = 0; }
}























