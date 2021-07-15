#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT(){  /* 250 interrupts/sec */
  static char blink_count = 0;

  if( note_pressed ){ turn_red_on(); }
  //else{ turn_red_off(); }

  if( blink_count % delay == 0 ){ turn_green_on(); }//6
  else{ turn_green_off(); }

  if (++blink_count == 250){
    blink_count = 0;
  }

}























