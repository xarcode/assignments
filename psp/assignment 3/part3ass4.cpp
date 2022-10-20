#include <iostream>

using namespace std;

int main()
{
	int n1, n2;
	char op;
	cout << "Enter a simple expression(num1 operator num2): "; cin >> n1 >> op >> n2;
	
	switch(op)
	{
		case '+':
			cout << "= " << n1 + n2;
			break;
		case '-':
			cout << "= " << n1 - n2;
			break;
		case '*':
			cout << "= " << n1 * n2;
			break;
		case '/':
			cout << "= " << n1 / n2;
			break;
		default:
			cout << "Invalid operator";
			break;
	}
	return 0;
}
