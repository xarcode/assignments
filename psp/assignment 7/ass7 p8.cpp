#include <iostream>

using namespace std;

class class_name
{
	int a;
	string b;
	
	public:
		class_name()
		{
			a = 10;
			b = "Inline function example";
		}
		
		void implicit_inline_function()
		{
			cout << "Implicit inline function called" << endl;
			cout << "Printing values of data members:" << endl;
			cout << a << ", " << b << endl;
		}
		
		void explicit_inline_function();
};

inline void class_name::explicit_inline_function()
{
	cout << "Explicit inline function called" << endl;
	cout << "Printing values of data members:" << endl;
	cout << a << ", " << b << endl;	
}

int main()
{
	class_name c;
	c.implicit_inline_function();
	c.explicit_inline_function();
	return 0;
}
