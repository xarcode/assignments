#include <iostream>

using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3;
	float m1, m2;
	cout << "Enter the coordinates of first point: "; cin >> x1 >> y1;
	cout << "Enter the coordinates of second point: "; cin >> x2 >> y2;
	cout << "Enter the coordinates of third point: "; cin >> x3 >> y3;
	
	m1 = (y2 - y1) / ((x2 - x1) * 1.0);
	m2 = (y3 - y1) / ((x3 - x1) * 1.0);
	
	if(m1 == m2) cout << "Points are collinear";
	else cout << "Points are not collinear";
	return 0;
}
