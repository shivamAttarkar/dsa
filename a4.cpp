#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
public:
    Node *head;
    BST()
    {
        this->head = nullptr;
    }

    void insertNode(Node *newNode, Node *&node)
    {
        if (node == nullptr)
        {
            node = newNode;
        }
        else if (newNode->data > node->data)
        {
            insertNode(newNode, node->right);
        }
        else
        {
            insertNode(newNode, node->left);
        }
    }

    int search(Node *node, int data)
    {
        if (node != nullptr)
        {
            if (node->data == data)
            {
                return 1;
            }
            else if (data > node->data)
            {
                search(node->right, data);
            }
            else
            {
                search(node->left, data);
            }
        }
        return -1;
    }
    int getMin()
    {
        Node *node = head;
        if (node != nullptr)
        {
            while (node->left != nullptr)
            {
                node = node->left;
            }
            return node->data;
        }
        return -1;
    }

    void insertElement()
    {
        int data = 0;
        cout << "Enter Element you want to Enter: ";
        cin >> data;
        Node *newNode = new Node(data);
        insertNode(newNode, head);
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int hr = height(node->right);
        int hl = height(node->left);
        if (hr > hl)
        {
            return hr + 1;
        }
        return hl + 1;
    }

    void mirror(Node *&node)
    {
        if (node != nullptr)
        {
            mirror(node->left);
            mirror(node->right);
            Node *temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }

    void preOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node)
    {
        if (node != nullptr)
        {
            preOrder(node->left);
            cout << node->data << endl;
            preOrder(node->right);
        }
    }
};

int main()
{
    BST t;
    for (int i = 0; i < 5; i++)
    {
        t.insertElement();
    }
    t.preOrder(t.head);
    cout << endl;
    cout << endl;
    t.mirror(t.head);
    cout << t.getMin() << endl;
    cout << endl;
    cout << t.height(t.head) << endl;
    cout << t.search(t.head, 5) << endl;
    cout << t.search(t.head, 8) << endl;
    return 0;
}