#ifndef HEADER2_H
#define HEADER2_H

#include <bits/stdc++.h>
using namespace std;

class Celsius
{
private:
    float temp;

public:
    Celsius();
    Celsius(float x);
    void display() const;
    void assign(float x);
    operator Kelvin();
    operator Fahrenheit();
};


#endif
