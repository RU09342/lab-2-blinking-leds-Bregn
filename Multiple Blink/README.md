# Multiple Blink
By Bryan Regn
Created 9/13/17
Last updated 10/8/17

## Dependencies
Similar to other labs this code is dependant on the MSP430.h file. 

## Differences from board to board 
The multiple blink was similar from processor to processor with slight differences. 
For all processor the DIR signal needed to be 1 to be an output, also the SEL signal had to be 0.
Some processors had different SEL signals though. The 5529 had one SEL signal. FR2311, FR5994, and FR6989 used SEL1 and SEL0. The G2553 used SEL and SEL2.
For the MSP430FR family of processors the following line of code was required to turn off the default high impedance mode on GPIO: PM5CTL0 &= ~LOCKLPM5;
For all processor LED 1 was used as P1.0. LED 2 changed from processor to processor. 
For the 5529 LED was P4.7. For the FR2311 LED 2 was P2.0. For the FR5994 LED 2 was P1.1. For the FR6989 LED 2 was P9.7. For the G2553 LED 2 was P1.6.
I ran an infinite loop that used two different modulus (%) divisors to toggle the two different LEDs at different rates.  