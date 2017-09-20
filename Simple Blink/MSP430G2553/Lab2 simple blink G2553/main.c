#include <msp430.h> 
//By Bryan Regn
//Last updated 9/17/17

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed when using msp430 processors used to reset device to previous state

    P1SEL = 0x00; // sets pin 1 to GPIO
    P1SEL2 = 0x00; // sets pin 1 to GPIO

    ADC10AE.0 =0x00;
    INCH.0 = 0x01;
    CAPD.y = 0x00;

    P1DIR = 0x01; //sets pin 1 to an output

    P1OUT = 0x00; //initializes LED

    for(;;){ //infinite loop
        P1OUT ^= 0x01; //uses xor to toggle P1OUT

        for(i=0; i<20000; i++); //delay used to see led blink

    }
    return 0;
}
