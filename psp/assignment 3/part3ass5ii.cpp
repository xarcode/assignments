#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter a number: "; cin >> n;
	
	int sum = 0;
	while(n)
	{
		int t = n;
		int term = 1;
		while(t > 1)
			term *= t--;
		sum += term;
		n--;
	}
	
	cout << "Sum of series is " << sum;
	return 0;
}
