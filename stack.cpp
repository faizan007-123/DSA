#include <iostream>
#include <vector>
using namespace std;

void PushElement(vector<int> &);
void PopElement(vector<int> &);
void PeekElement(vector<int> &);
void DisplayElements(vector<int> &);

int top = -1;

int main()
{
    vector<int> vec;
    int ch;

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
            PushElement(vec);
            break;

        case 2:
            PopElement(vec);
            break;

        case 3:
            PeekElement(vec);
            break;

        case 4:
            DisplayElements(vec);
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

void PushElement(vector<int> &v)
{
    int n;
    
    cout << "Enter a value: ";
    cin >> n;
    
    v.push_back(n);

    cout << "Element inserted successfully...\n";
    top++;

}

void PopElement(vector<int> &v)
{
    if (top == -1)
    {
        cout << "Stack is empty...\n";
        return;
    }
    else
    {
        v.pop_back();
        top--;
        cout << "Element deleted successfully...\n";
    }
}

void PeekElement(vector<int> &v)
{
    if (top == -1) 
    {
        cout << "Stack is empty...\n";
        return;
    }
        cout << "Top Element: " << v[top] << endl;
}

void DisplayElements(vector<int> &v)
{
    if (top == -1) 
    {
        cout << "Stack is empty...\n";
        return;
    }

    cout << "Stack Elements (from top to bottom): \n[ ";
    
    for(int i = top; i != -1; i--)
        cout << v[i] << " ";

    cout << "]\n";    
}
