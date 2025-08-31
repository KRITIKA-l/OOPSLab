#include<iostream>
using namespace std;

double calculate(double a,double b,char op)
{
    switch (op)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;

        default:
            cout << "Invalid Operator !\n";
            return 0;
    }
}
int main()
{
    double a,b,result;
    char op;

    cout << "Enter first number : ";
    cin >> a;
    cout << "Enter operator (+,-,*,/) : ";
    cin >> op;
    cout << "Enter second number : ";
    cin >> b;

    result = calculate(a,b,op);

    cout << "Result : " << result;

    return 0;
}