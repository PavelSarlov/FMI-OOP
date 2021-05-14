#pragma once

#ifndef FOLDER_H
#define FOLDER_H

#include "File.h"
#include <vector>
#pragma warning(disable : 4996)

class Folder
{
public:
	Folder();
	Folder(std::string name);
	Folder(const Folder& other);
	Folder& operator=(const Folder& other);
	~Folder();

	std::string get_name() const;
	std::string get_date() const;
	std::string get_path() const;

	bool add_folder(std::string path, Folder folder);
	bool add_file(std::string path, const File* file);
	bool remove_folder(std::string path, std::string folderName);
	bool remove_file(std::string path, std::string fileName);
	File* get_file(std::string path, std::string fileName) const;
	const Folder& find_folder(std::string path) const;

	void print() const;

private:
	std::string name;
	std::string date;
	std::vector<Folder> folders;
	std::vector<File*> files;
	std::string path;

	bool exists(std::string fileName) const;
};
#endif
