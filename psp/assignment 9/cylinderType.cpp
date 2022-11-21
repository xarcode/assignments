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

class cylinderType : public circleType
{
protected:
	int height;
public:
	cylinderType() : circleType()
	{
		height = 0;
	}	
	
	cylinderType(int _x, int _y, int radius, int _h) : circleType(radius, _x, _y)
	{
		height = _h;
	}
	
	double getVolume()
	{
		return height * getArea();
	}
	
	double getSurfaceArea()
	{
		return height * getCircumference() + 2 * getArea();
	}
	
	void setHeight(int _h)
	{
		height = _h;
	}
	
	void display()
	{
		cout << "Cylinder height: " << height << endl;
		cout << "Cylinder radius: " << radius << endl;
		cout << "Cylinder centre: ";
		pointType::display();
	}
};

int main()
{
	cylinderType cyl(10, 5, 6, 7);
	cyl.display();
	cout << "Volume is " << cyl.getVolume() << endl;
	cout << "Surface area is " << cyl.getSurfaceArea();
	return 0;
}
