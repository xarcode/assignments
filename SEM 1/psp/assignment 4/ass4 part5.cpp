#include <iostream>

using namespace std;

int main()
{
	float cp, sp;
	cout << "Enter the cost price: "; cin >> cp;
	cout << "Enter the selling price: "; cin >> sp;
	
	float p = sp - cp;
	if(p < 0) cout << "Loss incurred of Rs. " << p * -1;
	else cout << "Profit gained of Rs. " << p; 
	return 0;
}
