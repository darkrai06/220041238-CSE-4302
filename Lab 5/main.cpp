#include "header.h"

double randomInRange(double min, double max)
{
    if (min > max)
    {
        swap(min, max);
    }
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;
    return min + randomFraction * (max - min);
}

int randomInRangeInt(int min, int max)
{
    if (min > max)
    {
        swap(min, max);
    }
    return rand() % (max - min + 1) + min;
}

string generateRandomString(int length)
{
    string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1;

    for (int i = 0; i < length; ++i)
    {
        randomString += alphabet[rand() % alphabetSize];
    }
    return randomString;
}

int generateID()
{
    int id = randomInRangeInt(17, 24) * 100000;
    id += randomInRangeInt(1, 6) * 10;
    id += randomInRangeInt(1, 2) * 10;
    id += randomInRangeInt(1, 3) * 100;
    id += randomInRangeInt(1, 70);
    return id;
}

int main()
{
    Student students[100];

    for (int i = 0; i < 2; ++i)
    {
        cout << "Edit information for student " << i + 1 << ":\n";
        EditInformationByKeyboard(students[i]);
    }

    for (int i = 2; i < 100; ++i)
    {
        generateInformationRandom(students[i]);
    }

    ShowAllAlphabetically(students, 100);

    return 0;
}
