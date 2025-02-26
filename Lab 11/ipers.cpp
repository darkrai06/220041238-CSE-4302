#include <fstream>
#include <iostream>
using namespace std;

class person {
protected:
    char name[80];
    short age;

public:
    void showData()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    person pers;
    ifstream infile("PERSON.DAT", ios::binary);

    if (!infile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();

    return 0;
}
