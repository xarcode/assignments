#include <iostream>

using namespace std;

int main()
{
	float n;
	cout << "Enter a floating point number: "; cin >> n;
	int k;
	cout << "Enter a value for k: "; cin >> k;
	
	int m = 1;
	while(k--) m *= 10;
	
	int r = n * m;
	int d = n * m * 10;

	if(d % 10 < 5) cout << "Rounded number is " << r / (m * 1.0);
	else cout << "Rounded number is " << (r + 1) / (m * 1.0);
	return 0;
}
