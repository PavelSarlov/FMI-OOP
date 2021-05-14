#include "Software.h"

Software::Software() : Product() {}
Software::Software(double price, std::string name, std::string manufacturer, std::string version) : Product(price, name, SOFTWARE, manufacturer)
{
	this->version = version;
}
Software::Software(const Software& other)
{
	*this = other;
}
Software& Software::operator=(const Software& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->version = other.version;
	}
	return *this;
}

void Software::print_description() const
{
	Product::print_description();
	std::cout << "Version: " << this->version << std::endl;
}