#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_1_down, switch_2_down, switch_3_down, switch_4_down; /* effectively boolean */

static char 
switch_update_interrupt_sense(){
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init(){			/* setup switch */  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  switch_1_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_2_down = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  switch_3_down = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  switch_4_down = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */
  
  if( switch_4_down ){ state_advance(); }

  /* start buzzing!!! */
  if( switch_1_down ){ buzzer_set_period(100 + octave ); }
  if( switch_2_down ){ buzzer_set_period(150 + octave ); }
  if( switch_3_down ){ buzzer_set_period(200 + octave ); }

  if( switch_1_down || switch_2_down || switch_3_down ){ note_pressed = 1; }
  else{
    note_pressed = 0;
    buzzer_set_period( 0 );
  }


}

