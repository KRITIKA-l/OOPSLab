#include<iostream>
using namespace std;

class complex
{
    int real;
    int imaginary;
    public:
        complex(int r, int i)
        {
            real = r;
            imaginary = i;
        }
        void display()
        {
            cout << real << " + " << imaginary << "i " << endl;
        }

        complex operator++(int)
        {
            real ++;
            imaginary ++;
            return *this;
        }
        complex operator--()
        {
            -- real;
            -- imaginary;
            return *this;
        }
};

int main()
{
    int real, imaginary;
    cout << "Enter real part : ";
    cin >> real;
    cout << "Enter imaginary part : ";
    cin >> imaginary;
    complex c1(real, imaginary);

    cout << "Original : ";
    c1.display();
    cout << "After Post Increment : ";
    c1++;
    c1.display();
    cout << "After Pre Decrement : ";
    --c1;
    c1.display();

    return 0;
}