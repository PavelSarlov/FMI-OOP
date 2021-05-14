#pragma once

#ifndef APPLIANCE_H
#define APPLIANCE_H

#include "Product.h"
#include <iostream>

class Appliance : public Product
{
public:
	Appliance();
	Appliance(double price, std::string name, std::string manufacturer, double watts, double length, double width, double height);
	Appliance(const Appliance& other);
	Appliance& operator=(const Appliance& other);

	std::string getDimensions() const;

	void print_description() const;

private:
	double watts;
	double length;
	double width;
	double height;
};

#endif // !APPLIANCE_H




