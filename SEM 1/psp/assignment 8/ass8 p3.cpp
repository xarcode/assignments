#include <iostream>

using namespace std;

class myString
{
	string s;
	
	public:
		myString(string str)
		{
			s = str;
		}
		
		void show()
		{
			cout << s << endl;
		}
		
		bool operator == (myString s1)
		{
			return s == s1.s;
		}
		
		myString operator + (myString s1)
		{
			return myString(s + s1.s);
		}
};

int main()
{
	myString s1("ayush");
	myString s2("Ayush");
	s1.show();
	s2.show();
	
	cout << "Comparing the two strings\n";
	cout << (s1 == s2 ? "strings are equal": "strings are not equal") << endl;
	
	cout << "Concatenating the two strings\n";
	myString s3 = s1 + s2;
	s3.show();
	return 0;
}
