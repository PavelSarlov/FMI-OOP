#pragma once

#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "Product.h"

class Software : public Product
{
public:
	Software();
	Software(double price, std::string name, std::string manufacturer, std::string version);
	Software(const Software& other);
	Software& operator=(const Software& other);

	void print_description() const;

private:
	std::string version;
	// other specs
};

#endif
