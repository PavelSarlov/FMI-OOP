#include <iostream>
#include "MyString.h"

int main()
{
	MyString str("Some string.");

	std::cout << str << std::endl;

	std::cin >> str;

	std::cout << str << std::endl;

	system("pause");
	return 0;
}