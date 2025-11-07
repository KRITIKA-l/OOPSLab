#include<iostream>
using namespace std;

// create a function template to sort a list of elements of a given type using bubble sort (use generic function).

template <class T, int n>
class Array 
{
    T arr[n]; 
public:
    
    void input() 
    {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
    }

    void display() 
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    void sort() 
    {
        bool swapped;
        for (int i = 0; i < n - 1; ++i) 
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) 
            {
                if (arr[j] > arr[j + 1]) 
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) 
                break; 
        }
    }
};


int main() 
{
    Array<int, 5> intArray;
    Array<float, 5> floatArray;
    intArray.input();
    floatArray.input();

    cout << "Before sorting: ";
    cout << endl << "Int Array: ";
    intArray.display();

    cout << endl << "Float Array: ";
    floatArray.display();

    intArray.sort();
    floatArray.sort();

    cout << "After sorting: ";
    intArray.display();
    floatArray.display();

    return 0;
}