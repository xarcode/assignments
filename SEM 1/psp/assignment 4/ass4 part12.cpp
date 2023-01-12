#include <iostream>

using namespace std;

int main()
{
	int m = 3, n;
	cout << "Enter number of students: "; cin >> n;
	int sub1 = 0, sub2 = 0, sub3 = 0, total = 0;
	for(int i = 0; i < n; i++)
	{
		int t1, t2, t3;
		cout << "Enter marks of 3 subjects of student " << i + 1 << ": "; cin >> t1 >> t2 >> t3;
		sub1 += t1;
		sub2 += t2;
		sub3 += t3;
		total += t1 + t2 + t3;
	}
	
	cout << "Subject 1 average: " << sub1 / (n * 1.0) << endl;
	cout << "Subject 2 average: " << sub2 / (n * 1.0) << endl;
	cout << "Subject 3 average: " << sub3 / (n * 1.0) << endl;
	cout << "Class average: " << total / (3 * n * 1.0);
	return 0;
}
