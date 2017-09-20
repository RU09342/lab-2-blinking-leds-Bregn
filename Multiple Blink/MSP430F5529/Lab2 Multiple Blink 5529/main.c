#include <msp430.h> 
//By Bryan Regn
//Last updated 9/20/17

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//needed when using msp430 processors used to reset device to previous state

	    P1SEL = 0x00; //sets P1 to GPIO
	    P4SEL = 0x00; //sets P4 to GPIO

	    P1DIR = 0x01; //P1DIR is the register used to control the direction of other pins (I/O)
	    //the above code sets P1.0 '1' making it an output
	    P4DIR = 0x01; //sets P4 to an output for the second led

	    P1OUT = 0x00; //initializes led
	    P4OUT = 0x00; //initializes led

	    for(;;){ //infinite loop
	        if(i=2000){
	        P1OUT ^= 0x00; //uses xor to toggle P1.0 (first LED)
	        i=0;
	        }
	        if(q=3000){
	        P4OUT^= 0x07; // uses xor to toggle P4.7 (Second LED)
	        q=0;
	        }
	        for(q=0; q<30000; q++); //delay used to see second led

	        for(i=0; i<20000; i++); //delay used to see led blink

	        }
	return 0;
}
