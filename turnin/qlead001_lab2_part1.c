/*	Author: Quinn Leader qlead001@ucr.edu
 *      Partner(s) Name: NA
 *	Lab Section: 026
 *	Assignment: Lab 2  Exercise 1
 *	Exercise Description: Garage door system
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
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

    /* Insert your solution below */
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    while (1) {
        // 1) Read input
        tmpA = PINA & 0x03;
        // 2) Perform computation
        // if PA1PA0 is 01, set PB0 = 1, else = 0
        tmpB = (tmpB & 0xFE) | (tmpA == 0x01);
        // 3) Write output
        PORTB = tmpB;    
    }
    return 1;
}
