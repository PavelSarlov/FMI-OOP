#include "Electronic.h"

Electronic::Electronic() : Product() {}

Electronic::Electronic(double price, std::string name, std::string manufacturer, std::string operatingSystem, std::string version) : Product(price, name, ELECTRONICS, manufacturer)
{
	this->operatingSystem = operatingSystem;
	this->version = version;
}

Electronic::Electronic(const Electronic& other)
{
	*this = other;
}
Electronic& Electronic::operator=(const Electronic& other)
{
	if (this != &other)
	{
		Product::operator=(other);
		this->operatingSystem = other.operatingSystem;
		this->version = other.version;
		// some other specs
	}
	return *this;
}

void Electronic::print_description() const
{
	Product::print_description();
	std::cout << "Version: " << this->version << std::endl;
	std::cout << "Operating system: " << this->operatingSystem << std::endl;
}