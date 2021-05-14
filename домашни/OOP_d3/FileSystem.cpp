#include "FileSystem.h"

FileSystem::FileSystem() {}
FileSystem::FileSystem(const FileSystem& other)
{
	*this = other;
}
FileSystem& FileSystem::operator=(const FileSystem& other)
{
	if (this != &other)
	{
		this->mainDirectory = other.mainDirectory;
	}
	return *this;
}

void FileSystem::add_folder(std::string path, Folder folder)
{
	this->mainDirectory.add_folder(path, folder);
}
void FileSystem::add_file(std::string path, const File* file)
{
	this->mainDirectory.add_file(path, file);
}
void FileSystem::remove_folder(std::string path, std::string folderName)
{
	if (this->mainDirectory.remove_folder(path, folderName))
	{
		std::cout << "Successfully removed \"" << folderName << "\" at \"" << path << "\"!\n\n";
	}
}
void FileSystem::remove_file(std::string path, std::string fileName)
{
	if (this->mainDirectory.remove_file(path, fileName))
	{
		std::cout << "Successfully removed \"" << fileName << "\" at \"" << path << "\"!\n\n";
	}
}
File* FileSystem::get_file(std::string path, std::string fileName) const
{
	return this->mainDirectory.get_file(path, fileName);
}
void FileSystem::print_contents(std::string folderName) const
{
	try
	{
		this->mainDirectory.find_folder(folderName).print();
	}
	catch (std::string error)
	{
		std::cout << error << std::endl;
	}
}
