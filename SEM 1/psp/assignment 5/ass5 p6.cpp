#include <iostream>

using namespace std;

int main()
{
	string a, b;
	cout << "Enter first string: "; cin >> a;
	cout << "Enter second string: "; cin >> b;
	
	string c = a + b;
	cout << "After concatenation, string is " << c;
	return 0;
}
