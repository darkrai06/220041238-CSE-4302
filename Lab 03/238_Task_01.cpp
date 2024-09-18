#include<bits/stdc++.h>

using namespace std;

class Counter
{
  private :

    int count=0;
    int increment_steps;

  public :

    void setIncrementStep(int steps)
    {
        increment_steps= steps;
    }

    int getCount()
    {
        return count;
    }

    void increment()
    {
        count+= increment_steps;
    }

    void resetCount()
    {
        count=0;
    }
};

int main()
{
    Counter counting;

    counting.setIncrementStep(5);
    cout << "The current value of count is : " << counting.getCount() << endl;
    counting.increment();
    cout << "The current value of count is : " << counting.getCount() << endl;
    counting.increment();
    cout << "The current value of count is : " << counting.getCount() << endl;
    counting.resetCount();
    cout << "The current value of count is : " << counting.getCount() << endl;

    return 0;
}
