#include <iostream>

using namespace std;

int main()
{
	int n, rev = 0, t;
	cout << "Enter a 5 digit number: "; cin >> n;
	t = n;
	int m = 10000;
	while(t)
	{
		rev += (t % 10) * m;
		m /= 10;
		t /= 10;
	}
	
	cout << "Reversed number is: " << rev << endl;
	if(rev == n) cout << "Reversed number is equal to original number";
	else cout << "Reversed number is not equal to original number";
	return 0;
}
