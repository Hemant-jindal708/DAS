#include <iostream>
using namespace std;
template <typename Datatype>
class Node
{
public:
    Datatype data;
    Node *next;
    Node *prev;

    Node(Datatype val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename Datatype>
class List
{
private:
    Node<Datatype> *head;

public:
    List()
    {
        head = nullptr;
    }

    void insert(Datatype val)
    {
        Node<Datatype> *newNode = new Node<Datatype>(val);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<Datatype> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteNode(Datatype val)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == val)
        {
            Node<Datatype> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<Datatype> *temp = head;

        while (temp != nullptr && temp->data != val)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node<Datatype> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    List<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Linked list: ";
    list.display();

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    list.deleteNode(30);
    cout << "After deleting 30: ";
    list.display();

    List<string> list1;
    list1.insert("this");
    list1.insert("is");
    list1.insert("a");
    list1.insert("list");
    list1.display();
}
