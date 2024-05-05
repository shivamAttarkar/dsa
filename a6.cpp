#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int cost;
    Node *next;
    Node(string name)
    {
        this->name = name;
        this->cost = 0;
        this->next = nullptr;
    }
    Node(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
        this->next = nullptr;
    }
};

class Graph
{
private:
    int n;
    int matrix[20][20];
    string vertices[20];
    Node *head[20];

public:
    Graph()
    {
        for (int i = 0; i < 20; i++)
        {
            head[i] = nullptr;
        }
        this->n = 0;
    }

    void getGraph()
    {
        cout << "Enter no. of vertices: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter name of the vertex: ";
            cin >> vertices[i];
            head[i] = new Node(vertices[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string choice;
                cout << "Is there a edge between vertices " << vertices[i] << " and " << vertices[j] << "(y/n): ";
                cin >> choice;
                if (choice == "y")
                {
                    int cost = 0;
                    cout << "Enter Cost: ";
                    cin >> cost;
                    matrix[i][j] = cost;
                    Node *temp = head[i];
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = new Node(vertices[j], cost);
                }
                else if (choice == "n")
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    cout << "Wrong Choice." << endl;
                    j = j - 1;
                }
            }
        }
    }
    void displayMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << "   ";
            }
            cout << endl;
        }
    }
    void displayList()
    {
        Node *temp = nullptr;
        for (int i = 0; i < n; i++)
        {
            cout << head[i]->name;
            temp = head[i]->next;
            while (temp != nullptr)
            {
                cout << "-->" << temp->name << "(" << temp->cost << ")";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.getGraph();
    g.displayMatrix();
    g.displayList();
    return 0;
}