#include <iostream>
#include "JSONObject.h"
#include "JSONArray.h"

int main()
{
	JSONArray<int> someArray;

	JSONObject<int> someObject("somekey", new int(1));

	someArray.addObject(someObject);
	someArray.addObject("otherkey", new int(2));

	someArray.printToFile("somefile.txt");

	someArray.removeObject("somekey");

	someArray.printToFile("somefile.txt");

	std::cout << someArray.getValue("somekey") << std::endl;	// prints error and returns -1
	std::cout << someArray.getValue("otherkey") << std::endl;

	system("pause");
	return 0;
}