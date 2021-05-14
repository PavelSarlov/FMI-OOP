#include "ExpirationDate.h"

ExpirationDate::ExpirationDate()
{
	this->month = 0;
	this->year = 0;
}
ExpirationDate::ExpirationDate(time_t duration)
{
	time_t systemTime = std::time(NULL) + duration;
	struct tm* aTime = std::localtime(&systemTime);

	this->month = aTime->tm_mon + 1;
	this->year = aTime->tm_year + 1900;
}
ExpirationDate::ExpirationDate(const ExpirationDate& other)
{
	this->month = other.month;
	this->year = other.year;
}
ExpirationDate& ExpirationDate::operator=(const ExpirationDate& other)
{
	if (this != &other)
	{
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}

int ExpirationDate::getMonth() const
{
	return this->month;
}
int ExpirationDate::getYear() const
{
	return this->year;
}

std::ostream& operator<<(std::ostream& out, const ExpirationDate& expDate)
{
	expDate.month > 9 ? out << expDate.month : out << "0" << expDate.month;
	out << '/';
	expDate.year % 100 > 9 ? out << expDate.year % 100 : out << "0" << expDate.year % 100;
	return out;
}