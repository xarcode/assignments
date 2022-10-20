#include <iostream>
#include <iomanip>

using namespace std;

int daysInMonth(int month, bool isLeap)
{
	switch(month)
	{
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return 31;
		case 1:
			if(isLeap) return 29;
			return 28;
		default:
			return 30;
	}
	
	return -1;
}

string getMonth(int month)
{
	switch(month)
	{
		case 0:
			return "January";
		case 1:
			return "February";
		case 2:
			return "March";
		case 3:
			return "April";
		case 4:
			return "May";
		case 5:
			return "June";
		case 6:
			return "July";
		case 7:
			return "August";
		case 8:
			return "September";
		case 9:
			return "October";
		case 10:
			return "November";
		case 11:
			return "December";
	}
	return "";
}

string getDayOfWeek(int day)
{
	switch(day)
	{
		case 1:
			return "Mon";
		case 2:
			return "Tue";
		case 3:
			return "Wed";
		case 4:
			return "Thu";
		case 5:
			return "Fri";
		case 6:
			return "Sat";
		case 0:
			return "Sun";
	}
	return "";
}

bool isLeap(int year)
{
	if (year % 400 == 0) 
		return true;
  	else if (year % 100 == 0) 
    	return false;
	else if (year % 4 == 0) 
    	return true;
	
	return false;
}

void printCalendar(int year, int dayOfWeek)
{
	int a = dayOfWeek;
	for(int i = 0; i < 12; i++)
	{
		cout << setw(15) << getMonth(i) << endl;
		for(int j = 0; j < 7; j++) cout << getDayOfWeek(j) << " ";
		cout << endl;
		
		for(int b = 0; b < a; b++)
			cout << setw(4) << " ";
		for(int k = 1; k <= daysInMonth(i, isLeap(year)); k++)
		{
			if(a != 0 && a % 7 == 0) cout << endl;
			cout << setw(3) << k << " ";
			a++;
		}
		a %= 7;
		cout << endl << endl;	
	}
}

int main()
{
	int year, dayOfWeek;
	cout << "Enter year and day of Jan first: "; cin >> year >> dayOfWeek;
	printCalendar(year, dayOfWeek);
	return 0;
}
