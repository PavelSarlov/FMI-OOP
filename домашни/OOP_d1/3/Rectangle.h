#pragma once
#include "Point.h"

class Rectangle
{
public:
	Rectangle();
	Rectangle(Point, Point);

	double getArea() const;
	void findArea();

private:
	Point pointA;
	Point pointB;
	double area;
};

