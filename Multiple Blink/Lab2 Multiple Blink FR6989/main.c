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
    P9SEL0 = 0x00; // sets pin 9 to GPIO
    P9SEL1 = 0x00; // sets pin 9 to GPIO

    P1DIR = BIT0; //sets pin 1.0 to an output
    P9DIR = BIT7; //sets pin 9.7 to an output

    P1OUT = 0x00; //initializes LED
    P9OUT = 0x00; //initializes LED

    for(;;){ //infinite loop
        for(i=0; i<50000; i++);
        if(i%20000){
        P1OUT^= BIT0; //uses xor to toggle P1.0 (first LED)
        }
        if(i%40000){
        P9OUT^= BIT7; // uses xor to toggle P9.7 (Second LED)
        }

    }
    return 0;
}
