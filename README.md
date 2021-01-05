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
Potentiometer10bit rpm_regulator(rpm_regulator_pin);
```
## Для чего всё это?
Ради двух полезных функций.

```C++
float getValueAsCoeff(void); // возвращает значение от 0 до 1.0, то есть часть от полного значения. Можно использовать как множитель.
```
```C++
unsigned const char getValueAsPercent(void) // возвращает значение от 0 до 100, то есть процентное значение от полного значения.
```
ну и обычная функция:
```C++
unsigned const int getValue(void); //просто возвращает значение АЦП.
```
