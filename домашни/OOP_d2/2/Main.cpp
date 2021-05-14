#include <iostream>
#include "IntCounter.h"

int main()
{
	IntCounter<int> counter1;

	std::cout << counter1.get_count() << " - " << counter1.get_value() << std::endl;	// if value is nullptr -> returns -1

	IntCounter<char> counter2 = IntCounter<char>(new char[2]{"a"});
	{
		IntCounter<char> counter3 = counter2;

		std::cout << counter2.get_count() << " - " << counter2.get_value() << std::endl;
		std::cout << counter3.get_count() << " - " << counter3.get_value() << std::endl;
	}
	
	std::cout << counter2.get_count() << " - " << counter2.get_value() << std::endl;

	system("pause");
	return 0;
}