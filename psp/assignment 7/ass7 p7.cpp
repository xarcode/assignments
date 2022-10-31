#include <iostream>

using namespace std;

class Sum
{
	int n;
	
	public:
		Sum(){
			n = 2;
			cout << "Sum of first " << n << " natural numbers is " << n * n << endl;
		}
		
		Sum(int k)
		{
			n = k;
			cout << "Sum of first " << n << " natural numbers is " << n * n << endl;
		}
		
		Sum(const Sum &s)
		{
			n = s.n;
			cout << "Sum of first " << n << " natural numbers is " << n * n << endl;
		}
};

int main()
{
	Sum s;
	Sum s2(5);
	Sum s3(s2);
	return 0;
}
