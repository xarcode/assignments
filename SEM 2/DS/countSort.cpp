#include <iostream>

using namespace std;

#define MAX_VAL 11

void countSort(int arr[], int n){
	int i, c[MAX_VAL], o[n];
	
	for(i = 0; i < MAX_VAL; i++)
		c[i] = 0;
		
	for(i = 0; i < n; i++)
		c[arr[i]]++;
		
	for(i = 1; i < MAX_VAL; i++)
		c[i] = c[i] + c[i - 1];
		
	i = n - 1;
	
	while(i >= 0){
		o[c[arr[i]] - 1] = arr[i];
		c[arr[i]]--;
		i--;
	}
	
	for(i = 0; i < n; i++) arr[i] = o[i];
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	countSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
