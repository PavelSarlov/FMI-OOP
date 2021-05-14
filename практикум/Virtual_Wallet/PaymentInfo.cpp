#include "PaymentInfo.h"

PaymentInfo::PaymentInfo()
{
	this->itemPrice = 0;
	this->itemName = nullptr;
}
PaymentInfo::PaymentInfo(double price, const char* name)
{
	this->itemPrice = price;
	setStringValues(this->itemName, name);
}
PaymentInfo::PaymentInfo(const PaymentInfo& other)
{
	this->itemPrice = other.itemPrice;
	this->itemName = new char[1]();
	setStringValues(this->itemName, other.itemName);
}
PaymentInfo& PaymentInfo::operator=(const PaymentInfo& other)
{
	if (this != &other)
	{
		this->itemPrice = other.itemPrice;
		this->itemName = new char[1]();
		setStringValues(this->itemName, other.itemName);
	}
	return *this;
}
PaymentInfo::~PaymentInfo()
{
	if (this->itemName != nullptr)
		delete[] this->itemName;
}

double PaymentInfo::getItemPrice() const
{
	return this->itemPrice;
}
const char* PaymentInfo::getItemName() const
{
	return this->itemName;
}