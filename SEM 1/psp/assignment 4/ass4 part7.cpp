#include <iostream>

using namespace std;

int main()
{
	float a, b, c;
	cout << "Enter the 3 angles of a triangle: "; cin >> a >> b >> c;
	if(a + b + c == 180) cout << "This is a valid triangle";
	else cout << "This is an invalid triangle: ";
	return 0;
}
