#include <iostream>
#include <string>

using namespace std;

class Employee
{
	static int count;
	int EmployeeNumber;
	string EmployeeName;
	int BasicSalary;
	int Allowances;
	int IT;
	int NetSalary;
	
	public:
		Employee();
		void set_data();
		void calculate_net_salary();
		void print_details();
		static void employee_count();
		~Employee();
};

int Employee::count = 0;

inline void Employee::employee_count()
{
	cout << count << " employee(s) created" << endl;
}

Employee::Employee()
{
	count++;
	EmployeeNumber = count;
}

void Employee::set_data()
{
	cout << "Enter name of Employee: ";
	getline(cin, EmployeeName);
	cout << "Enter the Basic Salary: ";
	cin >> BasicSalary;
	getchar();
	calculate_net_salary();
}

void Employee::calculate_net_salary()
{
	Allowances = 1.23 * BasicSalary;
	IT = 0.3 * (Allowances + BasicSalary);
	NetSalary = BasicSalary + Allowances - IT;
}

void Employee::print_details()
{
	cout << "Employee Number: " << EmployeeNumber << endl;
	cout << "Employee Name: " << EmployeeName << endl;
	cout << "Basic Salary: Rs " << BasicSalary << endl;
	cout << "Allowances: Rs " << Allowances << endl;
	cout << "Income Tax: Rs " << IT << endl;
	cout << "Net Salary: Rs " << NetSalary << endl;
}

Employee::~Employee()
{
	cout << "Destroying Employee " << EmployeeNumber << endl;
	count--;
}

int main()
{
	Employee e1;
	e1.set_data();
	e1.print_details();
	
	Employee::employee_count();
	
	Employee e2;
	e2.set_data();
	e2.print_details();
	
	Employee::employee_count();
	
	return 0;
}
