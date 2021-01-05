#ifndef _POTENTIOMETER_H
#define _POTENTIOMETER_H

#include <Arduino.h>
#include <math.h>

typedef unsigned const char pin_number;

template <unsigned const int T_ADC> // bit depth of ADC

class Potentiometer
{
	public:
			Potentiometer(pin_number p){
				pin = p;
				PinMode(pin, INPUT_PULLUP);
				}
				
			Potentiometer (pin_number p, float voltage){
				pin = p;
				PinMode(pin, INPUT_PULLUP);
				AREF_VOLTAGE = voltage;
				}
			
			//double getValueAsCoeff(void) {return ceil((analogRead(pin)/(T_ADC - 1));}
			float getValueAsCoeff(void) const {return (float)(ceil((analogRead(pin)/(T_ADC - 1)));}
			unsigned char getValueAsPercent(void) const {return ((analogRead(pin)/(T_ADC - 1))*100);}
			unsigned int getValue(void) const {return analogRead(pin);}
			float getVoltage(void) const {return ((analogRead(pin) / (T_ADC - 1)) * AREF_VOLTAGE);}
			
	private: 
			pin_number analog_pin;
			float AREF_VOLTAGE;
			
			
};

#endif //_POTENTIOMETER_H

