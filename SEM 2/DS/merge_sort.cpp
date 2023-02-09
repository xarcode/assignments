#include <iostream>
using namespace std;

template <typename T>
void merge(T array[], int const left, int const mid, int const right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
 
	T *L = new T[n1],
		*R = new T[n2];

	for (int i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

template <typename T>
void mergeSort(T array[], int const begin, int const end)
{
	if (begin >= end)
		return; 

	int mid = begin + (end - begin) / 2;
	mergeSort<T>(array, begin, mid);
	mergeSort<T>(array, mid + 1, end);
	merge<T>(array, begin, mid, end);
}

template <typename T>
void printArray(T A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort<int>(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray<int>(arr, arr_size);
	return 0;
}
