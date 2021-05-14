#include <iostream>
#include "MyString.h"
#include "IntCounter.h"
#include "SVG.h"

int main()
{
	int* some_number1 = new int(5);
	IntCounter first1(some_number1);
	std::cout << first1.getCounter() << std::endl;	//1
	IntCounter second1 = first1;
	std::cout << first1.getCounter() << std::endl;	//2

	{
		IntCounter third(second1);
		std::cout << first1.getCounter() << std::endl;	//3
	}
	std::cout << first1.getCounter() << std::endl;	//2

	std::cout << std::endl;

	int* some_number2 = new int(5);
	IntCounter first2(some_number2);

	int* some_number3 = new int(7);
	IntCounter second2(some_number3);

	std::cout << first2.getCounter() << std::endl;	//1
	std::cout << second2.getCounter() << std::endl;	//1
	std::cout << first2.getVariable() << std::endl;	//5
	std::cout << second2.getVariable() << std::endl;//7

	system("pause");
	return 0;
}