#pragma once

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

enum Category { SOFTWARE, HOME, CLOTHING, ELECTRONICS, APPLIANCES, DEFAULT };

class Product
{
public:
	Product();
	Product(double price, std::string name, Category category, std::string manufacturer);
	Product(const Product& other);
	Product& operator=(const Product& other);
	
	int getId() const;
	std::string getName() const;
	double getPrice() const;
	Category getCategory() const;
	std::string  getCategoryName() const;
	std::string getManufacturer() const;

	virtual void print_description() const;

private:
	int id;
	std::string name;
	double price;
	Category category;
	std::string categoryName;
	std::string manufacturer;
};
#endif // !PRODUCT_H


namespace std
{
	template<> struct less<Product>	// iterating the products by sorting them by name
	{
		bool operator() (const Product& first, const Product& second) const
		{
			return first.getName() < second.getName();
		}
	};
}