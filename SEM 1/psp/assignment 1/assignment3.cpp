#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Enter 3 numbers: "; cin >> a >> b >> c;
	
	if(a > b && a > c) cout << "Maximum is " << a << endl;
	if(b > a && b > c) cout << "Maximum is " << b << endl;
	if(c > a && c > b) cout << "Maximum is " << c << endl;
	
	if(a < b && a < c) cout << "Minimum is " << a << endl;
	if(b < a && b < c) cout << "Minimum is " << b << endl;
	if(c < a && c < b) cout << "Minimum is " << c << endl;
	
	return 0;
}
