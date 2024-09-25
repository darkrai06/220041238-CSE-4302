#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Trigonometry_Calculator
{
   private :
       float currentAngle;
       float get_angle()
       {
           return currentAngle;
       }

   public :

       Trigonometry_Calculator()
       {
           currentAngle= 0;
       }

       Trigonometry_Calculator(float value)
       {
           currentAngle= value;
       }

       float calculateSine()
       {
           float rad= currentAngle*M_PI/180.0;
           float ang= sin(rad);

           return ang;
       }

       float calculateCosine()
       {
           float rad= currentAngle*M_PI/180.0;
           float ang= cos(rad);

           return ang;
       }

       float calculateTangent()
       {
           if((int)currentAngle==currentAngle && ((int)currentAngle/90)%2!=0)
           {
               cout << "Tan : Invalid Value" << endl;
               return 0.5;
           }

           float rad= currentAngle*M_PI/180.0;
           float ang= tan(rad);

           return ang;
       }

       float calculateArcSine()
       {
           float rad= currentAngle*M_PI/180.0;
           float ang= asin(rad);

           return ang;
       }

       float calculateArcCosine()
       {
           float rad= currentAngle*M_PI/180.0;
           float ang= acos(rad);

           return ang;
       }

       float calculateArcTangent()
       {
           float rad= currentAngle*M_PI/180.0;
           float ang= atan(rad);

           return ang;
       }

       void calculateForAngle(float paramAngle)
       {
           cout << sin((paramAngle*M_PI)/180.0) << endl;
           cout << cos((paramAngle*M_PI)/180.0) << endl;
           cout << tan((paramAngle*M_PI)/180.0) << endl;
       }

       void clear()
       {
           currentAngle= 0;
       }

       void display()
       {
           cout << get_angle() << endl;
       }

       ~Trigonometry_Calculator()
       {
           cout << "Destructor of the Calculator object is called." << endl;
       }
};


int main()
{
    Trigonometry_Calculator calculate(30);

    cout << "Sin : " << calculate.calculateSine() << endl;
    cout << "Cos : " << calculate.calculateCosine() << endl;
    if(calculate.calculateTangent()!=0.5)
        cout << "Tan : " << calculate.calculateTangent() <<endl;

    cout << "ArcSin : " << calculate.calculateArcSine() << endl;
    cout << "ArcCos : " << calculate.calculateArcCosine() << endl;
    cout << "ArcTan : " << calculate.calculateArcTangent() << endl;
    calculate.display();
    calculate.calculateForAngle(60);
}
