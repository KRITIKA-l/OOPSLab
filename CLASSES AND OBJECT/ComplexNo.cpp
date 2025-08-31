#include<iostream>
using namespace std;

class complex 
{
    int x;
    int y;
    public:
        complex()
        {
            x = 1;
            y = 1;
        }
        complex(int c, int d)
        {
            x = c;
            y = d;
        }
        void input()
        {
            cout << "Enter real part of number : ";
            cin >> x;
            cout << "Enter imaginary part of number : ";
            cin >> y;
        }

        void sum(complex c)
        {
            int real = x + c.x;
            int imaginary = y + c.y;
            cout << real<< " + " << imaginary << "i" ;
        }
};

int main()
{
    int a, b;
    complex c1;
    c1.input();
    cout << "Enter real part of second number : ";
    cin >> a;
    cout << "Enter imaginary part of second number : ";
    cin >> b;
    complex c2(a, b);
    c1.sum(c2);
    return 0;
}