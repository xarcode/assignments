#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter a 4 digit number: "; cin >> n;
	cout << "Sum of first and last digit of number is: " << (n / 1000) + (n % 10);
	return 0;
}
