#include<bits/stdc++.h>

using namespace std;

class Medicine
{
  private :
    char trade_name[30];
    char generic_name[30];
    double unit_price;
    double discountPercent;

  public :

    void assignName(char name[], char genericName[])
    {
        strcpy(trade_name,name);
        strcpy(generic_name,genericName);
    }

    void assignPrice(double price)
    {
        unit_price= price;
    }

    void setDiscountPercent(double percent)
    {
        discountPercent= percent;
    }

    double getSellingPrice(int nos=1)
    {
        double discount= (unit_price*discountPercent)/100;
        double sellingPrice= nos*(unit_price-discount);
        return sellingPrice;
    }
    double getSellingPrice()
    {
        double discount= (unit_price*discountPercent)/100;
        double sellingPrice= (unit_price-discount);
        return sellingPrice;
    }

    void display()
    {
        int a= 5;
        double x= getSellingPrice();
        cout << "MRP of " << trade_name << "(" << generic_name << ") is BDT. " << unit_price << ". Current discount " << discountPercent << "%. Selling price BDT " << x/double(a) << ". For total no of " << trade_name << ", price is BDT. " << x << endl;
    }
};

int main()
{
    Medicine medical ;
    char a[]="Napa";
    char b[]="Paracetamol";
    medical.assignName(a,b);
    medical.assignPrice(1.00);
    medical.setDiscountPercent(10);
    medical.display();

    return 0;
}
