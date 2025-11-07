#include <iostream>
using namespace std;

// Function template to swap two values
template <class T>
void swapping(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;
    float x = 5.01, y = 10.02;

    cout << "Before swap: " << a << ", " << b << endl;
    swapping(a, b);
    cout << "After Swap: " << a << ", " << b << endl;

    cout << "Before swap: " << x << ", " << y << endl;
    swapping(x, y);
    cout << "After Swap: " << x << ", " << y << endl;

    return 0;
}
