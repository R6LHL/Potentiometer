#ifndef _POTENTIOMETER_H
#define _POTENTIOMETER_H

#include <Arduino.h>
#include <math.h>

typedef unsigned const char pin_number;

template <unsigned const int T_ADC> // bit depth of ADC

class Potentiometer
{
	public:
			Potentiometer(pin_number p) {pin = p;}
			
			//double getValueAsCoeff(void) {return ceil((analogRead(pin)/(T_ADC - 1));}
			float getValueAsCoeff(void) {return (float)(ceil((analogRead(pin)/(T_ADC - 1)));}
			unsigned const char getValueAsPercent(void) {return ((analogRead(pin)/(T_ADC - 1))*100);}
			unsigned const char getValue(void){return analogRead(pin);}
			
	private: 
			pin_number pin;
			
			
};

#endif //_POTENTIOMETER_H

