#include <iostream>

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6}, n = 6;
	int *p = a;
	int sum = 0;
	
	for(int i = 0; i < n; i++) sum += *(p + i);
		
	cout << "sum is " << sum;	
	return 0;
}
