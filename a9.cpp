#include <iostream>
using namespace std;

class Node
{
public:
    string keyword, meaning;
    int ht;
    Node *left;
    Node *right;
    Node(string keyword, string meaning)
    {
        this->keyword = keyword;
        this->meaning = meaning;
        this->ht = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVL
{
public:
    Node *head;
    AVL()
    {
        head = nullptr;
    }
    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int hl = height(node->left);
        int hr = height(node->right);
        if (hl > hr)
        {
            return hl + 1;
        }
        return hr + 1;
    }
    int BF(Node *node)
    {
        return height(node->left) - height(node->right);
    }

    void Swap(Node *&a, Node *&b)
    {
        Node *temp = a;
        a = b;
        b = temp;
    }

    void rotateLeft(Node *&x)
    {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        swap(x, y);
    }

    void rotateRight(Node *&x)
    {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        swap(x, y);
    }

    void insertNode(Node *newNode, Node *&node)
    {
        if (node == nullptr)
        {
            node = newNode;
            return;
        }
        else if (newNode->keyword > node->keyword)
        {
            insertNode(newNode, node->right);
        }
        else
        {
            insertNode(newNode, node->left);
        }
        int bf = BF(node);
        if (bf == 2)
        {
            if (newNode->keyword > node->left->keyword)
            {
                rotateRight(node->left);
            }
            rotateLeft(node);
        }
        else if (bf == -2)
        {
            if (newNode->keyword < node->right->keyword)
            {
                rotateLeft(node->right);
            }
            rotateRight(node);
        }
    }

    void deleteNode(Node *&node, string keyword)
    {
        if (node == nullptr)
        {
            return;
        }
        if (keyword > node->keyword)
        {
            deleteNode(node->right, keyword);
        }
        else if (keyword < node->keyword)
        {
            int bf = BF(node);
            deleteNode(node->left, keyword);
        }
        else if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            node = temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            node = temp;
        }
        else
        {
            Node *temp = node->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            node->keyword = temp->keyword;
            node->meaning = temp->meaning;
            deleteNode(node->right, node->keyword);
        }

        if (node != nullptr && (node->right != nullptr || node->left != nullptr))
        {
            int bf = BF(node);
            if (bf == 2)
            {
                if (keyword > node->left->keyword)
                {
                    rotateRight(node->left);
                }
                rotateLeft(node);
            }
            else if (bf == -2)
            {
                if (keyword < node->right->keyword)
                {
                    rotateLeft(node->right);
                }
                rotateRight(node);
            }
        }
    }

    void insert()
    {
        string keyword, meaning = "";
        cout << "Enter keyword: ";
        cin >> keyword;
        insertNode(new Node(keyword, meaning), head);
        cout << "Node: " << keyword << endl;
    }
};

int main()
{
    AVL t;
    for (int i = 0; i < 5; i++)
    {
        t.insert();
    }
    t.deleteNode(t.head, "b");
    cout << t.head->keyword << endl;
}