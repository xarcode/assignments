#include <iostream>
#include <string>

using namespace std;

struct date{
	int day;
	int month;
	int year;
};

struct library{
	string name;
	string book_id;
	date day_of_renewal;
};

void getDate(date &d)
{
	cout << endl;
	cout << "Enter day: "; cin >> d.day;
	cout << "Enter month: "; cin >> d.month;
	cout << "Enter year: "; cin >> d.year;
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

int main()
{
	int n;
	
	cout << "Enter number of users in your library: "; cin >> n;
	library users[n];
	
	for(int i = 0; i < n; i++)
	{
		getchar();
		cout << "Enter your name: "; getline(cin, users[i].name);
		cout << "Enter book id: "; cin >> users[i].book_id;
		getchar();
		cout << "Enter date of renewal of book\n"; getDate(users[i].day_of_renewal);
	}
	
	date returnDate, dummy;

	cout << "Enter date of renewal of books\n"; getDate(returnDate);
	
	cout << "Names of students who are defaulters:\n";
	for(int i = 0; i < n; i++)
		if(compareDate(users[i].day_of_renewal, returnDate) > 0)
			cout << users[i].name << endl;
	return 0;
}
