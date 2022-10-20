#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the value of n: "; cin >> n;
	int sum = n;
	while(n--)
		sum += n;
		
	cout << "Sum is " << sum;
	return 0;
}
