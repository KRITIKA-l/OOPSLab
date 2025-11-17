#include<iostream>
using namespace std;

class shape
{
    public :
        virtual void area() = 0;
};          

class circle : public shape
{
    private :
        int radius;
    public :
        circle(int r)
        {
            radius = r;
        }
        void area() override
        {
            cout << "Area of Circle : " << 3.14 * radius * radius << " sq units" << endl;
        }
} ;

class rectangle : public shape
{
    private :
        int length;
        int breadth;

    public :
        rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

    void area() override
    {
        cout << "Area of Rectangle : " << length * breadth << " sq units" << endl;
    }

};

int main ()
{
    shape *s1, *s2;
    int radius, length, breadth;
    cout << "Enter Radius : ";
    cin >> radius;

    s1 = new circle(radius);
    s1 -> area();

    cout << "\nEnter Length : ";
    cin >> length;
    cout << "Enter Breadth : ";
    cin >> breadth;

    s2 = new rectangle(length, breadth);
    s2 -> area();

    delete s1;
    delete s2;

    return 0;
}