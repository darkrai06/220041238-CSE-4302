#include "header.h"

Student::Student() : gpa(0.00) {}

void Student::setName(string str)
{
    name = str;
}

void Student::setDept(string str)
{
    dept = str;
}

void Student::setProgram(string str)
{
    program = str;
}

void Student::setSection(string str)
{
    section = str;
}

void Student::setYear(int str)
{
    year = str;
}

void Student::setAddress(string str)
{
    address = str;
}

void Student::setGpa(double str)
{
    gpa = str;
}

void Student::setID(int str)
{
    id = str;
}

string Student::getName()
{
    return name;
}

string Student::getDept()
{
    return dept;
}

string Student::getProgram()
{
    return program;
}

string Student::getSection()
{
    return section;
}

int Student::getYear()
{
    return year;
}

string Student::getAddress()
{
    return address;
}

double Student::getGpa()
{
    return gpa;
}

int Student::getID()
{
    return id;
}

double Student::calculateGpa()
{
    cout << "Number of Courses: ";
    int n;
    cin >> n;
    double totalMarks = 0;

    for (int i = 0; i < n; ++i)
    {
        double quizzes[4], midterm, finalExam, attendance, quizTotal = 0;

        cout << "Enter 4 quiz marks: ";
        for (int j = 0; j < 4; ++j)
        {
            cin >> quizzes[j];
        }

        sort(quizzes, quizzes + 4);
        quizTotal = quizzes[1] + quizzes[2] + quizzes[3];

        cout << "Enter midterm, final and attendance marks: ";
        cin >> midterm >> finalExam >> attendance;

        double courseMarks = quizTotal + midterm + finalExam + attendance;
        totalMarks += courseMarks;
    }

    double avg = totalMarks / n;

    if (avg >= 80)
        return 4.00;
    else if (avg >= 70)
        return 3.50;
    else if (avg >= 60)
        return 3.00;
    else if (avg >= 50)
        return 2.50;
    else if (avg >= 40)
        return 2.00;
    else
        return 0.00;
}

void EditInformationByKeyboard(Student &s)
{
    string str;
    int year;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, str);
    s.setName(str);

    cout << "Enter Department: ";
    getline(cin, str);
    s.setDept(str);

    cout << "Enter Program: ";
    getline(cin, str);
    s.setProgram(str);

    cout << "Enter Section: ";
    getline(cin, str);
    s.setSection(str);

    cout << "Enter Admission Year: ";
    cin >> year;
    s.setYear(year);

    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, str);
    s.setAddress(str);
}

void generateInformationRandom(Student &s)
{
    string name = generateRandomString(6) + " " + generateRandomString(6);
    s.setName(name);

    int year = randomInRangeInt(2020, 2023);
    s.setYear(year);

    string address;
    for (int i = 0; i < 5; ++i)
    {
        if (i > 0)
            address += " ";
        address += generateRandomString(randomInRangeInt(4, 10));
    }
    s.setAddress(address);

    s.setID(generateID());
}

void ShowAllAlphabetically(Student ar[], int n)
{
    sort(ar, ar + n, [](Student &a, Student &b) {
        return a.getID() < b.getID();
    });

    cout << "Displaying All Students Alphabetically by ID:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Name: " << ar[i].getName() << ", ID: " << ar[i].getID() << ", GPA: " << ar[i].getGpa() << endl;
    }
}
