#include "AccountDatabase.h"
#include <iostream>
#include <Windows.h>
#ifdef max
#undef max
#endif

AccountDatabase::AccountDatabase() {}
AccountDatabase::AccountDatabase(const AccountDatabase& other)
{
	*this = other;
}
AccountDatabase& AccountDatabase::operator=(const AccountDatabase& other)
{
	if (this != &other)
	{
		this->users = other.users;
	}
	return *this;
}

bool AccountDatabase::validateUsername(std::string givenUsername) const
{
	if (givenUsername.size() < 4 || givenUsername.size() > 12 || givenUsername.find(' ') != std::string::npos)
		return false;
	return true;
}
bool AccountDatabase::validatePassword(std::string givenPassword) const
{
	if (givenPassword.size() < 8 || givenPassword.size() > 16 || givenPassword.find(' ') != std::string::npos)
		return false;
	return true;
}
bool AccountDatabase::validateEmail(std::string givenEmail) const
{
	std::regex emailRegex("\\w+(([\\_\\-\\.]\\w+)*)\\@\\w+(([\\-\\.]\\w+)+)");

	if (std::regex_match(givenEmail, emailRegex))
		return true;

	return false;
}

User* AccountDatabase::login(bool& exitStore, bool& logged)
{
	while (true)
	{
		std::string email, password;
		std::string command;

		int index = 0;

		system("cls");

		std::cout << "In order to use the shop, you have to login first.\n";
		std::cout << "If you do not have an account, type \"-r\" to register.\n";
		std::cout << "Otherwise just click enter and proceed with your login info.\n";
		std::cout << "If you would like to exit, type \"-q\" \n\n";

		while (std::cin.peek() != '\n')
		{
			command += getchar();
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (command == "-r")
		{
			registerUser();
			continue;
		}
		else if (command == "-q")
		{
			exitStore = true;
			break;
		}
		else if (command != "")
		{
			std::cout << "\n\nERROR! Please read the instructions above.";
			exitStore = false;
			Sleep(2000);
			continue;
		}

		std::cout << "Email: ";
		
		while (std::cin.peek() != '\n')
		{
			email += getchar();
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!validateEmail(email))
		{
			std::cout << "\n\nERROR! Given email is invalid.";
			Sleep(2000);
			continue;
		}

		index = getUserIndex(email);

		if (index < 0)
		{
			std::cout << "\n\nERROR! User with given email doesn't exist.";
			Sleep(2000);
			continue;
		}

		std::cout << "Password: ";

		while (std::cin.peek() != '\n')
		{
			password += getchar();
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!this->users[index].authenticatePassword(password))
		{
			std::cout << "\n\nERROR! Wrong password.";
			Sleep(2000);
			continue;
		}

		logged = true;
		return &this->users[index];
	}
	return nullptr;
}
void AccountDatabase::registerUser()
{
	while (true)
	{
		system("cls");

		bool invalid = false;
		bool userExists = false;

		std::string email, username, password;

		std::cout << "Enter your email (in the format \"user123@example123.com\"): ";

		while (std::cin.peek() != '\n')
		{
			email += getchar();
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!validateEmail(email))
		{
			std::cout << "\n\nERROR! Chosen email doesn't meet the requirements.";
			Sleep(2000);
			continue;
		}

		if (getUserIndex(email) >= 0)
		{
			std::cout << "\n\nERROR! User with given email already exists.";
			Sleep(2000);
			continue;
		}

		std::cout << "\nChoose your username (between 4 and 12 characters, no space allowed): ";

		while (std::cin.peek() != '\n')
		{
			username += getchar();
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!validateUsername(username))
		{
			std::cout << "\n\nERROR! Chosen username doesn't meet the requirements.";
			Sleep(2000);
			continue;
		}

		if (usernameExists(username))
		{
			std::cout << "\n\nERROR! User with given username already exists.";
			Sleep(2000);
			continue;
		}

		std::cout << "\nChoose your password (between 8 and 16 characters, no space allowed): ";

		while (std::cin.peek() != '\n')
		{
			password += getchar();
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!validatePassword(password))
		{
			std::cout << "\n\nERROR! Chosen password doesn't meet the requirements.";
			Sleep(2000);
			continue;
		}

		User newUser = User(username, password, email);
		this->users.push_back(newUser);

		std::cout << "\n\n Registration successful!";

		Sleep(2000);
		return;
	}
}

int AccountDatabase::getUserIndex(std::string email) const
{
	for (int i = 0; i < this->users.size(); i++)
	{
		if (this->users[i].authenticateEmail(email))
		{
			return i;
		}
	}
	return -1;
}

bool AccountDatabase::usernameExists(std::string username) const
{
	for (int i = 0; i < this->users.size(); i++)
	{
		if (this->users[i].getUsername() == username)
		{
			return true;
		}
	}
	return false;
}