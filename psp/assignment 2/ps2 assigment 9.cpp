#include <iostream>

using namespace std;

int main()
{
	int n, s;
	cout << "Enter a 3 digit number: "; cin >> n;
	
	do{
		s = 0;
		while(n)
		{
			s += n % 10;
			n /= 10;
		}
		n = s;
	}while(s / 10);
	
	cout << "Result is " << s;
	return 0;
}
