/*
A Dictionary stores keywords and its meanings. Provide facility for
adding new keywords, deleting keywords, updating values of any
entry. Provide facility to display whole data sorted in ascending/
Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Binary Search Tree for
implementation
*/

#include <iostream>
using namespace std;

class Node
{
public:
    string keyword, meaning;
    Node *left;
    Node *right;
    Node(string keyword, string meaning)
    {
        this->keyword = keyword;
        this->meaning = meaning;
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
        head = nullptr;
    }

    void insertNode(Node *newNode, Node *&node)
    {
        if (node == nullptr)
        {
            node = newNode;
            return;
        }
        if (newNode->keyword > node->keyword)
        {
            insertNode(newNode, node->right);
        }
        else
        {
            insertNode(newNode, node->left);
        }
    }

    void insert()
    {
        string keyword, meaning;
        cout << "Enter Keyword: ";
        getline(cin, keyword);
        cout << "Enter Meaning: ";
        getline(cin, meaning);
        Node *newNode = new Node(keyword, meaning);
        insertNode(newNode, head);
    }

    void inorder(Node *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << "Keyword: " << node->keyword << endl;
            inorder(node->right);
        }
    }

    void des(Node *node)
    {
        if (node != nullptr)
        {
            inorder(node->right);
            cout << "Keyword: " << node->keyword << endl;
            inorder(node->left);
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
            return;
        }
        else if (keyword < node->keyword)
        {
            deleteNode(node->left, keyword);
            return;
        }

        if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            node = node->right;
            return;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            node = temp;
            return;
        }

        Node *temp = node->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        node->keyword = temp->keyword;
        node->meaning = temp->meaning;
        deleteNode(node->right, node->keyword);
    }
};

int main()
{
    BST t;
    t.insert();
    t.insert();
    t.insert();
    t.inorder(t.head);

    t.des(t.head);
    t.deleteNode(t.head, "gamma");
    cout << endl;
    t.inorder(t.head);
}