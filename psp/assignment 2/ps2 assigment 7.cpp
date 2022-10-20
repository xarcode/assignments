#include <iostream>

using namespace std;

int main()
{
	float sp, cp, d, ap;
	cout << "Enter the mark price: "; cin >> sp;
	cout << "Enter the cost price: "; cin >> cp;
	cout << "Enter the discount percent: "; cin >> d;
	
	ap = sp - (sp*d/100.0);
	if(ap >= cp) cout << "A profit of Rs. " << ap - cp << " is incurred";
	else cout << "A loss of Rs. " << cp - ap << " is incurred";
	return 0;
}
