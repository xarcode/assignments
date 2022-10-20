#include <iostream>
#include <string>

using namespace std;

string reverse(string s, int n)
{
	if(n == 0)
		return "";
	return s[n - 1] + reverse(s, n - 1);
}

int main()
{
	int n;
	cout << "Enter a decimal number (base 10): "; cin >> n;
	
	string res = "";
	int t = n;
	while(t)
	{
		res += (t % 8) + '0';
		t /= 8;
	}
	
	cout << "Octal (base 8) representation is: " << reverse(res, res.length()) << endl;
	
	res = "";
	t = n;
	while(t)
	{
		int r = (t % 16);
		if(r < 10) res += r + '0';
		else
		{
			switch(r)
			{
				case 10:
					res += 'A';
					break;
				case 11:
					res += 'B';
					break;
				case 12:
					res += 'C';
					break;
				case 13:
					res += 'D';
					break;
				case 14:
					res += 'E';
					break;
				case 15:
					res += 'F';
					break;
			}
		}
		t /= 16;
	}
	
	cout << "Hexadecimal representation is: " << reverse(res, res.length());
	
	return 0;
}
