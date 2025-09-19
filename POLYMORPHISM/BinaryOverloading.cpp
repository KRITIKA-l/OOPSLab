#include<iostream>
using namespace std;

class time1
{
    int hours;
    int minutes;
    int seconds;

    public:
        time1(int h, int m, int s) 
        {
            hours = h;
            minutes = m;
            seconds = s;
        }

        friend time1 operator+(time1 t1, time1 t2);

        void display()  
        {
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }
};

time1 operator+(time1 t1, time1 t2) 
{
    time1 t3(0, 0, 0);
    
    t3.seconds = t1.seconds + t2.seconds;
    t3.minutes = t1.minutes + t2.minutes;
    t3.hours = t1.hours + t2.hours;

    if (t3.seconds >= 60) 
    {
        t3.seconds = t3.seconds - 60;
        t3.minutes = t3.minutes + 1;
    }
    if (t3.minutes > 60)
    {
        t3.hours = t3.hours + 1;
        t3.minutes = t3.minutes - 60;
    }
    
    return t3;
}
int main() 
{
    int h1, m1, s1, h2, m2, s2;

    cout << "Enter first time(hr:min:sec) : ";
    cin >> h1 >> m1 >> s1;
    cout << "Enter second time(hr:min:sec) : ";
    cin >> h2 >> m2 >> s2;

    time1 t1(h1, m1, s1);
    time1 t2(h2, m2, s2);

    time1 t3 = operator+(t1, t2);
    cout << "First Time : "; t1.display();
    cout << "Second Time : "; t2.display();
    cout << "Sum : "; t3.display();

    return 0;
}