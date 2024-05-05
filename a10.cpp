#include <iostream>
using namespace std;

void minHeapify(int *a, int i, int n)
{
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < n && a[left] < a[smallest])
    {
        smallest = left;
    }
    if (right < n && a[right] < a[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        minHeapify(a, smallest, n);
    }
}

void buildMinHeap(int *a, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        minHeapify(a, i, n);
    }
}

void maxHeapify(int *a, int i, int n)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (n > left && a[left] > a[i])
    {
        largest = left;
    }
    if (n > right && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxHeapify(a, largest, n);
    }
}

void buildMaxHeap(int *a, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(a, i, n);
    }
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int n = 5;
    int a[] = {20, 30, 40, 10, 60};
    buildMinHeap(a, n);
    display(a, n);
    cout << endl;
    buildMaxHeap(a, n);
    display(a, n);
}
