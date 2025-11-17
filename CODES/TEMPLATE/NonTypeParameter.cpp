#include<iostream>
using namespace std;

// Implement class template with non type parameter.
template<typename t, int n>
class arrays
{
    t arr[n];
    public:
        void fill(t value)
        {
            for(int i = 0; i<n; i++)
            {
                arr[i] = value;
            }
        }
        void display()
        {
            for(int i = 0; i<n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
};

int main()
{
    arrays<int,5>intarray;
    arrays<double, 3>dbarray;
    intarray.fill(10);
    dbarray.fill(3.14);
    intarray.display();
    dbarray.display();

    return 0;

}

