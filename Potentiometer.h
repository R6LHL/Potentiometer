#ifndef _POTENTIOMETER_H
#define _POTENTIOMETER_H

#include <Arduino.h>

typedef unsigned char pin_num;

template <unsigned const int T_ADC> // bit depth of ADC

class Potentiometer
{
	public:
			Potentiometer(pin_num p){
				analog_pin = p;
				pinMode(analog_pin, INPUT);
				}
				
			Potentiometer (pin_num p, float voltage){
				analog_pin = p;
				pinMode(analog_pin, INPUT);
				AREF_VOLTAGE = voltage;
				}
			
			//double getValueAsCoeff(void) {return ceil((analogRead(analog_pin)/(T_ADC - 1));}
			float getValueAsCoeff(void){
			
				int adc = analogRead(analog_pin);
				int adc_bit_depth = (T_ADC - 1);
				return (float)adc / (float)adc_bit_depth;
			}
			
			unsigned char getValueAsPercent(void){return ((analogRead(analog_pin)/(T_ADC - 1))*100);}
			unsigned int getValue(void) {return analogRead(analog_pin);}
			float getVoltage(void) {
				int adc = analogRead(analog_pin);
				int adc_bit_depth = (T_ADC - 1);
				return ((float)(analogRead(analog_pin) / (float)(T_ADC - 1)) * AREF_VOLTAGE);
				}
			
	private: 
			pin_num analog_pin;
			float AREF_VOLTAGE;
			
			
};

#endif //_POTENTIOMETER_H

