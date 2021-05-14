#pragma once

#ifndef USER_H
#define USER_H

#include <regex>
#include <string>
#include "Cart.h"

class User
{
public:
	User();
	User(std::string username, std::string password, std::string email);
	User(const User& other);
	User& operator=(const User& other);

	std::string getUsername() const;
	double getBalance() const;
	Cart& getCart();
	
	bool validateUsername(std::string givenUsername) const;
	bool validatePassword(std::string givenPassword) const;
	bool validateEmail(std::string givenEmail) const;
	bool authenticateEmail(std::string givenPassword) const;
	bool authenticatePassword(std::string givenEmail) const;
	bool addFunds(double);
	bool makePurchase();

private:
	std::string username;
	std::string password;
	std::string email;
	double balance;
	Cart cart;

	bool confirmPurchase() const;
};

#endif