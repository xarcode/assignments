#include <iostream>

using namespace std;

int main()
{
	int l, b;
	cout << "Enter length and breadth of a rectangle"; cin >> l >> b;
	if(l * b < 2 * (l + b))
		cout << "Perimeter is greater than area";
	else cout << "Area is greater than perimeter";
	return 0;
}
