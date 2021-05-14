#pragma once

#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include <regex>
#include "User.h"

class AccountDatabase
{
public:
	AccountDatabase();
	AccountDatabase(const AccountDatabase& other);
	AccountDatabase& operator=(const AccountDatabase& other);

	void registerUser();
	User* login(bool&, bool&);

private:
	std::vector<User> users;

	bool validateUsername(std::string) const;
	bool validatePassword(std::string) const;
	bool validateEmail(std::string) const;
	bool usernameExists(std::string username) const;
	int getUserIndex(std::string email) const;
};
#endif // !ACCOUNTDATABASE_H