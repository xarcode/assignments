#include <iostream>

using namespace std;

class FloydTriangle
{
	private:
		int n;
	public:
		FloydTriangle(int n1)
		{
			n = n1;
			int count = 1;
			for(int i = 0; i < n; i++){
				for(int j = 0; j <= i; j++)
					cout << count ++ << " ";
				cout << endl;
			}
		}
};

int main()
{
	FloydTriangle(5);
	return 0;
}
