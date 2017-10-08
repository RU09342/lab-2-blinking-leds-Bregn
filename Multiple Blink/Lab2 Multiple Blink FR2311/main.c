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

    PM5CTL0 &= ~LOCKLPM5;

    unsigned int i=0;

    P1SEL0 = 0x00; // sets pin 1 to GPIO
    P1SEL1 = 0x00; // sets pin 1 to GPIO
    P2SEL0 = 0x00; // sets pin 2 to GPIO
    P2SEL1 = 0x00; // sets pin 2 to GPIO

    P1DIR = BIT0; //sets pin 1.0 to an output
    P2DIR = BIT0; //sets pin 2.0 to an output

    P1OUT = 0x00; //initializes LED
    P2OUT = 0x00; //initializes LED

    for(;;){ //infinite loop
        for(i=0; i<20000; i++);{
            if(i%1000==0){
                (P2OUT)^= BIT0; // uses xor to toggle P2.0 (Second LED)
            }
            if(i%2000==0){
                (P1OUT)^= BIT0; //uses xor to toggle P1.0 (first LED)
            }
        }
    }
    return 0;
}
