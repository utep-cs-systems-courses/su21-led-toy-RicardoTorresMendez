#ifndef switches_included
#define switches_included

#define SW1 BIT0		
#define SW2 BIT1		
#define SW3 BIT2		
#define SW4 BIT3		

#define SWITCHES (SW1|SW2|SW3|SW4)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_1_down, switch_2_down, switch_3_down, switch_4_down; /* effectively boolean */

#endif // included
