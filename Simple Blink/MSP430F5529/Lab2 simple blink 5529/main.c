#include <msp430.h> 
//By Bryan Regn
//Last updated 9/17/17

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//needed when using msp430 processors used to reset device to previous state

	P1SEL = 0x00; //sets P1 to GPIO

	P1DIR = 0x01; //P1DIR is the register used to control the direction of other pins (I/O)
	//the above code sets P1.0 '1' making it an output

	P1OUT = 0x00; //initializes led

	for(;;){ //infinite loop
	    P1OUT ^= 0x01; //uses xor to toggle P1OUT

	    for(i=0; i<20000; i++); //delay used to see led blink

	}
	
	return 0;
}
