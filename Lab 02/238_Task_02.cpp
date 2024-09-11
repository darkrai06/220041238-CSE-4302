#include<iostream>
#include<cstdio>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

signed main()
{
    char letter;
    cout << "Give input : " ;
    cin >> letter ;
    enum etype job;

    switch(letter)
    {
    case 'l':
        (job=laborer);
        break;
    case 's':
        (job=secretary);
        break;
    case 'm':
        (job=manager);
        break;
    case 'a':
        (job=accountant);
        break;
    case 'e':
        (job=executive);
        break;
    case 'r':
        (job=researcher);
        break;
    default:
        cout << "Not Found" << endl;
        return 0;
    }

    cout << "Employee type is : " ;

    switch(job)
    {
    case 0 :
        cout << "laborer";
        break;
    case 1 :
        cout << "secretary";
        break;
    case 2 :
        cout << "manager";
        break;
    case 3 :
        cout << "accountant";
        break;
    case 4 :
        cout << "executive";
        break;
    case 5 :
        cout << "researcher";
        break;
    default:
        cout << "Not Found" << endl;
        break;
    }


}

