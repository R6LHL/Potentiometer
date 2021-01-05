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
			Potentiometer (pin_number p, float voltage){pin = p; AREF_VOLTAGE = voltage};
			
			//double getValueAsCoeff(void) {return ceil((analogRead(pin)/(T_ADC - 1));}
			float getValueAsCoeff(void) {return (float)(ceil((analogRead(pin)/(T_ADC - 1)));}
			unsigned const char getValueAsPercent(void) {return ((analogRead(pin)/(T_ADC - 1))*100);}
			unsigned const int getValue(void){return analogRead(pin);}
			float getVoltage(void){return ((analogRead(pin) / (T_ADC - 1)) * AREF_VOLTAGE);}
			
	private: 
			pin_number pin;
			float AREF_VOLTAGE;
			
			
};

#endif //_POTENTIOMETER_H

