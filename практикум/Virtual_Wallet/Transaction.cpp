#include "Transaction.h"

Transaction::Transaction()
{
	this->paymentInfo = PaymentInfo();
	this->timeAndDate = 0;
}
Transaction::Transaction(PaymentInfo paymentInfo, time_t timeAndDate)
{
	this->paymentInfo = paymentInfo;
	this->timeAndDate = timeAndDate;
}
Transaction::Transaction(const Transaction& other)
{
	this->paymentInfo = other.paymentInfo;
	this->timeAndDate = other.timeAndDate;
}
Transaction& Transaction::operator=(const Transaction& other)
{
	if (this != &other)
	{
		this->paymentInfo = other.paymentInfo;
		this->timeAndDate = other.timeAndDate;
	}
	return *this;
}

PaymentInfo Transaction::getPaymentInfo() const
{
	return this->paymentInfo;
}
const char* Transaction::getTimeAndDate() const
{
	#pragma warning(suppress : 4996)
	return ctime(&this->timeAndDate);
}