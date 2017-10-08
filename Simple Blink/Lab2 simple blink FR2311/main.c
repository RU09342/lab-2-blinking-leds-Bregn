#include <msp430.h> 
//By Bryan Regn
//Last updated 10/7/17

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    //needed when using msp430 processors used to reset device to previous state
	
	PM5CTL0 &= ~LOCKLPM5;

	unsigned int i=0;

	P1SEL0 = 0x00; // sets pin 1 to GPIO
	P1SEL1 = 0x00; // sets pin 1 to GPIO

	P1DIR = 0x01; //sets pin 1 to an output

	P1OUT = 0x00; //initializes LED

    for(;;){ //infinite loop
        P1OUT ^= 0x01; //uses xor to toggle P1OUT

        for(i=0; i<20000; i++); //delay used to see led blink

    }
	return 0;
}
