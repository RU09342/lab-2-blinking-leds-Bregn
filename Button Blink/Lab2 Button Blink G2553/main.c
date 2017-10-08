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

    P1SEL = 0x00; // sets pin 1 to GPIO
    P1SEL2 = 0x00; // sets pin 1 to GPIO

    P1DIR = BIT0; //sets pin 1.0 to an output rest are inputs

    P1REN = BIT3; //Resistor enabled for button P1.3
    P1OUT = BIT3; //Resistor pulled up

    for(;;){ //infinite loop
        if ((P1IN&BIT3)==0x00) //if button is pushed
        {
            P1OUT ^= 0x01; //turn on LED
        }
    }
    return 0;
}
