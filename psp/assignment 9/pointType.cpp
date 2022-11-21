#include <iostream>
#include <cmath>

using namespace std;

class pointType
{
protected:
	int x, y;
public:
//	pointType()
//	{
//		x = 0;
//		y = 0;
//	}
//	
	pointType(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	
	double distanceFromOrigin()
	{
		return sqrt(x*x + y*y);
	}
	
	int distanceFromXAxis(){ return y; }
	int distanceFromYAxis(){ return x; }
	int getX(){ return x; }
	int getY(){ return y; }
	
	void set(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	
	void display()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

int main()
{
	pointType p(10, 20);
	cout << "The point is: ";
	p.display();
	cout << "Distance from origin: " << p.distanceFromOrigin() << endl;
	cout << "Distance from X Axis: " << p.distanceFromXAxis() << endl;
	cout << "Distance from Y Axis: " << p.distanceFromYAxis() << endl;
	return 0;
}
