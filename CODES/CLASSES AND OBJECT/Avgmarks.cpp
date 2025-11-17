#include<iostream>
using namespace std;

class student
{
    private:
        double marks;
    public:
        student()
        {
            marks = 0.0;
        }
        student(int m)
        {
            marks = m;
        }

        void avgmarks()
        {
            cout << "Average Marks :" << marks << endl;
        }

        student average(student s2, student s3)
        {
            student temp;
            temp.marks = (s2.marks + s3.marks)/2;
            return temp;
        }

};

int main()
{
    double m1,m2;
    cout << "Enter marks of first student: ";
    cin >> m1;
    cout << "Enter marks of second student : ";
    cin >> m2;
    student s1(m1);
    student s2(m2);
    student s3;
    s3 = s3.average(s1,s2);

    s3.avgmarks();

    return 0;
}