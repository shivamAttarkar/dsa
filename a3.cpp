#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    int flag;
    Node *down;
    Node *right;

    Node(string data)
    {
        this->data = data;
        flag = 0;
        down = nullptr;
        right = nullptr;
    }

    void insertChild(string data)
    {
        Node *newNode = new Node(data);
        Node *temp = this;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        temp->right = newNode;
    }

    void insertSibling(string data)
    {
        Node *newNode = new Node(data);
        Node *temp = this;
        while (temp->down != nullptr)
        {
            temp = temp->down;
        }
        temp->down = newNode;
    }

    Node *searchSiblings(string data)
    {
        Node *temp = this;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                break;
            }
            temp = temp->down;
        }
        return temp;
    }

    Node *searchChildren(string data)
    {
        Node *temp = this->right;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                break;
            }
            temp = temp->right;
        }
        return temp;
    }
};

class GLL
{
    Node *head, *temp;
    string bookName, chapterName, sectionName;

public:
    GLL()
    {
        head = nullptr;
    }
    void insertBook()
    {
        cout << "Enter Book Name: ";
        getline(cin, bookName);
        if (head == nullptr)
        {
            head = new Node(bookName);
        }
        else
        {
            head->insertSibling(bookName);
        }
    }
    int insertChapter()
    {
        if (head == nullptr)
        {
            cout << "No book is present" << endl;
            return 0;
        }
        cout << "Enter Book Name: ";
        getline(cin, bookName);
        Node *book = head->searchSiblings(bookName);
        if (book == nullptr || book->data != bookName)
        {
            cout << "Book Not Found" << endl;
            return 0;
        }
        cout << "Enter Chapter Name: ";
        getline(cin, chapterName);
        book->insertChild(chapterName);
        return 0;
    }
};

int main()
{
    GLL *g = new GLL();
    g->insertBook();
    g->insertChapter();
    return 0;
}