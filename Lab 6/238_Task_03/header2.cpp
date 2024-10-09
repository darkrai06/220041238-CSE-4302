#include "header.h"
#include "header2.h"
#include "header3.h"

Celsius::Celsius() : temp(0){}

Celsius::Celsius(float x)
{
    assign(x);
}

void Celsius::display()const
{
    if(temp!=-1000)
    cout << "The Current Temperature is " << temp << " Celsius" <<endl;
}

void Celsius::assign(float x)
{
    if(x < -273.15)
    {
        temp=-1000;
        cout << "Temperature not valid" << endl;
    }
    else temp=x;
}

Celsius::operator Kelvin()
{
    float kelvin_temp = temp + 273.15;
    return Kelvin(kelvin_temp);
}

Celsius::operator Fahrenheit()
{
    float fahrenheit_temp = (temp * 9.0/5.0) + 32;
    return Fahrenheit(fahrenheit_temp);
}

