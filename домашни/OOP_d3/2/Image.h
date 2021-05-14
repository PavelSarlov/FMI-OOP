#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include "File.h"

class Image : public File
{
public:
	Image();
	Image(std::string deviceName, unsigned int width, unsigned int height, std::string fileName, double size);
	Image(std::string deviceName, unsigned int width, unsigned int height, std::string fileName, std::string extension, double size);
	Image(const Image& other);
	Image& operator=(const Image& other);

	std::string get_deviceName() const;
	unsigned int get_width() const;
	unsigned int get_height() const;

	virtual void print() const;

private:
	std::string deviceName;
	unsigned int width = 0;
	unsigned int height = 0;
};

#endif