#include<iostream>
using namespace std;
struct point
{
    int first;
    int second;
};
int main()
{
    point p1,p2;
    cout << "Enter coordinates for P1 : ";
    cin >> p1.first >> p1.second;
    cout << "Enter coordinates for P2 : ";
    cin >> p2.first >> p2.second;
    int sum1= p1.first + p2.first;
    int sum2= p1.second + p2.second;
    cout << "Coordinates of P1 + P2 : " << sum1 << " , " << sum2;
    return 0;
}