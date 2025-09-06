#include<iostream>
using namespace std;
#define size 5

class stack 
{
    int arr[size];
    int top;
    public :
        stack()
        {
            top = 0;
        }
        void push(int n);
        void pop();
        void display();
};

void stack :: push(int n)
{
    if (top == size)
    {
        cout << "Stack Overflow !" << endl;
    }
    else
    {
        arr[top] = n;
        top ++;
        cout << "Pushed " << n << " to stack." << endl;
    }
}
void stack :: pop()
{
    int x;
    if (top == 0)
    {
        cout << "Stack Underflow !" << endl;
    }
    else
    {
        top--;
        x = arr[top];
        cout << "Popped " << x << " from stack." << endl;
    }
}
void stack :: display()
{
    if (top == 0) 
    {
        cout << "Stack is empty." << endl;
    } 
    else 
    {
        cout << "Stack contents (top to bottom): ";
        for (int i = top - 1; i >= 0; i--) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    stack s;
    int choice, value;
    cout << "===== Stack Menu =====" << endl;
    
    while (choice != 4)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } 

    return 0;
}