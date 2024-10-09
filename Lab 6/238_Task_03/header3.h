#ifndef HEADER3_H
#define HEADER3_H

#include <bits/stdc++.h>
using namespace std;

class Fahrenheit
{
private:
    float temp;

public:
    Fahrenheit();
    Fahrenheit(float x);
    void display() const;
    void assign(float x);
    operator Celsius();
    operator Kelvin();
};


#endif
