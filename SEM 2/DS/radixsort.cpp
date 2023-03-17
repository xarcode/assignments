#include <bits/stdc++.h>
using namespace std;
void count_Sort(int arr[], int n, int exp)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]); // find max element in the array
    }

    int count[10] = {0};
    for (int i = 0; i < n; i++) // store the frequency of the each elements of arr
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of the digit in output[]
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / exp) % 10]] = arr[i]; // place the value of arr at [--count[arr[i]]]
    }
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxVal = max(arr[i], maxVal);
    }
    // Do counting sort for every digit
    for (int i = 1; maxVal / i > 0; i *= 10)
    {
        count_Sort(arr, n, i);
    }
}
int main()
{
    int arr[] = {221, 765, 545, 3, 20, 3, 821, 45, 67, 690, 54};
    radixSort(arr, 11);

    for (int x : arr)
    {
        cout << x << " ";
    }
}