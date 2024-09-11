#include<iostream>
#include<cstdio>

using namespace std;

signed main()
{
    int a,b,c,d;
    char s='/';
    cout << "Enter First Fraction : " ;
    cin >> a >> s >> b;
    cout << "Enter Second Fraction : " ;
    cin >> c >> s >> d;

    int ans = ((a*d)+(b*c)) ;
    int deno = (b*d);
    cout << "Sum : " << ans << "/" << deno << endl;
}
