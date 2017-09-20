#include <msp430.h> 
//By Bryan Regn
//Last updated 9/20/17

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed when using msp430 processors used to reset device to previous state

    P1SEL0 = 0x00; // sets pin 1 to GPIO
    P1SEL1 = 0x00; // sets pin 1 to GPIO
    P2SEL0 = 0x00; // sets pin 2 to GPIO
    P2SEL1 = 0x00; // sets pin 2 to GPIO

    P1DIR = 0x01; //sets pin 1 to an output
    P2DIR = 0x01; //sets pin 2 to an output

    P1OUT = 0x00; //initializes LED
    P2OUT = 0x00; //initializes LED

    for(;;){ //infinite loop
        if(i=2000){
        P1OUT ^= 0x00; //uses xor to toggle P1.0 (first LED)
        i=0;
        }
        if(q=3000){
        P2OUT ^= 0x00; // uses xor to toggle P2.0 (Second LED)
        q=0;
        }
        for(q=0; q<30000; q++); //delay used to see second led

        for(i=0; i<20000; i++); //delay used to see led blink

        }
    }
    return 0;
}
