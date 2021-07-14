#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT(){  /* 250 interrupts/sec */
  static char blink_count = 0;

  if( blink_count % 1 == 0 ){ turn_green_on(); }
  else{ turn_green_off(); }

  if (++blink_count == 250){ blink_count = 0; }
}























