#include<iostream>
using namespace std;

class distance1
{
    private:
        double inches;
        double feet;
    public:
        distance1()
        {
            inches = 0.0;
            feet = 0.0;
        }
        distance1(int i , float f)
        {
            inches = i;
            feet = f;
        }

        void display()
        {
            cout << "Total : " << feet << " feet, " << inches << " inches " << endl;
        }

        distance1 add_dist(distance1 d2)
        {
            distance1 temp;
            temp.inches = inches + d2.inches;
            if (temp.inches>=12.0)
            {
                temp.inches-=12.0;
                temp.feet = 1;
            }
            temp.feet = temp.feet+feet+d2.feet;
            return temp;
        }
};

int main()
{
    int i1, i2;
    double f1, f2;

    cout << "Enter first distance(inches feet) :";
    cin >> i1 >> f1;
    cout << "Enter second distance(inches feet) :";
    cin >> i2 >> f2;

    distance1 d1(i1, f1);
    distance1 d2(i2, f2);

    d1 = d1.add_dist(d2);
    d1.display();

    return 0;
}