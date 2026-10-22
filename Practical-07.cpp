
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x)
{
    Node* newNode = new Node{x, NULL};

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int x)
{
    Node* newNode = new Node{x, NULL};

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void insertAfter(int key, int x)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == key)
        {
            Node* newNode = new Node{x, temp->next};
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node not found\n";
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    delete temp;
}

void deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = head;
    delete del;
}

void deleteAfter(int key)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == key)
        {
            Node* del = temp->next;

            if (del == head && del == temp)
            {
                delete del;
                head = NULL;
                return;
            }

            if (del == head)
                head = head->next;

            temp->next = del->next;
            delete del;
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Node not found\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main()
{
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(30);
    insertAfter(20, 25);

    cout << "Circular Linked List: ";
    display();

    deleteFirst();
    cout << "After deleting first node: ";
    display();

    deleteLast();
    cout << "After deleting last node: ";
    display();

    insertEnd(40);
    insertEnd(50);
    deleteAfter(25);

    cout << "After deleting node after 25: ";
    display();

    return 0;
}
