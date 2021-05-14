#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
	this->pointA = { 0,0 };
	this->pointB = { 0,0 };
	this->area = 0;
}
Rectangle::Rectangle(Point pointA, Point pointB)
{
	if (pointA.getPointX() == pointB.getPointX() || pointA.getPointY() == pointB.getPointY())
	{
		std::cout << "ERROR! Points cannot be on the same axis.\n";
	}
	else
	{
		this->pointA = pointA;
		this->pointB = pointB;
		this->area = abs(this->pointA.getPointX() - this->pointB.getPointX()) * abs(this->pointA.getPointY() - this->pointB.getPointY());
	}
}

double Rectangle::getArea() const
{
	return area;
}