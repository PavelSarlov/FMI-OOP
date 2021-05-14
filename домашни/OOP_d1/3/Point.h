#pragma once
class Point
{
public:
	Point();
	Point(double, double);

	double getPointX() const;
	double getPointY() const;

private:
	double pointX;
	double pointY;
};

