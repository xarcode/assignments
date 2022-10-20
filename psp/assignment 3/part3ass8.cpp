#include <iostream>

using namespace std;

int main()
{
	cout << "Fibonacci series..." << endl;
	int n;
	cout << "Enter the number of terms in Fibonacci series: "; cin >> n;
	
	int t1 = 0, t2 = 1;
	cout << "The series is " << t1 << " ";
	for(int i = 1; i < n; i++)
	{
		cout << t2 << " ";	
		int t = t2;
		t2 += t1;
		t1 = t;
	}		
	cout << endl;
	
	cout << endl << "Find Prime numbers in a given range..." << endl;
	int l, h;
	cout << "Enter a range of numbers: "; cin >> l >> h;
	cout << "Prime numbers in the given range are: ";
	for(int i = l; i <= h; i++)
	{
		bool flag = false;
		for(int j = 2; j*j <= i; j++)
			if(i % j == 0) flag = true;
		
		if(!flag) cout << i << " ";
	}
	return 0;
}
