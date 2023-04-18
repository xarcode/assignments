#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n and arr[l] > arr[largest])
        largest = l;
    if (r < n and arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapsort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {10, 21, 33, 11, 42, 22, 19, 76};
    heapsort(arr, 8);
    for (size_t i = 0; i < 8; i++)
        cout << arr[i] << " ";

    return 0;
}