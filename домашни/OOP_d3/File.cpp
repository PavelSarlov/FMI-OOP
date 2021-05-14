#include "File.h"

File::File()
{
	this->name = "New File";
	this->extension = ".ext";
	time_t currentDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	this->date = std::ctime(&currentDate);
}
File::File(std::string name, std::string extension, double size, FileType type)
{
	this->name = name;
	this->extension = extension;
	this->sizeMB = size;
	time_t currentDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	this->date = std::ctime(&currentDate);
	this->type = type;
}
File::File(const File& other)
{
	*this = other;
}
File& File::operator=(const File& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->extension = other.extension;
		this->sizeMB = other.sizeMB;
		this->date = other.date;
		this->type = other.type;
		this->path = other.path;
	}
	return *this;
}

std::string File::get_name() const
{
	return this->name;
}
std::string File::get_extension() const
{
	return this->extension;
}
std::string File::get_date() const
{
	return this->date;
}
std::string File::get_path() const
{
	return this->path;
}
double File::get_sizeMB() const
{
	return this->sizeMB;
}
FileType File::get_type() const
{
	return this->type;
}

void File::rename(std::string newName)
{
	std::cout << "Successfully renamed \"" << this->name << this->extension << "\" to \"" << newName << this->extension << "\"!\n\n";
	this->name = newName;	
}
void File::set_path(std::string newPath)
{
	this->path = newPath;
}

void File::print() const
{
	std::cout << "File path: " << this->path << std::endl;
	std::cout << "Size: " << this->sizeMB << " MB" << std::endl;
	std::cout << "Date created: " << this->date;
}