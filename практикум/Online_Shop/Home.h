#pragma once

#ifndef HOME_H
#define HOME_H

#include "Product.h"

class Home : public Product
{
public:
	Home();
	Home(double price, std::string name, std::string manufacturer, std::string material, double length, double width, double height);
	Home(const Home& other);
	Home& operator=(const Home& other);

	std::string getDimensions() const;

	void print_description() const;

private:
	std::string material;
	double length;
	double width;
	double height;
};

#endif // !HOME_H



