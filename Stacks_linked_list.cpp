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
class Stack
{
    Node<type> *head;
    int size = 0;

public:
    Stack()
    {
        head->next = nullptr;
    }
    void push(int val)
    {
        size++;
        Node<type> *newNode = new Node<type>(val);
        newNode->next = head;
        head = newNode;
    }
    type pop()
    {
        if (head == nullptr)
        {
            cout << "empty Stack" << endl;
            return-1;
        }
        Node<type> *temp = head;
        head = head->next;
        type var = temp->data;
        delete temp;
        size--;
        return var;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void print()
    {
        Node<type> *temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp->next != nullptr);
    }
};
int main()
{
    Stack<int> S;
    S.push(0);
    S.push(1);
    S.push(2);
    S.push(3);
    S.print();
    cout << S.pop() << endl;
    cout << S.pop() << endl;
    cout << S.pop() << endl;
    cout << S.pop() << endl;
}