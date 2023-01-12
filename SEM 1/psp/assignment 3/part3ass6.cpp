#include <iostream>

using namespace std;

int main()
{
	int n1, n2;
	cout << "Enter 2 numbers: "; cin >> n1 >> n2;
	
	int num = (n1>n2)?n1:n2;
    int den = (n1<n2)?n1:n2;
    int rem = num % den;
 
    while (rem != 0)
    {
        num   = den;
        den = rem;
        rem   = num % den;
    }
    int gcf = den;
    int lcm = n1 * n2 / gcf;
    cout << "GCF is " << gcf << endl;
    cout << "LCM is " << lcm << endl;
	return 0;
}
