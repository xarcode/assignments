#include <iostream>

using namespace std;

int main()

{
	int year;
	cout << "Enter year: "; cin >> year;
	
	if(year % 100 == 0)
	{
		if(year % 400 == 0) cout << "It is a leap year";
		else cout << "It is not a leap year";
	}
	else if(year % 4 == 0) cout << "It is a leap year";
	else cout << "it is not a leap year";
	return 0;
}
