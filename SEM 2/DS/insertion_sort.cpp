#include <iostream>

using namespace std;

// Function to sort an array using
// insertion sort
template <typename T>
void insertionSort(T arr[], int n)
{
	int i, j;
	T key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

template <typename T>
void printArray(T arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort<int>(arr, N);
	printArray<int>(arr, N);

	return 0;
}

