#include <iostream>

using namespace std;

void printMat(int m[][3], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int m1[3][3] = {
					{1, 2, 3}, 
					{4, 5, 6}, 
					{7, 8, 9}
				   };
	int m2[3][3] = {
					{3, 2, 1}, 
					{4, 1, 3}, 
					{8, 7, 9}
				   };
	int m3[3][3];
				   
	cout << "Addition of matrices:\n";
	printMat(m1, 3); cout << "+\n"; printMat(m2, 3); cout << "=\n";
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m3[i][j] = m1[i][j] + m2[i][j];
	printMat(m3, 3);

	cout << "Subtraction of matrices:\n";
	printMat(m1, 3); cout << "-\n"; printMat(m2, 3); cout << "=\n";
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m3[i][j] = m1[i][j] - m2[i][j];
	printMat(m3, 3);
	
	cout << "Multiplication of matrices:\n";
	printMat(m1, 3); cout << "*\n"; printMat(m2, 3); cout << "=\n";
	for (int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
        {
            m3[i][j] = 0;
            for (int k = 0; k < 3; k++)
                m3[i][j] += m1[i][k] * m2[k][j];
    	}
	}
	printMat(m3, 3);	
	
	return 0;
}
