#pragma once

#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "User.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <map>

class Store
{
public:
	Store();
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	void setFilterProductsList(Category);

	void showStoreInfo();
	void addProduct(int, const Product*);
	void removeProduct(int);
	void storeInterface(User*);
	void storeLogic(User*, bool&, bool&);

private:
	std::map<Product*, int> products;
	Category filterProductsList;
};
#endif // !STORE_H

