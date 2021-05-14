#include "Appliance.h"

Appliance::Appliance() : Product()
{
	this->watts = 0;
	this->length = 0;
	this->width = 0;
	this->height = 0;
}
Appliance::Appliance(double price, std::string name, std::string manufacturer, double watts, double length, double width, double height) : Product(price, name, APPLIANCES, manufacturer)
{
	this->watts = watts;
	this->length = length;
	this->width = width;
	this->height = height;
}
Appliance::Appliance(const Appliance& other)
{
	*this = other;
}
Appliance& Appliance::operator=(const Appliance& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->watts = other.watts;
		this->length = other.length;
		this->width = other.width;
		this->height = other.height;
	}
	return *this;
}

std::string Appliance::getDimensions() const
{
	return ("length: " + std::to_string(this->length) + "cm, width: " + std::to_string(this->width) + "cm, height: " + std::to_string(this->height) + "cm");
}

void Appliance::print_description() const
{
	Product::print_description();
	std::cout << "Power: " << this->watts << std::endl;
	std::cout << "Dimensions: " << getDimensions() << std::endl;
}