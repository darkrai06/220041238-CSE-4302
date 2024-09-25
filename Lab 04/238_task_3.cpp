#include <bits/stdc++.h>
using namespace std;

class EmployeeList
{
private:
    string EmpName;
    int ID;
    int age;
    float salary;

    void getstatus()
    {
        if(age<=25){
            if(salary<=20000) cout<<"Low";
            else cout<<"Moderate";
        }
        else{
           if(salary<=21000) cout<<"Low";
           else if(salary<=60000) cout<<"Moderate";
           else cout<<"High";
        }
    }
public:
    void FeedInfo()
    {
        cout<<"Enter Employee name: ";
        cin>>EmpName;

        cout<<"Enter Employee ID: ";
        cin>>ID;

        cout<<"Enter Employee Salary: ";
        cin>>salary;
    }

    void ShowInfo()
    {
        cout<<"Enter Employee name: "<<EmpName<<endl;
        cout<<"Enter Employee ID: "<<ID<<endl;
        cout<<"Enter Employee Salary: "<<salary<<endl;

        getstatus();
        cout<<" Salaried Person"<<endl;
    }
};

int main()
{
    EmployeeList e;
    e.FeedInfo();

    e.ShowInfo();
}
