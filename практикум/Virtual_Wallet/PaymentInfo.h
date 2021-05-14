#pragma once

#ifndef PAYMENTINFO_H
#define PAYMENTINFO_H

#include <iostream>
#include "HelperFunctions.h"

class PaymentInfo
{
public:
	PaymentInfo();
	PaymentInfo(double, const char*);
	PaymentInfo(const PaymentInfo& other);
	PaymentInfo& operator=(const PaymentInfo& other);
	~PaymentInfo();

	double getItemPrice() const;
	const char* getItemName() const;

private:
	double itemPrice;
	const char* itemName;

	// Product* items;
	// double subtotal;
};
#endif