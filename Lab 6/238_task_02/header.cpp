#include "header.h"

Coordinate::Coordinate() : x(0), y(0) {}

Coordinate::Coordinate(float abscissa,float ordinate)
{
    x=abscissa;
    y=ordinate;
}

float Coordinate::getDistance()const
{
    float dist= sqrt(x*x+y*y);
    return dist;
}

float Coordinate:: operator-(Coordinate c)
{
    return sqrt(pow(c.x - x, 2) + pow(c.y - y, 2));
}

void Coordinate::display()const
{
    cout << "Coordinate: (" << x << ", " << y << ")" << endl;
}

void Coordinate::move_x(float val)
{
    x += val;
}

void Coordinate::move_y(float val)
{
    y += val;
}

void Coordinate::moves(float x_val,float y_val)
{
    x += x_val;
    y += y_val;
}

bool Coordinate::operator>(const Coordinate &c)const
{
    return (getDistance() > c.getDistance());
}

bool Coordinate::operator<(const Coordinate &c)const
{
    return getDistance() < c.getDistance();
}

bool Coordinate::operator>=(const Coordinate &c)const
{
    return getDistance() >= c.getDistance();
}

bool Coordinate::operator<=(const Coordinate &c)const
{
    return getDistance() <= c.getDistance();
}

bool Coordinate::operator==(const Coordinate &c)const
{
    return getDistance() == c.getDistance();
}

bool Coordinate::operator!=(const Coordinate &c)const
{
    return getDistance() != c.getDistance();
}

Coordinate:: ~Coordinate() {}

void highest(Coordinate c[], int size)
{
    int index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (c[i] > c[index])
        {
            index = i;
        }
    }
    cout << "Coordinate with highest distance from origin: ";
    c[index].display();
}

void lowest(Coordinate c[], int size)
{
    int index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (c[i] < c[index])
        {
            index = i;
        }
    }
    cout << "Coordinate with lowest distance from origin: ";
    c[index].display();
}

float randomInRange(float min, float max)
{
    if (min > max)
    {
        swap(min, max);
    }

    float randomFraction = static_cast<float>(rand()) / RAND_MAX;

    return min + randomFraction * (max - min);
}

void randomAssignment(Coordinate c[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        float x = randomInRange(-100.0, 100.0);
        float y = randomInRange(-100.0, 100.0);
        c[i] = Coordinate(x, y);
    }
}


