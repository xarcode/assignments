#include <iostream>

using namespace std;

int main()
{
	char a;
	cout << "Enter an alphabet: "; cin >> a;
	
	switch(a)
	{
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			cout << "Entered alphabet is a vowel";
			break;
		default:
			cout << "Entered alphabet is not a vowel";
			break;
	}
	return 0;
}
