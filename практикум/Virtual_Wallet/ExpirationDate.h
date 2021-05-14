#pragma once

#ifndef EXPIRATIONDATE_H
#define EXPIRATIONDATE_H

#include <iostream>
#include <chrono>
#include <ctime>

const time_t YEAR_IN_SECONDS = 31536000;	// 365 days
const time_t MONTH_IN_SECONDS = 2678400;	// 31 days
const time_t DAY_IN_SECONDS = 86400;		// 24 hours

class ExpirationDate
{
public:
	ExpirationDate();
	ExpirationDate(time_t duration);
	ExpirationDate(const ExpirationDate& other);
	ExpirationDate& operator=(const ExpirationDate& other);

	int getMonth() const;
	int getYear() const;

	friend std::ostream& operator<<(std::ostream& out, const ExpirationDate& expDate);

private:
	int month;
	int year;
};

#endif // !EXPIRATIONDATE_H