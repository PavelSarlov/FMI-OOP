#include "Clothing.h"

Clothing::Clothing() : Product() {}
Clothing::Clothing(double price, std::string name, std::string manufacturer, std::string color, std::string size) : Product(price, name, CLOTHING, manufacturer)
{
	this->color = color;
	this->size = size;
}
Clothing::Clothing(const Clothing& other)
{
	*this = other;
}
Clothing& Clothing::operator=(const Clothing& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->color = other.color;
		this->size = other.size;
	}
	return *this;
}

void Clothing::print_description() const
{
	Product::print_description();
	std::cout << "Color: " << this->color << std::endl;
	std::cout << "Size: " << this->size << std::endl;
}