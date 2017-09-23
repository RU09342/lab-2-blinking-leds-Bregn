#include <msp430.h> 
//By Bryan Regn
//Last updated 9/23/17

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed when using msp430 processors used to reset device to previous state

    PM5CTL0 &= ~LOCKLPM5;

    P1SEL0 = 0x00; // sets pin 1 to GPIO
    P1SEL1 = 0x00; // sets pin 1 to GPIO
    P5SEL0 = 0x00; // sets pin 5 to GPIO
    P5SEL1 = 0x00; // sets pin 5 to GPIO

    P1DIR = 0x01; //sets pin 1.0 to an output rest are inputs

    P5REN = BIT6; //Resistor enable for P5.6 button
    P5OUT = BIT6; //Pull up resistor for button

    for(;;){ //infinite loop
        if ((P5IN&&BIT6)==0x00) //if button is pushed
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
