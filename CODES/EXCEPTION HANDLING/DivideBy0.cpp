#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter Second Number: ";
    cin >> b;
    try
    {
        if (b == 0)
        {
            throw "Divide by Zero";
        }
        else
        {
            cout << "Result : " << a/b;
        }
    }
    catch (const char *msg)
    {
        cout << msg;
    }
}