#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    float x;
    float y;

public:
    Coordinate();
    Coordinate(float abscissa,float ordinate);
    float getDistance()const;
    void display()const;
    void move_x(float val);
    void move_y(float val);
    void moves(float x_val,float y_val);
    float operator -(Coordinate c);
    bool operator >(const Coordinate &c)const;
    bool operator <(const Coordinate &c)const;
    bool operator >=(const Coordinate &c)const;
    bool operator <=(const Coordinate &c)const;
    bool operator ==(const Coordinate &c)const;
    bool operator !=(const Coordinate &c)const;
    ~Coordinate();
};

float randomInRange(float min, float max);
void randomAssignment(Coordinate c[], int size);
void highest(Coordinate c[], int size);
void lowest(Coordinate c[], int size);


#endif

