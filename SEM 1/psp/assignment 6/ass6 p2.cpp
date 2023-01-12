#include <iostream>
#include <cstring>

using namespace std;

struct account
{
	string name;
	string accno;
	int balance;	
};

int main()
{
	account accs[10];
	int n;
	cout << "Enter the number of accounts in your bank: "; cin >> n;
	cin.get();
	for(int i = 0; i < n; i++)
	{
		cout << "Enter name of account holder: "; getline(cin, accs[i].name);
		cout << "Enter account number: "; cin >> accs[i].accno;
		cout << "Enter account balance: "; cin >> accs[i].balance;
		cin.get();
	}
	
	string accno;
	cout << "\nEnter account number to search for: "; cin >> accno;
	bool found = false;
	for(int i = 0; i < n; i++)
	{
		if(accs[i].accno == accno)
		{
			cout << "Name of Account Holder: " << accs[i].name << endl;
			cout << "Account Number: " << accs[i].accno << endl;
			cout << "Balance: " << accs[i].balance;
			found = true;
			break;
		}
	}
	
	if(!found)
		cout << "Account not found";
	return 0;
}
