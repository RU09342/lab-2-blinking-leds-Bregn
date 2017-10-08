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

    unsigned int i=0;

	    P1SEL = 0x00; //sets P1 to GPIO
	    P4SEL = 0x00; //sets P4 to GPIO

	    P1DIR = BIT0; //P1DIR is the register used to control the direction of other pins (I/O)
	    //the above code sets P1.0 '1' making it an output
	    P4DIR = BIT7; //sets P4 to an output for the second led

	    P1OUT = 0x00; //initializes led
	    P4OUT = 0x00; //initializes led

	    for(;;){ //infinite loop
            for(i=0; i<20000; i++);
            if(i%1000==0){
            P4OUT^= BIT7; // uses xor to toggle P4.7 (Second LED)
            }
            if(i%2000==0){
	        P1OUT ^= BIT0; //uses xor to toggle P1.0 (first LED)
	        }
	        }
	return 0;
}
