/*	Author: Quinn Leader qlead001@ucr.edu
 *      Partner(s) Name: NA
 *	Lab Section: 026
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: Amusement park ride weight detection
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
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s

    /* Insert your solution below */
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
    unsigned short total = 0x00;
    unsigned char diffAC = 0x00;
    unsigned char out = 0x00;
    while (1) {
        // 1) Read input
        tmpA = PINA; tmpB = PINB; tmpC = PINC;
        // 2) Perform computation
        // Calculate total weight
        total = (unsigned short)tmpA + (unsigned short)tmpB + (unsigned short)tmpC;
        // Find the difference between A and C
        diffAC = (tmpA > tmpC)?tmpA-tmpC:tmpC-tmpA;
        // Check if total weight exceeds 140kg
        out = (total > 140);
        // Check if A and C differ by more than 80kg
        out = out | ((diffAC > 80) << 1);
        // PD[7:2] is total weight divided by 16
        out = out | ((total / 12) << 2);
        // 3) Write output
        PORTD = out;
    }
    return 1;
}
