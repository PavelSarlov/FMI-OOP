#pragma once
#include "Rectangle.h"

class SVG
{
public:
	SVG();
	~SVG();

	Rectangle* getRectangles() const;
	int getRectanglesCount() const;

	void addRectangle(Rectangle&);
	void createRectangle(Point, Point);
	int getLargestAreaRectIndex() const;

private:
	Rectangle* rectangles;
	int rectanglesCount;
};

