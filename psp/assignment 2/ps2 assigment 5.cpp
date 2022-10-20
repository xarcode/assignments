#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the value of n: "; cin >> n;
	cout << "Sum of squares of first n numbers: " << (n * (n + 1) * (2 * n + 1)) / 6;
	return 0;
}
