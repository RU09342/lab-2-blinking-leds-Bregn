# Button Blink
By Bryan Regn
Created 9/13/17
Last updated 9/20/17

The button blink was similar from processor to processor with slight differences. 
For all processor the DIR signal needed to be 1 to be an output, also the SEL signal had to be 0. This is required to set LED pin.
The DIR signal needs to be 0 for the button pin to set it as an input, SEL still needs to be 0 to make it a GPIO instead of a peripheral.
Some processors had different SEL signals though. The 5529 had one SEL signal. FR2311, FR5994, and FR6989 used SEL1 and SEL0. The G2553 used SEL and SEL2.
Also the G2553 had some extra signals such as ADC10AE, CAPD, and INCH that were needed to make P1 I/O. 
The pins where buttons are changed from board to board. 
For the 5529, FR2311, FR6989, and G2553 the button was in P1. For the FR5994 the button was in P5.
After the it is set up correctly at the trigger of every button presh I used an xor to toggle the LED.