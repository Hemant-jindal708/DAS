#include <iostream>
using namespace std;
class Queue
{
    int max;
    int *arr;
    int front = -1;
    int rear = -1;

public:
    Queue(int length)
    {
        max = length;
        arr = new int(max);
    }
    void enqueue(int data)
    {
        if (rear == max - 1)
        {
            cout << "Overflow Condition" << endl;
            return;
        }
        if (front < 0)
            front++;

        rear++;
        arr[rear] = data;
    }
    int dequeue()
    {
        if (IsEmpty())
        {
            cout << "Underflow Condition" << endl;
            return -1;
        }
        int x = arr[front];
        front++;
        return x;
    }
    bool IsFull()
    {
        return rear == max - 1;
    }
    bool IsEmpty()
    {
        return front == -1;
    }
    int size()
    {
        return rear - front + 1;
    }
    int length()
    {
        return max;
    }
    int peek()
    {
        if (front == rear && front > 0)
        {
            cout << "Underflow Condition" << endl;
            return -1;
        }
        int x = arr[front];
        return x;
    }
};
int main()
{
    Queue q1(5);
    q1.enqueue(0);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    for (int i = 0; i < q1.length(); i++)
    {
        cout << q1.dequeue() << endl;
    }
}