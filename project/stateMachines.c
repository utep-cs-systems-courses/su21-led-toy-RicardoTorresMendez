#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

char delay = 5, current_state = 0;

void state_advance(){		/* change state */

  if( current_state == 0 ){
    current_state = 1;
    delay = 5;
  }
  else if( current_state == 1 ){
    current_state = 2;
    delay = 2;
  }
  else if( current_state == 2 ){
    current_state = 0;
    delay = 3;
  }

  led_update();
}



