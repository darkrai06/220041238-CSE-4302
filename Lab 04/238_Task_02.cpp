#include <bits/stdc++.h>

using namespace std;

class BankAccount
{
   private :
       int account_num;
       string account_holder;
       string account_type;
       float current_balance;
       float min_balance;
       float get_balance();
       {
           return current_balance;
       }
       float get_minimum()
       {
           return min_balance;
       }

    public :
        BankAccount(int num, string type, string name, float value, float val)
        {
            current_balance= value;
            min_balance= val;
            account_num= num;
            account_holder= name;
            account_type= type;
        }

        void showBalance()
        {
            cout << get_balance() << endl;
        }

        void allInfo()
        {
            cout << "Account Number : " << account_num << endl;
            cout << "Account Holder's Name : " << account_holder << endl;
            cout << "Account Type : " << account_type << endl;
            cout << "Current Balance : " << current_balance << " taka" << endl;
            cout << "Minimum Balance : " << min_balance << " taka" << endl;
        }

        float deposit(float add)
        {
            current_balance= current_balance+add;
            return current_balance;
        }

        float withdraw(float deduct)
        {
            if(current_balance-deduct<min_balance)
            {
                cout << "Invalid Withdraw Amount" << endl;
                return -1;
            }
            current_balance= current_balance-deduct;
            return current_balance;
        }

        float giveInterest(float interest=3.00)
        {
            float inter= (current_balance*interest)/100.00;
            float deduce= inter- (inter*0.1);
            current_balance+= deduce;
        }

       ~BankAccount()
       {
           cout << "Account of " << account_holder <<  " with account no " << account_num << " is destroyed with a balance BDT " << current_balance << endl;
       }
};


int main()
{
    BankAccount info(11004,"savings","Mahin",666666.00,2000.00);
    info.allInfo();
    float amount= 1000;
    cout << info.deposit(amount) << endl;
    float withdraw= info.withdraw(amount);
    if(withdraw!=-1)
        cout << withdraw << endl;
    cout << info.giveInterest() << endl;
    info.showBalance();

    return 0;
}
