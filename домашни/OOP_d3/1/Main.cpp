#include <iostream>
#include "JSONArray.h"
#include "JSONObject.h"

int main()
{
	JSONArray<int> arr;

	arr.insert("somekey", 1);
	arr.insert(new JSONArray<int>());
	arr.insert(new JSONObject<int>("otherkey", 2));
	arr[1]->insert("anotherkey", 3);

	try
	{
		std::cout << arr.get_value("somekey") << std::endl;			// 1
		std::cout << arr.get_value("otherkey") << std::endl;		// 2
		std::cout << arr.get_value("anotherkey") << std::endl;		// 3

		arr.remove("somekey");

		std::cout << arr.get_value("somekey") << std::endl;		// does not exist -> exception
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}

	system("pause");
	return 0;
}