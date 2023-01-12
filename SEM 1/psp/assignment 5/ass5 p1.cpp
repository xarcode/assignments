#include <iostream>

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6}, b[] = {7, 8, 9, 10, 11}, n1 = 6, n2 = 5;
	int c[n1 + n2];
	
	int k = 0;
	for(int i = 0; i < n1; i++) c[k++] = a[i];
	for(int i = 0; i < n2; i++) c[k++] = b[i];
	
	cout << "Merged array is: ";
	for(int i = 0; i < n1 + n2; i++) cout << c[i] << " ";
	return 0;
}
