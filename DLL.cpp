#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node *head;
    Node *tail;

    DoublyList() {
        head = tail = NULL;
    }

    void insertAtBeginning() {
        int data;
        
        cout << "Enter data value: ";
        cin >> data;

        Node *newNode = new Node(data);

        if(head == NULL && tail == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteAtEnd() {
        if(tail == NULL)
        {
            cout << "List is empty...\n";
            return;
        }

        else if(tail->prev == NULL)
        {
            delete tail;
            head = tail = NULL;
        }

        else
        {
            Node *temp = tail;

            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;

            delete temp;

        }
    }

    void display() {
        if(head == NULL) {
            cout << "List is empty...\n";
            return;
        }

        Node *temp = head;

        cout << "NULL <-> ";

        while (temp != NULL)
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

    dl.insertAtBeginning();
    dl.insertAtBeginning();
    dl.insertAtBeginning();

    dl.deleteAtEnd();

    dl.display();

    return 0;
}