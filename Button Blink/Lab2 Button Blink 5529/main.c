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

    P1SEL = 0x00; //sets P1 to GPIO

    P1DIR = BIT0; //sets P1.0 to an output rest are inputs

    P1REN = BIT1; //Resistor enabled for P1.1 button
    P1OUT = BIT1; //pull up resistor for button P1.1

    for(;;){ //infinite loop
        if ((P1IN&BIT1)==0x00) //if button 1 is pushed
        {
            P1OUT ^= 0x01; //toggle LED
        }
    }

    return 0;
}
