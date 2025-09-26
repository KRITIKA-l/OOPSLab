#include<iostream>
using namespace std;

class A
{
    public:
        A ()
        {
            cout << "Class A Constructure Call .\n";
        }
        ~A ()
        {
            cout << "Class A Destructor call .\n";
        }
        
};

class B
{
    public:
        B ()
        {
            cout << "Class B Constructure Call .\n";
        }
        ~B ()
        {
            cout << "Class B Destructor call .\n";
        }
        
};

class C : public A, public B
{
    public:
        C ()
        {
            cout << "Class C Constructure Call .\n";
        }
        ~C ()
        {
            cout << "Class C Destructor call .\n";
        }
        
};

int main()
{
    C c;

    return 0;
}
