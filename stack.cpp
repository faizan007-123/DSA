#include <iostream>
using namespace std;

void PushElement(int *, int);
void PopElement(int *);
void PeekElement(int *);
void DisplayElements(int *, int);

int top = -1;

int main()
{
    int n;
    int ch;

    cout << "Enter size of stack: ";
    cin >> n;

    int *arr = new int[n];

    do
    {
        cout << "1.Push \n";
        cout << "2.Pop \n";
        cout << "3.Peek (Top) \n";
        cout << "4.Display \n";
        cout << "5.Exit \n";
        
        cout << "Please enter your choice: \n";
        cin >> ch;

        switch (ch)
        {

        case 1:

            PushElement(arr, n);
            break;

        case 2:

            PopElement(arr);
            break;

        case 3:

            PeekElement(arr);
            break;

        case 4:

            DisplayElements(arr, n);
            break;

        case 5:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid Input...\n";
            break;
        }

    } while (ch != 5);

    return 0;
}

void PushElement(int *x, int a)
{
    if (top == (a - 1))
    {
        cout << "Stack is full...\n";
        return;
    }
    else
    {
        top++;

        cout << "Enter element to be inserted: ";
        cin >> x[top];

        cout << "Element inserted successfully...\n";
    }
}

void PopElement(int *y)
{
    if (top == -1)
    {
        cout << "Stack is empty...\n";
        return;
    }
    else
    {
        y[top] = 0;

        top--;

        cout << "Element deleted successfully...\n";
    }
}

void PeekElement(int *z)
{
    if (top == -1) 
    {
        cout << "Stack is empty...\n";
        return;
    }
        cout << z[top] << endl;
}

void DisplayElements(int *q, int b)
{
    if (top == -1) 
    {
        cout << "Stack is empty...\n";
        return;
    }
        cout << "Stack Elements (from top to bottom): \n[ ";
        for (int j = top; j > -1; j--)
            cout << q[j] << " ";

        cout << "]\n";
}
