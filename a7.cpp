/*
You have a business with several offices; you want to lease phone
lines to connect them up with each other; and the phone company
charges different amounts of money to connect different pairs of
cities. You want a set of lines that connects all your offices with a
minimum total cost. Solve the problem by suggesting appropriate
data structures.
*/

#include <iostream>
using namespace std;

class Graph
{
    int a[20][20];
    int n, connections;

public:
    void getData()
    {
        cout << "Enter No of Offices: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = 999;
            }
        }

        cout << "Enter No of Connections: ";
        cin >> connections;
        int b1, b2, cost;
        for (int i = 0; i < connections; i++)
        {
            cout << "Enter Staring vertex of Connection: ";
            cin >> b1;
            cout << "Enter Ending vertex of Connection: ";
            cin >> b2;
            cout << "Enter Connection Cost: ";
            cin >> cost;
            a[b1 - 1][b2 - 1] = a[b2 - 1][b1 - 1] = cost;
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void primsMST()
    {
        int weight[20], visited[20], MST[20];
        for (int i = 0; i < n; i++)
        {
            weight[i] = 999;
            visited[i] = false;
        }
        MST[0] = -1;
        weight[0] = 0;
        for (int count = 0; count < n - 1; count++)
        {
            int minWeight = 999, minIndex;
            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && weight[v] < minWeight)
                {
                    minWeight = weight[v];
                    minIndex = v;
                }
            }
            visited[minIndex] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && a[minIndex][v] < 999 && a[minIndex][v] < weight[v])
                {
                    weight[v] = a[minIndex][v];
                    MST[v] = minIndex;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            cout << MST[i] + 1 << "----" << i + 1 << " : " << a[MST[i]][i] << endl;
        }
    }
};

int main()
{
    Graph g;
    g.getData();
    g.display();
    g.primsMST();
    return 0;
}