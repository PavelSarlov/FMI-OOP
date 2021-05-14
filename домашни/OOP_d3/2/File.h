#pragma once

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#pragma warning(disable : 4996)

enum FileType {BLANK, IMAGE, AUDIO};

class File
{
public:
	File();
	File(std::string name, std::string extension, double size, FileType type);
	File(const File& other);
	File& operator=(const File& other);

	std::string get_name() const;
	std::string get_extension() const;
	std::string get_date() const;
	std::string get_path() const;
	double get_sizeMB() const;
	FileType get_type() const;

	void set_path(std::string newPath);
	void rename(std::string newName);

	virtual void print() const;

private:
	std::string name;
	std::string extension;
	std::string date;
	std::string path;
	double sizeMB = 0;
	FileType type = BLANK;
};

#endif