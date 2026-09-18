
#include <iostream>
using namespace std;

#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
        cout << "Overflow\n";
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        q[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        cout << "Underflow\n";
    else
        cout << "Deleted = " << q[front++] << endl;
}

void display()
{
    if (front == -1 || front > rear)
        cout << "Queue is empty\n";
    else
    {
        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";

        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}

