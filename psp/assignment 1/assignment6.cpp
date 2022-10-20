#include <iostream>

using namespace std;

int main()
{
	int n, s = 0;
	cout << "Enter a 3 digit number: "; cin >> n;
	while(n)
	{
		s += n % 10;
		n /= 10;
	}
	
	cout << "Sum of the digits of the number is " << s;
	return 0;
}
