#include<bits/stdc++.h>

using namespace std;

class RationalNumber
{
  private :
    int numerator_num;
    int denominator_num;

  public :
    void assign(int numerator,int denominator)
    {
       numerator_num= numerator;
       if(denominator==0)
           cout << "You can not assign 0 as denominator" << endl;
       else denominator_num= denominator;
   }

   float convert()
   {
       return ((float)numerator_num/(float)denominator_num);
   }

   void invert()
   {
       if(numerator_num==0)
           cout << "You can not assign 0 as denominator. Inversion Failed" << endl;
       else swap(numerator_num, denominator_num);
   }

   void print()
   {
       if(denominator_num!=0)
           cout << "The Rational Number is " << numerator_num << "/" << denominator_num << endl;
   }

};

int main()
{
    RationalNumber number;
    number.assign(3,2);
    number.print();
    number.invert();
    number.print();
    cout << "The decimal equivalent value is " << number.convert() << endl;
}

