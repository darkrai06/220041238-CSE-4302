#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;

class Kelvin
{
private:
    float temp;

public:
    Kelvin();
    Kelvin(float x);
    void display() const;
    void assign(float x);
    operator Celsius();
    operator Fahrenheit();
};

#endif
