
#include <iostream>
using namespace std;

#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % MAX == front)
        cout << "Overflow\n";
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        q[rear] = x;
        cout << x << " inserted\n";
    }
}

void dequeue()
{
    if (front == -1)
        cout << "Underflow\n";
    else
    {
        cout << "Deleted = " << q[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
        cout << "Queue is empty\n";
    else
    {
        cout << "Queue elements: ";
        int i = front;

        while (true)
        {
            cout << q[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}
