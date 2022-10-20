#include <iostream>

using namespace std;

int main()
{
	int e_day, e_month, e_year, r_day, r_month, r_year;
	cout << "Enter the expected return date (dd mm yyyy): ";
	while(cin >> e_day >> e_month >> e_year)
	{
		if(e_day < 1 || e_day > 31)
		{
			cout << "Invalid day entered, please try again...\n";
			continue;
		}
		if(e_month < 1 || e_month > 12)
		{
			cout << "Invalid month entered, please try again...\n";
			continue;
		}
		break;
	}
	
	cout << "Enter the actual return date (dd mm yyyy): ";
	while(cin >> r_day >> r_month >> r_year)
	{
		if(r_day < 1 || r_day > 31)
		{
			cout << "Invalid day entered, please try again...\n";
			continue;
		}
		if(r_month < 1 || r_month > 12)
		{
			cout << "Invalid month entered, please try again...\n";
			continue;
		}
		break;
	}
	
	float fine = 0.0;
	
	if(e_year == r_year)
	{
		if(e_month == r_month)
			fine = 15*(r_day - e_day);
		else
			fine = 500*(r_month - e_month);
	}
	else
		fine = 10000;
		
	cout << endl << "Returning book..." << endl;
	cout << "You have to pay a fine of Rs. " << fine << endl;
	return 0;
}
