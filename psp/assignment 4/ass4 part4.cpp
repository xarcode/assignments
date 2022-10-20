#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	int n, res = 0, m = 1,k=0;
	cout << "Enter a 5 digit number: "; cin >> n;
	
	while(n)
	{
		int t = n % 10;
		if(t + 1 < 10)
			res += (t + 1) * m;
		
		m *= 10;
		n /= 10;
		k++;
	}
	
	cout << "Result: " <<  setw(k) << setfill('0') << res;	
	return 0;
}
