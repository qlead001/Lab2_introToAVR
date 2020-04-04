/*	Author: Quinn Leader qlead001@ucr.edu
 *      Partner(s) Name: NA
 *	Lab Section: 026
 *	Assignment: Lab 2  Exercise 2
 *	Exercise Description: Parking space counter
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s

    /* Insert your solution below */
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char cntavail = 0x00; // Temporary variable to hold the value of space count
    while (1) {
        // 1) Read input
        tmpA = PINA & 0x0F;
        // 2) Perform computation
        cntavail = !(tmpA & 0x01) + !(tmpA & 0x02) + !(tmpA & 0x04) + !(tmpA & 0x08);
        // 3) Write output
        PORTC = cntavail;    
    }
    return 1;
}
