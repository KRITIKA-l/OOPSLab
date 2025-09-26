#include<iostream>
using namespace std;

class Person
{
    public:
        Person()
        {
            cout << "Person::Person() called .\n";
        }
        Person (int x)
        {
            cout << "Person::Person(int ) called .\n";
        }
        
};

class Faculty : virtual public Person
{
    public:
        Faculty(int x):Person(x)
        {
            cout << "Faculty::Faculty(int ) called .\n";
        }
};

class Student : virtual public Person
{
    public:
        Student(int x):Person(x)
        {
            cout << "Student::Student(int ) called .\n";
        }
};

class TA : public Faculty, public Student
{
    public:
        TA(int x) : Faculty(x), Student(x)
        {
            cout << "TA::TA(int ) called .\n";
        }
};

int main()
{
    TA ta(63);

    return 0;
}