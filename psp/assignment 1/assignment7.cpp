#include <iostream>

using namespace std;

int main()
{
	int n, p, m = 1;
	cout << "Enter a number: "; cin >> n;
	cout << "Enter power of 2: "; cin >> p;
	
	for(int i = 0; i < p; i++)
		m *= 2;
	int m_res = n * m, d_res = n / m;
	cout << endl << "Finding result without using bitwise operator..." << endl;
	cout << n << " x 2^" << p << " = " << m_res << endl;
	cout << n << " / 2^" << p << " = " << d_res << endl;
	
	cout << endl << "Finding result using bitwise operator..." << endl;
	cout << n << " x 2^" << p << " = " << (n << p) << endl;
	cout << n << " / 2^" << p << " = " << (n >> p) << endl;

	return 0;
}
