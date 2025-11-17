#include<iostream>
using namespace std;

// Implement class template with multiple type parameter
template<typename t1, typename t2, typename t3>
class geek
{
    public:
        t1 x;
        t2 y;
        t3 z;

        geek(t1 val1, t2 val2, t3 val3)
        {
            x = val1;
            y = val2;
            z = val3;
        }
        void getvalues()
        {
            cout << x << ", " << y << ", " << z << endl;
        }
};

int main()
{
    geek<int, double, string>g1(10,3.14,"hello");
    geek<char, float, bool>g2('a',3.67,true);
    g1.getvalues();
    g2.getvalues();
    return 0;
}

