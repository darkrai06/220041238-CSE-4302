#include<iostream>
#include<cstdio>

using namespace std;

struct fraction
{
    int numerator;
    int denominator;
};

signed main()
{
    struct fraction first;
    struct fraction second;

    char s='/';
    cout << "Enter First Fraction : " ;
    cin >> first.numerator >> s >> first.denominator;
    cout << "Enter Second Fraction : " ;
    cin >> second.numerator >> s >> second.denominator;

    int num= (first.numerator*second.denominator)+(second.numerator*first.denominator);
    int deno = (first.denominator*second.denominator);

    cout << "Sum : " << num << "/" << deno << endl;
}
