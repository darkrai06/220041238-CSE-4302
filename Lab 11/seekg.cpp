#include <fstream>
#include <iostream>
using namespace std;

class person {
protected:
    char name[80];
    int age;

public:
    void getData()
    {
        cout << "\n Enter name: ";
        cin >> name;
        cout << " Enter age: ";
        cin >> age;
    }

    void showData()
    {
        cout << "\n Name: " << name;
        cout << "\n Age: " << age;
    }
};

int main() {
    person pers;
    ifstream infile("GROUP.DAT", ios::in | ios::binary);

    if (!infile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    infile.seekg(0, ios::end);
    int endposition = infile.tellg();
    int totalPersons = endposition / sizeof(person);

    cout << "\nThere are " << totalPersons << " persons in the file.";
    cout << "\nEnter person number (1 to " << totalPersons << "): ";
    int n;
    cin >> n;

    if (n < 1 || n > totalPersons)
    {
        cerr << "Invalid person number!" << endl;
        return 1;
    }

    int position = (n - 1) * sizeof(person);
    infile.seekg(position);
    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));

    pers.showData();
    cout << endl;

    return 0;
}
