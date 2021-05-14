#include "Point.h"

Point::Point()
{
	this->pointX = 0;
	this->pointY = 0;
}
Point::Point(double x, double y)
{
	this->pointX = x;
	this->pointY = y;
}

double Point::getPointX() const
{
	return this->pointX;
}
double Point::getPointY() const
{
	return this->pointY;
}