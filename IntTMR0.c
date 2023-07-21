#include <stdint.h>
#include <pic16f887.h>
#include "IntTMR0.h"
#include <xc.h>  


char contador = 0x00;
unsigned char sumaADC;

unsigned char DISPLAY[0b00010000] = {
    0b1000000,//0
    0b1111001,//1
    0b0100100,//2
    0b0110000,//3
    0b0011001,//4
    0b0010010,//5
    0b0000010,//6
    0b1111000,//7
    0b0000000,//8
    0b0010000,//9
    0b0001000,//A
    0b0000011,//B
    0b1000110,//C
    0b0100001,//D
    0b0000110,//E
    0b0001110,};

void InterruptTMR0(char DisplayLow_ADC, char DisplayHigh_ADC){
    if(TMR0IF){
        TMR0 = 6;
        contador = !contador;
        
        if (contador == 0x01){
            RE1 = 0;
            RE0 = 1;
            PORTD = DISPLAY[DisplayLow_ADC];
        }
        if (contador == 0x00){
            RE0 = 0;
            RE1 = 1;
            PORTD = DISPLAY[DisplayHigh_ADC];
        }
        sumaADC = (DisplayHigh_ADC << 4) + DisplayLow_ADC;
        
        if (PORTC < sumaADC){
            RA0 = 0;
        }
        TMR0IF = 0;
    }
}



