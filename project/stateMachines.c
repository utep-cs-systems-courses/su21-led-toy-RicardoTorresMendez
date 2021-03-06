#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char current_state = 0, delay = 1, note_pressed = 0, octave = 0;

void state_advance(){    /* alternate between toggling red & green */
  if( current_state < 3 ){ current_state++; }
  else{ current_state = 0; }

  delay = ( current_state * 2 ) + 1; //change dimness

  octave = ( current_state * 150 ); 
  
}

void turn_green_on(){
  green_on = 1;
  led_changed = 1;
  led_update();
}

void turn_green_off(){
  green_on = 0;
  led_changed = 1;
  led_update();
}

void turn_red_on(){
  red_on = 1;
  led_changed = 1;
  led_update();
}

void turn_red_off(){
  red_on =0;
  led_changed = 1;
  led_update();
}


