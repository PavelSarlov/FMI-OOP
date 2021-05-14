#include "Folder.h"
#include "Image.h"
#include "Audio.h"

Folder::Folder()
{
	this->name = "New Folder";
	time_t currentDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	this->date = std::ctime(&currentDate);
	this->path = "New Folder/";
}
Folder::Folder(std::string name)
{
	this->name = name;
	time_t currentDate = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	this->date = std::ctime(&currentDate);
	this->path = name + "/";
}
Folder::Folder(const Folder& other)
{
	*this = other;
}
Folder& Folder::operator=(const Folder& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->date = other.date;
		this->folders = other.folders;
		this->files = other.files;
		this->path = other.path;
	}
	return *this;
}
Folder::~Folder()
{
	while (!this->files.empty())
	{
		delete this->files.back();
		this->files.pop_back();
	}
}

std::string Folder::get_name() const
{
	return this->name;
}
std::string Folder::get_date() const
{
	return this->date;
}
std::string Folder::get_path() const
{
	return this->path;
}

bool Folder::add_folder(std::string path, Folder folder)
{
	if (path == this->name)
	{
		folder.path = this->path + folder.path;
		this->folders.push_back(folder);
		return true;
	}
	else
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].add_folder(path, folder))
				return true;
		}
	}
	return false;
}
bool Folder::add_file(std::string path, const File* file)
{
	if (file == nullptr)
		return false;

	if (path == this->path)
	{
		switch (file->get_type())
		{
		case IMAGE:
			this->files.push_back(new Image(*(dynamic_cast<const Image*>(file))));
			break;
		case AUDIO:
			this->files.push_back(new Audio(*(dynamic_cast<const Audio*>(file))));
			break;
		}
		this->files.back()->set_path(this->path + file->get_name() + file->get_extension());
		return true;
	}
	else
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].add_file(path, file))
				return true;
		}
	}
	return false;
}
bool Folder::remove_folder(std::string path, std::string folderName)
{
	if (this->path == path)
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			if (folderName == this->folders[i].get_name())
			{
				this->folders.erase(this->folders.begin() + i);
				return true;
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].remove_folder(path, folderName))
			{
				return true;
			}
		}
	}
	return false;
}
bool Folder::remove_file(std::string path, std::string fileName)
{
	if (this->path == path)
	{
		for (unsigned int i = 0; i < this->files.size(); i++)
		{
			if (fileName == this->files[i]->get_name() + this->files[i]->get_extension())
			{
				this->files.erase(this->files.begin() + i);
				return true;
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].remove_file(path, fileName))
			{
				return true;
			}
		}
	}
	return false;
}
File* Folder::get_file(std::string path, std::string fileName) const
{
	if (this->path == path)
	{
		for (unsigned int i = 0; i < this->files.size(); i++)
		{
			if (fileName == this->files[i]->get_name() + this->files[i]->get_extension())
			{
				return this->files[i];
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].exists(fileName))
			{
				return this->folders[i].get_file(path, fileName);
			}
		}
	}
	throw "ERROR! File with the name \"" + fileName + "\" not found.\n";
}

void Folder::print() const
{
	std::cout << "Path: " << this->path << std::endl;
	std::cout << "Date created: " << this->date;
	std::cout << "Folders contained: ";
	for (unsigned int i = 0; i < this->folders.size(); i++)
	{
		std::cout << this->folders[i].get_name() << ", ";
	}
	std::cout << std::endl << "Files contained: ";
	for (unsigned int i = 0; i < this->files.size(); i++)
	{
		std::cout << this->files[i]->get_name() << this->files[i]->get_extension() << ", ";
	}
	std::cout << std::endl << std::endl;
}

bool Folder::exists(std::string fileName) const
{
	for (unsigned int i = 0; i < this->files.size(); i++)
	{
		if (fileName == this->files[i]->get_name() + this->files[i]->get_extension())
		{
			return true;
		}
	}
	return false;
}

const Folder& Folder::find_folder(std::string path) const
{
	if (this->path == path)
	{
		return *this;
	}
	else
	{
		for (unsigned int i = 0; i < this->folders.size(); i++)
		{
			return this->folders[i].find_folder(path);
		}
	}

	throw "ERROR! Destination at \"" + path + "\" not found.\n";
}
