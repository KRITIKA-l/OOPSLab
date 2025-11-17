#include<iostream>
using namespace std;

class rectangle
{
    private:
        double length;
        double breadth;
    public:
        rectangle()
        {
            length = 0.0;
            breadth = 0.0;
        }
        void set_dimension(double l , double b)
        {
            length = l;
            breadth = b;
        }
        double area()
        {
            return length*breadth;
        }
        double perimeter()
        {
            return 2*(length + breadth);
        }
};

int main()
{
    rectangle r;
    double length , breadth ;
    cout << "Enter length : ";
    cin >> length;
    cout << "Enter breadth : ";
    cin >> breadth;

    r.set_dimension(length,breadth);
    cout << "Area :"<< r.area() << endl;
    cout << "Perimeter : "<< r.perimeter();

    return 0;
}
