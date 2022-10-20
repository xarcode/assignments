#include <iostream>

using namespace std;

int main()
{
	float total_sp, total_p, cost_p;
	cout << "Enter the total selling price of 15 items: "; cin >> total_sp;
	cout << "Enter the total profit on the sale of 15 items: "; cin >> total_p;
	
	cout << "Cost price of 1 item: " << (total_sp - total_p) / 15;
	return 0;
}
