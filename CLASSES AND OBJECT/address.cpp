#include<iostream>
#include<string>
using namespace std;

class address 
{
    private:
        string street;
        string city;
        int zipcode;
    public:
        address(string street, string city, int zipcode)
        : street(street), city(city), zipcode(zipcode) {};

        void displayaddress() const
        {
            cout << "  Street  : " << street << "\n"
                 << "  City    : " << city << "\n"
                 << "  Zipcode : " << zipcode << "\n";
        } 
};

class person 
{
    private :
        string name;
        int age;
        address address;
    public :
        person(string name, int age, string street, string city, int zipcode)
        : name(name), age(age), address(street, city, zipcode) {};

        void displayperson() const
        {
            cout << "Person Details:\n";
            cout << "Name : " << name << "\n"
                 << "Age  : " << age << "\n";
            cout << "Address:\n";
            address.displayaddress();
        }
};

int main()
{
    string name, street, city;
    int age, zipcode;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;
    cin.ignore();  

    cout << "Enter street: ";
    getline(cin, street);

    cout << "Enter city: ";
    getline(cin, city);

    cout << "Enter zipcode: ";
    cin >> zipcode;

    person person(name, age, street, city, zipcode);
    person.displayperson();
    return 0;
}