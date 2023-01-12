#include <iostream>

using namespace std;

struct complex
{
	int real, img;	
};

void printComplex(complex c)
{
	cout << c.real << " ";
	if(c.img < 0) cout << "- " << -c.img;
	else cout << "+ " << c.img;
	cout << "i";
}

int main()
{
	complex c1, c2;
	cout << "Enter real and imaginary value for 1st complex number: "; cin >> c1.real >> c1.img;
	cout << "Enter real and imaginary value for 2nd complex number: "; cin >> c2.real >> c2.img;
	
	cout << "---------ADDITION---------\n";
	printComplex(c1); cout << " + "; printComplex(c2);
	complex c3;
	c3.real = c1.real + c2.real;
	c3.img = c1.img + c2.img;
	cout << " = "; printComplex(c3);
	
	cout << "\n------MULTIPLICATION------\n";
	printComplex(c1); cout << " * "; printComplex(c2);
	c3.real = c1.real * c2.real - c1.img * c2.img;
	c3.img = c1.img * c2.real + c1.real * c2.img;
	cout << " = "; printComplex(c3);
	return 0;
}
