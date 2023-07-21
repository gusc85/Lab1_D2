#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>  

extern unsigned char contador;
extern unsigned char DISPLAY[];
extern unsigned char sumaADC;

extern char DisplayLow_ADC;
extern char DisplayHigh_ADC;

void InterruptTMR0(char DisplayLow_ADC, char DisplayHigh_ADC);

#endif
