#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
class BST
{
private:
    Node *Root;
    Node *insertrecursive(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->data)
        {
            node->left = insertrecursive(node->left, key);
        }
        if (key > node->data)
        {
            node->right = insertrecursive(node->right, key);
        }
        return node;
    }
    void preorder(Node *node)
    {
        cout << node->data << " ";
        if (node->left)
            preorder(node->left);
        if (node->right)
            preorder(node->right);
    }
    void inorder(Node *node)
    {
        if (node->left)
            inorder(node->left);
        cout << node->data << " ";
        if (node->right)
            inorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node->left)
            postorder(node->left);
        if (node->right)
            postorder(node->right);
        cout << node->data << " ";
    }
    bool search(Node *node, int key)
    {
        bool x = false;
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == key)
        {
            return true;
        }
        if (node->data > key)
        {
            x = search(node->left, key);
        }
        if (node->data < key)
        {
            x = search(node->right, key);
        }
        return x;
    }
    Node *Delete(Node *node, int key)
    {
        if (node == nullptr)
            return node;

        if (key > node->data)
        {
            node->right=Delete(node->right, key);
        }
        else if (key < node->data)
            node->left=Delete(node->left, key);
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = node->right;
            while (temp && temp->left != nullptr)
            {
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
        return node;
    }

public:
    BST()
    {
        Root = nullptr;
    }
    void Insert(int key)
    {
        Root = insertrecursive(Root, key);
    }
    void preorder()
    {
        preorder(Root);
    }
    void inorder()
    {
        inorder(Root);
    }
    void postorder()
    {
        postorder(Root);
    }
    bool search(int key)
    {
        return search(Root, key);
    }
    void Delete(int key)
    {
        Root = Delete(Root, key);
    }
};
int main()
{
    BST tree;
    tree.Insert(10);
    tree.Insert(11);
    tree.Insert(9);
    tree.Insert(8);
    tree.Insert(12);
    tree.preorder();
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.postorder();
    cout << endl;
    tree.Delete(11);
    tree.inorder();
}