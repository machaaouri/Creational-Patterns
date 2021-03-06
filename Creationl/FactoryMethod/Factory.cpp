#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>

class Point
{
	Point(const float x, const float y)
		: x{ x },
		y{ y }
	{
	}

public:
	float x, y;

	friend std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		return os
			<< "x : " << obj.x
			<< " y : " << obj.y;

	}

	friend class PointFactory;
};

class PointFactory
{
public:
	static Point Cartesian(const float x, const float y)
	{
		return{ x,y };
	}

	static Point Polar(const float r, const float theta)
	{
		return{ r*cos(theta),r*sin(theta) };
	}
};

int main()
{
	auto c = PointFactory::Cartesian(2, 3);
	std::cout << c << std::endl;

	auto p = PointFactory::Polar(5, M_PI_4);
	std::cout << p << std::endl;

	getchar();
	return 0;
}