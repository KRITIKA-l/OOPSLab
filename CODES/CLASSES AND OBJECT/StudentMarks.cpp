#include<iostream>
using namespace std;

class student
{
    int rollno;
    float marks;
    public:
        void getdata()
        {
            cout << "Enter roll no :";
            cin >> rollno;
            cout << "Enter marks :";
            cin >> marks;
        }
        void display()
        {
            cout << "Roll no. : " << rollno << endl;
            cout << "Marks : " << marks << endl;
        }
};

int main()
{
    student s;
    s.getdata();
    s.display();
    return 0;
}