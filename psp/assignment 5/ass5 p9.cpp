#include <iostream>
#include <cmath>
using namespace std;
int d = 0;

int det(int n, int mat[10][10])
{

    int submat[10][10];
    if (n == 2)
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            d = d + (pow(-1, x) * mat[0][x] * det(n - 1, submat));
        }
    }
    return d;
}

int main()
{

    cout << "Enter the dimension of the matrix:\n";
    int n, D;
    cin >> n;
    int mat[10][10];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[j][i];
        }
    }
    D = det(n, mat);
    cout << "The determinant of the given matrix is: " << D << endl;
    if (D)
        cout << "Matrix is not singular";
    else
        cout << "matrix is singular ";
    return 0;
}
