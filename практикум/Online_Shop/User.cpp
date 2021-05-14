#include "User.h"

User::User()
{
	this->balance = 0;
}
User::User(std::string username, std::string password, std::string email)
{
	this->username = username;
	this->password = password;
	this->email = email;
}
User::User(const User& other)
{
	*this = other;
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		this->username = other.username;
		this->password = other.password;
		this->email = other.email;
		this->balance = other.balance;
		this->cart = other.cart;
	}
	return *this;
}


std::string User::getUsername() const
{
	return this->username;
}
bool User::authenticatePassword(std::string givenPassword) const
{
	if (this->password != givenPassword)
		return false;
	return true;
}
bool User::authenticateEmail(std::string givenEmail) const
{
	if (this->email != givenEmail)
		return false;
	return true;
}

double User::getBalance() const
{
	return this->balance;
}
Cart& User::getCart()
{
	return this->cart;
}

bool User::addFunds(double funds)
{
	if (funds <= 0)
		return false;

	this->balance += funds;
	return true;
}
bool User::makePurchase()
{
	if (this->cart.getTotalCost() > getBalance())
	{
		std::cout << "\nERROR! Insufficient funds.";
		Sleep(2000);
	}
	else if (!this->cart.confirmItems())
	{
		std::cout << "\nERROR! You haven't got any items in the cart.";
		Sleep(2000);
	}
	else
	{
		if (confirmPurchase())
		{
			this->balance -= this->cart.getTotalCost();
			this->cart.showPurchaseInfo();
			return true;
		}
	}
	return false;
}
bool User::confirmPurchase() const
{
	while (true)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");

		this->cart.showCartInfo();

		std::cout << "\nPlease confirm your purchase by typing \"Y\" or go back by typing \"N\"." << std::endl;

		if (std::cin.peek() != 'Y' && std::cin.peek() != 'N')
		{
			std::cout << "\nERROR! Bad input.";
			Sleep(2000);
			continue;
		}
		else if (std::cin.peek() == 'Y' || std::cin.peek() == 'N')
		{
			char input = getchar();

			if (std::cin.peek() != '\n')
			{
				std::cout << "\nERROR! Bad input.";
				Sleep(2000);
				continue;
			}
			else if (input == 'Y')
				return true;
			else
				return false;
		}
	}
}

bool User::validateUsername(std::string givenUsername) const
{
	if (givenUsername.size() < 4 || givenUsername.size() > 12 || givenUsername.find(' ') != std::string::npos)
		return false;
	return true;
}
bool User::validatePassword(std::string givenPassword) const
{
	if (givenPassword.size() < 4 || givenPassword.size() > 12 || givenPassword.find(' ') != std::string::npos)
		return false;
	return true;
}
bool User::validateEmail(std::string givenEmail) const
{
	std::regex emailRegex("\\w+(([\\_\\-\\.]\\w+)*)\\@\\w+(([\\-\\.]\\w+)+)");

	if (std::regex_match(givenEmail, emailRegex))
		return true;

	return false;
}