#ifndef switches_included
#define switches_included

#define SW1 BIT0                          /* switch1 is p2.0 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1|SW2|SW3|SW4)	

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down_1, switch_state_down_2, switch_state_down_3, switch_state_down_4, switch_state_changed;

#endif // included