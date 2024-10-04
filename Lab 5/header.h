#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string name;
    string dept;
    string program;
    string section;
    int year;
    string address;
    double gpa;
    int id;

public:
    Student();
    void setName(string name);
    string getName();
    void setDept(string dept);
    string getDept();
    void setProgram(string program);
    string getProgram();
    void setSection(string section);
    string getSection();
    void setYear(int year);
    int getYear();
    void setAddress(string address);
    string getAddress();
    void setGpa(double gpa);
    double getGpa();
    void setID(int id);
    int getID();
    double calculateGpa();
};

string generateRandomString(int length);
int randomInRangeInt(int min, int max);
double randomInRange(double min, double max);

void EditInformationByKeyboard(Student &s);
void generateInformationRandom(Student &s);
void ShowAllAlphabetically(Student ar[], int n);

#endif
