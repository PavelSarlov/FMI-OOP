#include "Image.h"

Image::Image()
{
	this->deviceName = "Unknown device";
}
Image::Image(std::string deviceName, unsigned int width, unsigned int height, std::string fileName, double size) : File(fileName, (rand()%100+1)<=50 ? ".jpg" : ".png", size, IMAGE)
{
	this->deviceName = deviceName;
	this->width = width;
	this->height = height;
}
Image::Image(std::string deviceName, unsigned int width, unsigned int height, std::string fileName, std::string extension, double size) : File(fileName, extension, size, IMAGE)
{
	this->deviceName = deviceName;
	this->width = width;
	this->height = height;
}
Image::Image(const Image& other) : File(other)
{
	*this = other;
}
Image& Image::operator=(const Image& other)
{
	if (this != &other)
	{
		File::operator=(other);
		this->deviceName = other.deviceName;
		this->width = other.width;
		this->height = other.height;
	}
	return *this;
}

std::string Image::get_deviceName() const
{
	return this->deviceName;
}
unsigned int Image::get_width() const
{
	return this->width;
}
unsigned int Image::get_height() const
{
	return this->height;
}

void Image::print() const
{
	File::print();
	std::cout << "Device used: " << this->deviceName << std::endl;
	std::cout << "Width: " << this->width << std::endl;
	std::cout << "Height: " << this->height << std::endl << std::endl;
}