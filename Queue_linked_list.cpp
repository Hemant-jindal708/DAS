#include <iostream>
using namespace std;
template <typename type>
class Node
{
public:
    type data;
    Node *next;
    Node(type val)
    {
        data = val;
        next = nullptr;
    }
};
template <typename type>
class Queue
{
private:
    Node<type> *Front;
    Node<type> *Rear;
    int size = 0;

public:
    Queue()
    {
        Front = nullptr;
        Rear = nullptr;
    }
    void enqueue(type val)
    {
        Node<type> *newNode = new Node<type>(val);
        if (Rear == nullptr)
        {
            Front = Rear = newNode;
            return;
        }
        Rear->next = newNode;
        Rear = newNode;
    }
    type dequeue()
    {
        if (Front == nullptr)
        {
            cout << "Underflow Condition";
            return -1;
        }
        Node<type> *temp = Front;
        Front = Front->next;
        type var = temp->data;
        if(Front==nullptr)
        {
            Rear==nullptr;
        }
        delete temp;
        return var;
    }
    int peek()
    {
        if (Front==nullptr)
        {
            cout << "Queue is Empty"<<endl;
            return -1;
        }
        return Front->data;
    }
};
int main()
{
    Queue<int> Q;
    Q.enqueue(0);
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.peek();
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    Q.peek();
}