#include <iostream>
#include <cstring>
#include "File.h"
#include "Audio.h"
#include "Image.h"
#include "Folder.h"
#include "FileSystem.h"
#include "JSONArray.h"
#include "JSONObject.h"
#include "Teacher.h"
#include "Course.h"
#include "Student.h"

//int main()
//{
//	srand(time(NULL));	// randomly choosing extensions later
//
//	FileSystem sys;
//
//	sys.add_folder("C:", Folder("folder1"));
//
//	Image image = Image("imagemaker", 20, 30, "image", ".png", 2);
//	Audio song = Audio("someartist", "songname", 2001, ".mp3", 3);
//
//	sys.add_file("C:/folder1/", &image);
//	sys.add_file("C:/", &song);
//	sys.add_file("C:/", &image);
//
//	try
//	{
//		sys.get_file("C:/folder1/", "image.png")->print();
//		sys.get_file("C:/", "someartist-songname.mp3")->print();
//		sys.get_file("C:/", "someartist-songname.mp3")->rename("song");		// not returning const in order to be able to rename
//		sys.get_file("C:/", "somefile.txt");									// file does not exist -> exception
//	}
//	catch (std::string error)
//	{
//		std::cout << error << std::endl;
//	}
//
//	sys.print_contents("C:/");
//	sys.print_contents("C:/folder1/");
//
//	sys.remove_file("C:/folder1/", "image.png");
//
//	sys.print_contents("C:/");
//	sys.print_contents("C:/folder1/");
//	sys.print_contents("C:/folder/");
//
//	system("pause");
//	return 0;
//}

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
	catch(const char* msg)
	{
		std::cout << msg << std::endl;
	}

	system("pause");
	return 0;
}