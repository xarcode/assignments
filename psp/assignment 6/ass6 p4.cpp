#include <iostream>
#include <string>

using namespace std;

struct date{
	int day;
	int month;
	int year;
};

void getDate(date &d)
{
	cout << endl;
	cout << "Enter day: "; cin >> d.day;
	cout << "Enter month: "; cin >> d.month;
	cout << "Enter year: "; cin >> d.year;
}

void showDate(date d)
{
	cout << endl;
	cout << "day: " << d.day;
	cout << ", month: " << d.month;
	cout << ", year: " << d.year;
}

int compareDate(date d1, date d2)
{
	if(d1.year == d2.year)
		if(d1.month == d2.month)
			if(d1.day == d2.day) return 0;
			else if(d1.day < d2.day) return -1;
			else return 1;
		else if(d1.month < d2.month) return -1;
		else return 1;
	else if(d1.year < d2.year) return -1;
	return 1;
}

date addDays(int days, date d)
{
	date newDate;
	newDate.day = d.day + days > 30 ? (d.day + days) % 30 : d.day + days;
	newDate.month = d.day + days > 30 ? d.month == 12 ? 1 : d.month + 1 : d.month;
	newDate.year = d.day + days > 30 ? d.month + 1 > 12 ? d.year + 1 : d.year : d.year;
	
	return newDate;
}

int main()
{
	date d1, d2;
	cout << "Enter date 1: "; getDate(d1);
	cout << "Enter date 2: "; getDate(d2);
	
	if(compareDate(d1, d2) == 0) cout << "Entered dates are equal\n";
	else if(compareDate(d1, d2) < 0) cout << "Day 1 comes before day 2\n";
	else cout << "Day 1 comes after day 2\n";
	
	int days;
	cout << "Enter number of days to add to day1: "; cin >> days;
	cout << "New date is: "; showDate(addDays(days, d1));
	return 0;
}
