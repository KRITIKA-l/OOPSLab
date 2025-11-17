#include<iostream>
using namespace std;

class employee
{
    private:
        string name;
        int id;
        float salary;

    public:
        void input()
        {
            cout << "Enter Employee ID :";
            cin >> id;
            cout << "Enter Employee Name :";
            cin >> name;
            cout << "Enter Employee Salary :";
            cin >> salary;
        }

        void display()
        {
            
            cout << " " << id << " " << " " << name << " " << " " << salary << " " << endl;
        }
};

int main()
{
    employee emp[5];
    int n;
    cout << "Enter Number Of Details:";
    cin >> n;
    cout << "\nENTER DETAILS FOR " << n << " EMPLOYEES \n";
    for(int i = 0; i < n; i++)
    {
        cout << "\nEMPLOYEE " << i+1 << endl;
        emp[i].input();
    }
    cout << "\n EMPLOYEE DETAILS \n";
    cout << " ID " << " NAME " << " SALARY " << endl;
    for(int i = 0; i < n; i++)
    {
        emp[i].display();
    }

    return 0;
}
