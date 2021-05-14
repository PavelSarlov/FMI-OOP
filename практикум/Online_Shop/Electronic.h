#pragma once

#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include "Product.h"

class Electronic : public Product
{
public:
	Electronic();
	Electronic(double price, std::string name, std::string manufacturer, std::string operatingSystem, std::string version);
	Electronic(const Electronic& other);
	Electronic& operator=(const Electronic& other);

	void print_description() const;

private:
	std::string operatingSystem;
	std::string version;
	// some other specifications
};

#endif