#include "header.h"
#include "header2.h"
#include "header3.h"

Kelvin::Kelvin() : temp(0){}

Kelvin::Kelvin(float x)
{
    assign(x);
}

void Kelvin::display()const
{
    if(temp!=-1000)
    cout << "The Current Temperature is " << temp << " Kelvin" << endl;
}

void Kelvin::assign(float x)
{
    if(x<0)
    {
        temp=-1000;
        cout << "Temperature not valid" << endl;
    }
    else temp=x;
}

Kelvin::operator Celsius()
{
    float celsius_temp = temp - 273.15;
    return Celsius(celsius_temp);
}

Kelvin::operator Fahrenheit()
{
    float fahrenheit_temp = ((temp - 273.15) * 9.0/5.0) + 32;
    return Fahrenheit(fahrenheit_temp);
}

