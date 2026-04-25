#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    Node(int val, Node *nextNode) {
        data = val;
        next = nextNode;
    }
};

class Queue {
public:
    Node *front;
    Node *rear;

    Queue() {
        front = rear = NULL;
    }

    void enqueue() {
        int val;

        cout << "Enter data value: ";
        cin >> val;

        Node *newNode = new Node(val);

        if(rear == NULL)
           front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        } 
    }

    void dequeue() {
        if(front == NULL)
        {
            cout << "Queue is empty...\n";
            return;
        }

        Node *temp = front;

        front = front->next;
        temp->next = NULL;

        delete temp;
    }

    void peek() {
        if(front == NULL)
        {
            cout << "Queue is empty...\n";
            return;
        }
        
        cout << "Front Element: " << front->data << endl;
    }

    void size() {
        if(front == NULL)
        {
            cout << "Size: 0\n";
            return; 
        }

        Node *temp = front;
        int count = 0;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        cout << "Size: " << count << endl;
        
    }

    void display() {
        Node *temp = front;

        if(temp == NULL)
        {
            cout << "Queue is empty...\n";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << "\n";
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Peek\n";
        cout << "4.Size\n";
        cout << "5.Display\n";
        cout << "6.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            q.enqueue();
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.size();
            break;

        case 5:
            q.display();
            break;
        
        case 6:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Try Again...\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
