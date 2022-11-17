#include <iostream>

using namespace std;

class matrix
{
	int a[100][100], m, n;
	
	public:
		void getdata()
		{
			cout << "Enter the number of rows: "; cin >> m;
			cout << "Enter the number of columns: "; cin >> n;
			
			for(int i = 0; i < m; i++)
				for(int j = 0; j < n; j++)
					cin >> a[i][j];
		}
		
		void show()
		{
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++)
					cout << a[i][j] << " ";
				cout << endl;
			}
		}
		
		matrix operator + (matrix m1)
		{
			matrix m3;
			m3.m = m;
			m3.n = n;
			for(int i = 0; i < m; i++)
				for(int j = 0; j < n; j++)
					m3.a[i][j] = a[i][j] + m1.a[i][j];
			return m3;
		}
};

int main()
{
	matrix m1, m2;
	m1.getdata();
	m2.getdata();
	
	matrix m3 = m1 + m2;
	m3.show();
	return 0;
}
