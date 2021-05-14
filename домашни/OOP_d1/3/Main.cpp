#include <iostream>
#include "MyString.h"
#include "IntCounter.h"
#include "SVG.h"

int main()
{
	SVG svg = SVG();

	Rectangle some_rectangle = Rectangle({ 0,0 }, { 4,5 });

	svg.createRectangle({ 0,0 }, { 1,1 });	// area = 1, index = 0;
	svg.addRectangle(some_rectangle);	// area = 20, index = 1;

	std::cout << svg.getLargestAreaRectIndex() << std::endl;	// 1

	system("pause");
	return 0;
}