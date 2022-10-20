#include <iostream>

using namespace std;

void takeInput(int&, int&);
void showMenu();
void showResult(int, int , int);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
float divide(int, int);
int mod(int, int);
int exponent(int, int);

int main()
{
	showMenu();
	return 0;
}

void showMenu()
{
	int choice = -1, a, b;
	do
	{
		cout << "SIMPLE CALCULATOR" << endl;
		cout << endl;
		cout << "1. Add two numbers" << endl;
		cout << "2. Subtract two numbers" << endl;
		cout << "3. Multiply two numbers" << endl;
		cout << "4. Divide two numbers" << endl;
		cout << "5. Modulus of two numbers" << endl;
		cout << "6. Exponent of two numbers" << endl;
		cout << "Press 0 to Exit..." << endl;
		
		cin >> choice;
		
		if(choice)
		{
			takeInput(a, b);
			showResult(a, b, choice);
		}	
			
	}while(choice);
}

void takeInput(int &a, int &b)
{
	cout << "Enter two numbers: "; cin >> a >> b;
}

void showResult(int a, int b, int choice)
{
	switch(choice)
	{
		case 1:
			cout << a << " + " << b << " = " << add(a, b);
			break;
		case 2:
			cout << a << " - " << b << " = " << subtract(a, b);
			break;
		case 3:
			cout << a << " * " << b << " = " << multiply(a, b);
			break;
		case 4:
			cout << a << " / " << b << " = " << divide(a, b);
			break;
		case 5:
			cout << a << " % " << b << " = " << mod(a, b);
			break;
		case 6:
			cout << a << " ^ " << b << " = " << exponent(a, b);
			break;
	}
	
	cout << endl;
}

int add(int a, int b)
{
	return  a + b;
}

int subtract(int a, int b)
{
	return  a - b;
}

int multiply(int a, int b)
{
	return  a * b;
}

float divide(int a, int b)
{
	if(b == 0)
	{
		cout << "Cant divide a number by 0" << endl;
		return 0.0;
	}
	
	return a / b;
}

int mod(int a, int b)
{
	return a % b;
}

int exponent(int a, int b)
{
	int t = 1;
	while(b--) t *= a;
	
	return t;
}
