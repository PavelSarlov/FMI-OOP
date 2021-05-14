#include <iostream>
#include "SuccessMessage.h"

int main()
{
	SuccessMessage msg = SuccessMessage("message");
	SuccessMessage other = msg;

	std::cout << msg.getMessage() << std::endl;
	std::cout << other.getMessage() << std::endl;

	return 0;
}