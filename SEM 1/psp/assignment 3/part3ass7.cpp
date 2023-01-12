#include <iostream>

using namespace std;

int main()
{
	int n, fact = 1;
	cout << "Enter a number: "; cin >> n;
	
	do
	{
		fact *= n;
		n--;
	}while(n);
	
	cout << "Factorial is " << fact;
	return 0;
}
