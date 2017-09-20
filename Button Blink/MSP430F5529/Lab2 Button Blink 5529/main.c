#include <msp430.h> 
//By Bryan Regn
//Last updated 9/18/17

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed when using msp430 processors used to reset device to previous state



    P1SEL = 0x00; //sets P1 to GPIO

    P1DIR = 0x01; //sets P1.0 to an output rest are inputs

    P1OUT = 0x00; //initializes led

    for(;;){ //infinite loop
        if (P1IN) //if button 1 is pushed
        {
            P1OUT = 0x01; //turn on LED
        }
        else  //if button 1 is not pushed
        {
            P1OUT = 0x00; //turn off LED
        }
    }

    return 0;
}
