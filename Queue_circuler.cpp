#include <iostream>
using namespace std;

class CircularQueue
{
    int max;
    int *arr;
    int front;
    int rear;

public:
    CircularQueue(int length)
    {
        max = length;
        arr = new int(max);
        front = -1;
        rear = -1;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    void enqueue(int data)
    {
        if (IsFull())
        {
            cout << "overflow condition" << endl;
            return;
        }
        if (front < 0)
            front++;
        rear = (rear + 1) % max;
        arr[rear] = data;
    }
    int dequeue()
    {
        if (IsEmpty())
        {
            cout << "underflow condition" << endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front = (front + 1) % max;
        return data;
    }

    bool IsFull()
    {
        return (front == (rear + 1) % max);
    }

    bool IsEmpty()
    {
        return front == -1;
    }

    int size()
    {
        if (IsEmpty())
            return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return max - front + rear + 1;
    }

    int length()
    {
        return max;
    }

    int peek()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout << "Front element: " << q.peek() << endl;
    cout << "Size of queue: " << q.size() << endl;

    cout << "Dequeued elements: " << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(6);
    q.enqueue(7);

    cout << "Size of queue after enqueues: " << q.size() << endl;

    while (!q.IsEmpty())
    {
        cout << q.dequeue() << endl;
    }

    return 0;
}
