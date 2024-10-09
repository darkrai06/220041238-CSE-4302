#include "header.h"
#include "header2.h"
#include "header3.h"

Fahrenheit::Fahrenheit() : temp(0){}

Fahrenheit::Fahrenheit(float x)
{
    assign(x);
}

void Fahrenheit::display()const
{
    if(temp!=-1000)
    cout << "The Current Temperature is " << temp << " Fahrenheit" << endl;
}

void Fahrenheit::assign(float x)
{
    if(x < -459.60)
    {
        temp=-1000;
        cout << "Temperature not valid" << endl;
    }
    else temp=x;
}

Fahrenheit::operator Celsius()
{
    float celsius_temp = (temp - 32) * 5.0/9.0;
    return Celsius(celsius_temp);
}

Fahrenheit::operator Kelvin()
{
    float kelvin_temp = ((temp - 32) * 5.0/9.0) + 273.15;
    return Kelvin(kelvin_temp);
}

