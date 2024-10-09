#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int n=10;
    Coordinate coord[n];
    randomAssignment(coord, n);
    highest(coord, n);
    lowest(coord, n);
    return 0;
}
