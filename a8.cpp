#include <iostream>
using namespace std;

class OBST
{
public:
    float c[20][20], w[20][20], p[20], q[20];
    int r[20][20], n, v[20];

    OBST()
    {
        cout << "Enter No of vertices: ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter Element: ";
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter Successful Probability: ";
            cin >> p[i];
        }
        for (int i = 0; i <= n; i++)
        {
            cout << "Enter Unsuccessful Probability: ";
            cin >> q[i];
        }
        findOBST();
    }
    int findMin(int i, int j)
    {
        int min = 999, z = j;
        for (int k = i + 1; k <= j; k++)
        {
            if (min > c[i][k - 1] + c[k][j])
            {
                min = c[i][k - 1] + c[k][j];
                z = k;
            }
        }
        return z;
    }
    void findOBST()
    {
        for (int i = 0; i < n; i++) /* Initialize the weight and cost matrices , when j-i =0 and j-i=1 */
        {
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = w[i][i + 1];
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;

        for (int m = 2; m <= n; m++)
        {
            for (int i = 0; i <= n - m; i++)
            {
                int j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                int k = findMin(i, j); /* find minimum value in the range r[i-1][j] to r[i][j-1] */
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
        findTree("root", 0, n);
    }
    void findTree(string s, int i, int j)
    {
        if (r[i][j] == 0)
        {
            return;
        }
        cout << s + " Node: " << v[r[i][j]] << endl;
        findTree("left", i, r[i][j] - 1);
        findTree("right", r[i][j], j);
    }
};

int main()
{
    OBST t;
    return 0;
}