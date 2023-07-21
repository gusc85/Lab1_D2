#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>  

extern char DisplayLow_ADC;
extern char DisplayHigh_ADC;
extern unsigned char Low_ADC;
extern unsigned char High_ADC;
extern unsigned char Resultado_ADC;

void InterruptADC(char* DisplayLow_ADC, char* DisplayHigh_ADC);

#endif