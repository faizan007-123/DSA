#include <iostream>
#include <vector>
using namespace std;

void enqueue(vector<int> &);
void dequeue(vector<int> &);
void peek(vector<int> &);
void isEmpty(void);
void display(vector<int> &);
void size(vector<int> &);

int front = -1;
int rear = -1;

int main()
{
    vector<int> vec;
    int choice;

    do
    {
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Peek\n";
        cout << "4.IsEmpty\n";
        cout << "5.Display\n";
        cout << "6.Size\n";
        cout << "7.Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice; 

        switch(choice) 
        {
        case 1:
            enqueue(vec);
            break;

        case 2:
            dequeue(vec);
            break;

        case 3:
            peek(vec);
            break;

        case 4:
            isEmpty();
            break;

        case 5:
            display(vec);
            break;

        case 6:
            size(vec);
            break;

        case 7:
            cout << "Exiting the program...\n";
            break;
        
        default:
            cout << "Try Again...\n";
        }

    } while (choice != 7);
        
    return 0;
}

void enqueue(vector<int> &v) 
{
    int n;

    cout << "Enter a value: ";
    cin >> n;

    v.push_back(n);
    
    if((front == -1) && (rear == -1))
    {   
        front++;
        rear++;
    }
    else
        rear++;

}

void dequeue(vector<int> &v)
{
    if(front == -1)
    {
        cout << "Queue is empty...\n";
        return;
    }

    v.erase(v.begin() + front);
    rear--;

    if(v.empty())
    {
        front = -1;
        rear = -1;
    }
}

void peek(vector<int> &v)
{
    if(front == -1)
    {
        cout << "Queue is empty...\n";
        return;
    }
    
    cout << "Front element of Queue: " << v[front] << endl;
}

void isEmpty(void)
{
    if((front == -1) && (rear == -1))
        cout << "Queue is empty...\n";
    else
        cout << "Queue is not empty...\n";
}

void display(vector<int> &v)
{
    if(front == -1)
    {
        cout << "Queue is empty...\n";
        return;
    }

    for(int i = front; i <= rear; i++)
        cout << v[i] << " ";

    cout << endl;
}

void size(vector<int> &v)
{
    cout << "Size: " << v.size() << endl;
}
