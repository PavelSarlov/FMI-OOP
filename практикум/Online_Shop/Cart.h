#pragma once

#ifndef CART_H
#define CART_H

#include <iostream>
#include <Windows.h>
#ifdef max
#undef max
#endif
#include <iomanip>
#include "Product.h"
#include "Cart.h"
#include <vector>
#include <map>

class Cart
{
public:
	Cart();
	Cart(const Cart& other);
	Cart& operator=(const Cart& other);
	~Cart();

	double getTotalCost() const;
	std::map<Product*, int> getItems() const;

	void addItem(int, int, const Product*);
	void removeItem(int);
	void empty();
	void showCartInfo() const;
	bool confirmItems() const;
	void showPurchaseInfo() const;

private:
	std::map<Product*, int> items;
	double totalCost;
};
#endif // !CART_H