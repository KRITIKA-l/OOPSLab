#include<iostream>
using namespace std;

bool checksum(int num)
{
    if(num%2==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int num;
    cout << "Enter number :";
    cin >> num;
    if (checksum(num)==true)
    {
        cout << "The number is even .";
    }
    else
    {
        cout << "The number is odd .";
    }

    return 0;
}