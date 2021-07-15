#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_4_down; /* effectively boolean */

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
  switch_4_down = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */
  
  if( switch_4_down ){ state_advance(); }
}
