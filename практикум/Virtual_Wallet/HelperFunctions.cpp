#include "HelperFunctions.h"

void setStringValues(const char*& oldStr, const char* newStr)
{
	if (oldStr == nullptr)
		oldStr = new char[1]();

	if (newStr == nullptr)
	{
		delete[] oldStr;
		oldStr = nullptr;
		return;
	}

	for (int i = 0; newStr[i] != '\0'; i++)
	{
		char* temp = new char[i + 2]();
		for (int j = 0; j < i + 1; j++)
			temp[j] = newStr[j];
		delete[] oldStr;
		oldStr = temp;
	}
}

void printString(const char* str)
{
	if (str == nullptr)
		return;

	for (int i = 0; str[i] != '\0'; i++)
		std::cout << str[i];
}