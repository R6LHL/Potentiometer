# Potentiometer
Library for a different potentiometric sensors

## Шаблон класса для работы с потенциометрическими датчиками

### Сначала необходимо определить шаблон разрядностью АЦП вашего контроллера, например:

```C++
#include <Potentiometer.h>

typedef Potentiometer<1024> Potentiometer10bit;
```
### Затем определить сам потенциометер ногой, на которую он повешен:
```C++
Potentiometer10bit rpm_regulator(rpm_regulator_pin); // typedef unsigned const char pin_number;
```
либо ногой и напряжением AREF:
```C++
Potentiometer10bit rpm_regulator(rpm_regulator_pin, aref_voltage); //(pin_number, float)
```

## Для чего всё это?
Ради трёх полезных функций.

```C++
float getValueAsCoeff(void); // возвращает значение от 0 до 1.0, то есть часть от полного значения.
```
```C++
unsigned const char getValueAsPercent(void) // возвращает значение от 0 до 100, то есть процентное значение от полного значения.
```
```C++
float getVoltage(void) // выдаёт значение напряжения на ноге.
```
ну и обычная функция:
```C++
unsigned const int getValue(void); //просто возвращает значение АЦП.
```
