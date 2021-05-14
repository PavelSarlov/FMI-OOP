#pragma once

#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"

class Clothing : public Product
{
public:
	Clothing();
	Clothing(double price, std::string name, std::string manufacturer, std::string color, std::string size);
	Clothing(const Clothing& other);
	Clothing& operator=(const Clothing& other);

	void print_description() const;

private:
	std::string color;
	std::string size;
};

#endif // !CLOTHING_H


