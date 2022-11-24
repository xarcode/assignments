#include <iostream>
#include <math.h>

using namespace std;

class pointType
{
protected:
	int x, y;
public:
	pointType()
	{
		x = 0;
		y = 0;
	}
	
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

class circleType : public pointType
{
protected:
	int radius;
public:
	circleType() : pointType()
	{
		radius = 0;
	}
	
	circleType(int _r, int _x, int _y) : pointType(_x, _y)
	{
		radius = _r;
	}
	
	double getArea()
	{
		return M_PI * radius * radius;
	}
	
	double getCircumference()
	{
		return 2 * M_PI * radius;
	}
	
	void display()
	{
		cout << "Circle radius: " << radius << endl;
		cout << "Circle centre: ";
		pointType::display();
	}
	
	void setCenter(int _x, int _y)
	{
		set(_x, _y);
	}
	
	void setRadius(int _r)
	{
		radius = _r;
	}
	
	int getRadius()
	{
		return radius;
	}
	
	int getCentreX(){ return x; }
	int getCentreY(){ return y; }
};

int main()
{
	circleType c(10, 5, 5);
	c.display();
	cout << "Area " << c.getArea() << endl;
	cout << "Circumference: " << c.getCircumference() << endl;
	return 0;
}
