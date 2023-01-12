#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Enter the value of a: "; cin >> a;
	cout << "Enter the value of b: "; cin >> b;
	
	cout << endl << "Before swapping..." << endl;
	cout << "a = " << a << "\tb = " << b << endl;
	
	a += b;
	b = a - b;
	a -= b;
	
	cout << endl << "After swapping..." << endl;
	cout << "a = " << a << "\tb = " << b;
	return 0;
}
