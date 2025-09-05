#include<iostream>
using namespace std;

class number
{
    private:
        int value;

    public:
        number(int v)
        {
            value = v;
        }

        friend void findmax(number n1, number n2);
};

void findmax(number n1, number n2)
{
    if (n1.value > n2.value)
    {
        cout << "Greater Value : " << n1.value << endl;
    }
    else if (n2.value > n1.value)
    {
        cout << "Greater Value : " << n2.value << endl;
    }
    else
    {
        cout << "Both Values are Equal : " << n1.value << endl;
    }
}

int main()
{
    int n1, n2;
    cout << "Enter First Number : ";
    cin >> n1;
    cout << "Enter Second Number : ";
    cin >> n2;

    number num1(n1);
    number num2(n2);

    findmax(num1, num2);

    return 0;
}