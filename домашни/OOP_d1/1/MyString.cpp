#include "MyString.h"
#include <cstring>
#include <iostream>

MyString::MyString()
{
	this->str = new char[1]();
}
MyString::MyString(const char* str)
{
	this->str = new char[1]();
	for (int i = 0; str[i]!='\0'; i++)
	{
		append(str[i]);
	}
}
MyString::~MyString()
{
	delete[] this->str;
}

char* MyString::getStr() const
{
	return this->str;
}

void MyString::print()
{
	for (int i = 0; getStr()[i] != '\0'; i++)
	{
		std::cout << getStr()[i];
	}
	std::cout << std::endl;
}
void MyString::append(const char symbol)
{
	int length = strlen(getStr());
	char* newStr = new char[length + 2]();
	for (int i = 0; i < length; i++)
	{
		newStr[i] = getStr()[i];
	}
	this->~MyString();
	this->str = newStr;
	this->str[length] = symbol;
}
bool operator==(MyString& str1, MyString& str2)
{
	if (strlen(str1.getStr()) != strlen(str2.getStr()))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < str1.getStr()[i]!='\0'; i++)
		{
			if (str1.getStr()[i] != str2.getStr()[i])
			{
				return false;
			}
		}
	}
	return true;
}
bool operator!=(MyString& str1, MyString& str2)
{
	if (strlen(str1.getStr()) != strlen(str2.getStr()))
	{
		return true;
	}
	else
	{
		for (int i = 0; i < strlen(str1.getStr()); i++)
		{
			if (str1.getStr()[i] != str2.getStr()[i])
			{
				return true;
			}
		}
	}
	return false;
}
bool operator>(MyString& str1, MyString& str2)
{						   
	for (int i = 0; str1.getStr()[i] != '\0' || str1.getStr()[i] != '\0'; i++)
	{
		if (str1.getStr()[i] > str2.getStr()[i])
			return true;
		else if (str1.getStr()[i] < str2.getStr()[i])
			return false;
	}
	return false;
}						   
bool operator<(MyString& str1, MyString& str2)
{
	for (int i = 0; str1.getStr()[i] != '\0' || str1.getStr()[i] != '\0'; i++)
	{
		if (str1.getStr()[i] < str2.getStr()[i])
			return true;
		else if (str1.getStr()[i] > str2.getStr()[i])
			return false;
	}
	return false;
}