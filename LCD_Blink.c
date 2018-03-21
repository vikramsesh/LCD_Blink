/*
 * File:   main.c
 * Author: Vikram
 *
 * Created on January 18, 2018, 2:32 PM
 */

#define LED_BLED _RD2 //RD2 is short for PORTDbits.RD2 - selects pin 2 of the I/O PORTD register of the PIC24
#define ConfigureBacklight() _TRISD2=0 // TRSIDbits.TRISD2 control bit that defines the direction of the I/O pin. 0-output, 1-input
/*FCY = FOSC/2
 * FOSC = FIN (M/N1*N2)
 * M=50, N1=2, N2=4
 * FIN = 8Mhz
 * FOSC = 50MHz
 * FCY = 25Mhz
*/
#define FCY 25000000UL/256/4 

#include "xc.h"

#pragma config FNOSC = PRIPLL // Initial Oscillator Source Selection bits (Primary Oscillator (XT, HS, EC) with PLL)
#pragma config POSCMD = XT // Primary Oscillator Mode Select bits (HS Crystal Oscillator Mode)

int main(void) {
    ConfigureBacklight(); //configure I/O as output
    T1CON = 0x8030; //internal clock/2/256
    
    while(1)
    {
        TMR1=0; //delay
        while (TMR1<FCY);
        LED_BLED = 1-LED_BLED; //toggle LED_BLED output
    }
    
    return 0;
}


