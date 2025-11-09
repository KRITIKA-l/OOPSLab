#include<iostream>
using namespace std;


// Implement class template with static data member.

template<class t>
class counter
{
    public:
        static int count;
        counter()
        {
            count ++;
        }
        static void showcount()
        {
            cout << "Count for this type: " << count << endl;
        }
};

template<class t>
int counter<t> :: count = 0;

int main()
{
    counter<int>c1,c2;
    counter<double>d1;

    counter<int>::showcount();
    counter<double>::showcount();

    counter<int>c3;

    counter<int>::showcount();
    return 0;
    
}

