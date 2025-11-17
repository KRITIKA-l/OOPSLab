#include<iostream>
using namespace std;

double Power(double n,int p=2)
{
    double result=1;
    for (int i=1;i<=p;i++)
    {
        result*=n;
    }
    return result;
}

int main()
{
    double number , result;
    int power,choice;

    cout << "Enter Base :";
    cin >> number;
    cout << "Do you want to enter power? (1 = yes, 0 = no): ";
    cin >> choice;

    if (choice==1)
    {
        cout << "Enter power :";
        cin >> power;
        result = Power(number,power);
        cout << "Number " << number << " To the power " << power << " is " << result ;
    }
    else 
    {
        result = Power(number);
        cout << "Number " << number << " To the power 2 is " << result ;
    }

    return 0;
}