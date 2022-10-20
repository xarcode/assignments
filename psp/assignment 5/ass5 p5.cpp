#include <iostream>

using namespace std;

int main()
{
	string a, b;
	cout << "Enter first string: "; cin >> a;
	cout << "Enter second string: "; cin >> b;
	if(a == b) cout << "The strings are equal";
	else cout << "Strings are not equal";
	return 0;
}
