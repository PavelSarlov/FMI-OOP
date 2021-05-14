#include "SVG.h"
#include <iostream>

SVG::SVG()
{
	this->rectangles = new Rectangle[0];
	this->rectanglesCount = 0;
}
SVG::~SVG()
{
	delete[] this->rectangles;
}

Rectangle* SVG::getRectangles() const
{
	return this->rectangles;
}
int SVG::getRectanglesCount() const
{
	return this->rectanglesCount;
}

void SVG::addRectangle(Rectangle& rectangle)
{
	Rectangle* temp = new Rectangle[getRectanglesCount() + 1];
	for (int i = 0; i < getRectanglesCount(); i++)
	{
		temp[i] = getRectangles()[i];
	}
	delete[] this->rectangles;
	this->rectangles = temp;
	this->rectangles[getRectanglesCount()] = rectangle;
	this->rectanglesCount += 1;
}
void SVG::createRectangle(Point pointA, Point pointB)
{
	Rectangle rectangle = Rectangle(pointA, pointB);
	addRectangle(rectangle);
}
int SVG::getLargestAreaRectIndex() const
{
	int index = 0;

	for (int i = 1; i < getRectanglesCount(); i++)
	{
		if (getRectangles()[i].getArea() > getRectangles()[index].getArea())
		{
			index = i;
		}
	}

	return index;
}