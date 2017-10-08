#include <msp430.h> 
//By Bryan Regn
//Last updated 10/7/17

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed when using msp430 processors used to reset device to previous state

    unsigned int i=0;

    P1SEL = 0x00; // sets pin 1 to GPIO
    P1SEL2 = 0x00; // sets pin 1 to GPIO

    P1DIR = BIT0 | BIT6; //sets pin 1.0 and 1.6 to an output

    P1OUT = 0x00; //initializes LED

    for(;;)
    { //infinite loop
        for(i=0; i<20000; i++);{
            if(i%2000==0){
                P1OUT^= BIT6; // uses xor to toggle P1.6 (Second LED)
            }
            if(i%5000==0){
                P1OUT ^= BIT0; //uses xor to toggle P1.0 (first LED)
            }

        }
    }
    return 0;
}
