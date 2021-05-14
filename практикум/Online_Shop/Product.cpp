#include "Product.h"

int ID_INCREMENT = 1;

//	Constructor/Destructor
Product::Product()
{
	this->id = 0;
	this->price = 0;
	this->category = DEFAULT;
}
Product::Product(double price, std::string name, Category category, std::string manufacturer)
{
	this->id = ID_INCREMENT++;
	this->name = name;
	this->price = price;
	this->category = category;
	switch (category)
	{
	case 0:
		this->categoryName = "Software";
		break;
	case 1:
		this->categoryName = "Home";
		break;
	case 2:
		this->categoryName = "Clothing";
		break;
	case 3:
		this->categoryName = "Electronics";
		break;
	case 4:
		this->categoryName = "Appliances";
		break;
	default:
		this->categoryName = "Default";
		break;
	}
	this->manufacturer = manufacturer;
}
Product::Product(const Product& other)
{
	*this = other;
}
Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->name = other.name;
		this->price = other.price;
		this->category = other.category;
		this->categoryName = other.categoryName;
		this->manufacturer = other.manufacturer;
	}
	return *this;
}

//	Getters
int Product::getId() const
{
	return this->id;
}
std::string Product::getName() const
{
	return this->name;
}
double Product::getPrice() const
{
	return this->price;
}
Category Product::getCategory() const
{
	return this->category;
}
std::string Product::getCategoryName() const
{
	return this->categoryName;
}
std::string Product::getManufacturer() const
{
	return this->manufacturer;
}

void Product::print_description() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Manufacturer: " << this->manufacturer << std::endl;
	std::cout << "Price: " << this->price << " lv." << std::endl;
	std::cout << "ID: " << this->id << std::endl;
}