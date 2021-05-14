#pragma once

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Folder.h"

class FileSystem
{
public:
	FileSystem();
	FileSystem(const FileSystem& other);
	FileSystem& operator=(const FileSystem& other);

	void add_folder(std::string path, Folder folder);
	void add_file(std::string path, const File* file);
	void remove_folder(std::string path, std::string folderName);
	void remove_file(std::string path, std::string fileName);
	File* get_file(std::string path, std::string fileName) const;
	void print_contents(std::string folderName) const;

private:
	Folder mainDirectory = Folder("C:");
};
#endif
