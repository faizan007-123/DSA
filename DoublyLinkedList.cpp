#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyList {
public:
    Node *head;
    Node *tail;

    DoublyList() {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if(head == nullptr)
            head = tail = newNode;
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

    }

    void push_back(int val) 
    {
        Node *newNode = new Node(val);

        if(head == nullptr)
            head = tail = newNode;
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            cout << "List is empty...\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        
        if(head != nullptr)
            head->prev = nullptr;

        temp->next = nullptr;
        delete temp;
    }

    void pop_back()
    {
        if(tail == nullptr)
        {
            cout << "List is empty...\n";
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if(tail != nullptr)
            tail->next = nullptr;

        temp->prev = nullptr;
        delete temp;
    }

    void print() 
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
        
    }
};

int main()
{
    DoublyList dl;

    dl.push_front(0);
    dl.push_back(1);
    dl.push_back(2);
    dl.push_back(3);
    dl.push_back(4);

    dl.pop_front();
    dl.pop_back();

    dl.print();

    return 0;
}
