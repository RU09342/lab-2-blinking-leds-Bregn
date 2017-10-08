#Simple Blink
By Bryan Regn
Created 9/13/17
Last updated 10/8/17

# Dependancies
Similar to all labs MSP430.h was required. 

# Reference guide
When starting out I used this link as a reference and used their code to get a basic understanding and get started:
http://wisense.in/docs/TI-2013-MSP430F5529-LaunchPad-CCS.pdf

# Functionality and differences 
The simple blink was bassically the same from processor to processor with slight differences.
For all processor the DIR signal needed to be 1 to be an output, also the SEL signal had to be 0 to make it a GPIO.
Some processors had different SEL signals though. The 5529 had one SEL signal. FR2311, FR5994, and FR6989 used SEL1 and SEL0. The G2553 used SEL and SEL2.
For the MSP430FR family of processors the following line of code was required to turn off the default high impedance mode on GPIO: PM5CTL0 &= ~LOCKLPM5;
I ran an infinite loop that toggles the LED every 20,000 clock cycles. 