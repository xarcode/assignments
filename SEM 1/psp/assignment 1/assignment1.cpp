#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	
	float res = num2 / (num1*1.0);
	
	(res == num2 / num1) ? cout << "1st number dicvides the 2nd number exactly" : cout << "1st number does not divide the second number exactly";
	return 0;
}
