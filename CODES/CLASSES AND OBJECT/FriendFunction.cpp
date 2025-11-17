#include<iostream>
using namespace std;

class box
{
    private:
        int length;

    public:
        box(int l) : length(l)
        {}
        friend void printlength(box b);
};

void printlength(box b)
{
    cout << "Length of the Box : " << b.length << " cm" << endl;
}

int main()
{
    int len;

    cout << "Enter Length of the Box (in cm): ";
    cin >> len;

    box b(len);
    printlength(b);

    return 0;
}