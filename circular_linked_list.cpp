#include <iostream>
using namespace std;
template <typename Data>
class Node
{
public:
    Data data;
    Node *next;
    Node(Data val)
    {
        data = val;
        next = nullptr;
    }
};
template <typename Data>
class List
{
private:
    Node<Data> *head;
    int size = 0;

public:
    List()
    {
        head = nullptr;
    }
    void insert(Data val)
    {
        size++;
        Node<Data> *NewNode = new Node<Data>(val);
        if (head == nullptr)
        {
            head = NewNode;
            NewNode->next = head;
            return;
        }
        Node<Data> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
        NewNode->next = head;
    }
    void print()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        Node<Data> *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "Head" << endl;
    }
    void deleteNode(Data val)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == val)
        {
            Node<Data> *temp1 = head;
            Node<Data> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete temp1;
            return;
        }
        Node<Data> *prev;
        Node<Data> *temp = head;
        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != val);
        if (temp == nullptr)
        {
            cout << "node not found" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
};
int main()
{
    List<int> list;
    list.insert(0);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.print();
    list.deleteNode(0);
    list.print();
    list.deleteNode(3);
    list.print();
}