#include<iostream>
using namespace std;
struct phone
{
    int areacode;
    int exchange;
    int number;
};
int main()
{
    phone p1,p2;
    p1.areacode=415;
    p1.exchange=555;
    p1.number=1212;
    cout << "Enter your areacode,exchange and number : ";
    cin >> p2.areacode >> p2.exchange >> p2.number;
    cout << "My number is ("<< p1.areacode<< ") "<< p1.exchange<< "-"<< p1.number<< "\n";
    cout << "Your number is ("<< p2.areacode<< ") "<< p2.exchange<< "-"<< p2.number<< "\n";
    return 0;
}