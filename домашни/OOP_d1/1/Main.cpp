#include <iostream>
#include "MyString.h"
#include "IntCounter.h"
#include "SVG.h"

int main()
{
	MyString temp("Hello world");
	temp.print();
	temp.append('!');
	temp.print();

	MyString temp1("asdf");
	MyString temp2("bsdf");
	MyString temp3("asdf");

	std::cout << (temp1 == temp2) << std::endl;		   //0
	std::cout << (temp1 != temp2) << std::endl;		   //1
	std::cout << (temp1 > temp2) << std::endl;		   //0
	std::cout << (temp1 < temp2) << std::endl;		   //1
	std::cout << (temp1 == temp3) << std::endl;		   //1

	system("pause");
	return 0;
}