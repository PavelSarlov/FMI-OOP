#include "Home.h"

Home::Home() : Product()
{
	this->length = 0;
	this->width = 0;
	this->height = 0;
}
Home::Home(double price, std::string name, std::string manufacturer, std::string material, double length, double width, double height) : Product(price, name, HOME, manufacturer)
{
	this->length = length;
	this->width = width;
	this->height = height;
}
Home::Home(const Home& other)
{
	*this = other;
}
Home& Home::operator=(const Home& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->length = other.length;
		this->width = other.width;
		this->height = other.height;
	}
	return *this;
}

std::string Home::getDimensions() const
{
	return ("length: " + std::to_string(this->length) + "cm, width: " + std::to_string(this->width) + "cm, height: " + std::to_string(this->height) + "cm");
}

void Home::print_description() const
{
	Product::print_description();
	std::cout << "Material: " << this->material << std::endl;
	std::cout << "Dimensions: " << getDimensions() << std::endl;
}