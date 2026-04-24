#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    Node(int val, Node *nextNode)
    {
        data = val;
        next = nextNode;
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    void push()
    {
        int val;

        cout << "Enter data value: ";
        cin >> val;

        Node *newNode = new Node(val);

        if (top == NULL)
            top = newNode;
        else
        {
            newNode->next = top;
            top = newNode;
        }

        cout << "Element " << val << " added successfully...\n";
    }

    void pop()
    {
        if (top == NULL)
            cout << "Stack is empty...\n";
        else
        {
            Node *temp = top;
            top = top->next;

            temp->next = NULL;
            delete temp;

            cout << "Element deleted successfully...\n";
        }
    }

    void peek()
    {
        cout << "Top Element: " << top->data << endl;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty...\n";
            return;
        }

        Node *temp = top;

        while (temp != NULL)
        {
            cout << temp->data << " | ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    Stack s;
    int choice;

    do
    {
        cout << "1.Push\n";
        cout << "2.Pop\n";
        cout << "3.Peek\n";
        cout << "4.Display\n";
        cout << "5.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            s.push();
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Try Again...\n";
            break;
        }

    } while (choice != 5);

    return 0;
}
