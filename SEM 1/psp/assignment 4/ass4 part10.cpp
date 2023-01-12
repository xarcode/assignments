#include <iostream>

using namespace std;

int main()
{
	int x, y, r;
	cout << "Enter the center of circle: "; cin >> x >> y;
	cout << "Enter the radius of circle: "; cin >> r;
	
	int p1, p2;
	cout << "Enter the coordinates of a point: "; cin >> p1 >> p2;
	
	int res = ((p1 - x) * (p1 - x)) + ((p2 - y) * (p2 - y)) - (r * r);
	if(res < 0)	cout << "Point lies inside the circle";
	else if(res == 0) cout << "Point lies on the circle";
	else cout << "Point lies outside the circle";
	
	return 0;
}
