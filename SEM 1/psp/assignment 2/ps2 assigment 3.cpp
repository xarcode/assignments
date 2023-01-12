#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n, res, m = 10000;
	cout << "Enter a 5 digit number: "; cin >> n;
	
	while(n)
	{
		res += (m * (n % 10));
		m /= 10;
		n /= 10;
	}
	
	n = res;
	cout << "Reversed number is " << setw(5) << setfill('0') << n;
	return 0;
}
