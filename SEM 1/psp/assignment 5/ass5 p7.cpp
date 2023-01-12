#include <iostream>

using namespace std;

int main()
{
	string s = "UNIVERSITY";
	int l = 10;
	
	for(int i = 2; i <= l; i += 2)
	{
		for(int j = 0; j < i; j++) cout << s[j] << " ";
		cout << endl;
	}
	
	for(int i = 8; i > 0; i -= 2)
	{
		for(int j = 0; j < i; j++) cout << s[j] << " ";
		cout << endl;
	}
	return 0;
}
