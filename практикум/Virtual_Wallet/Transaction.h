#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <chrono>
#include "Card.h"
#include "PaymentInfo.h"

class Transaction
{
public:
	Transaction();
	Transaction(PaymentInfo, time_t);
	Transaction(const Transaction&);
	Transaction& operator=(const Transaction& other);

	PaymentInfo getPaymentInfo() const;
	const char* getTimeAndDate() const;

private:
	PaymentInfo paymentInfo;
	time_t timeAndDate;
};

#endif

