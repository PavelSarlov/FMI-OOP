#pragma once

#ifndef JSONARRAY_H
#define JSONARRAY_H

#include "JSONObject.h"
#include <fstream>

const int ERROR_VALUE = -1;

template <class T> 
class JSONArray
{
public:
	JSONArray();
	JSONArray(const JSONArray& other);
	JSONArray& operator=(const JSONArray& other);
	~JSONArray();

	void addObject(const JSONObject<T>&);
	void addObject(const char* key, T* value);
	void removeObject(const char* key);
	T getValue(const char* key);
	void printToFile(const char* fileName) const;

private:
	JSONObject<T>* objects;
	int objectsCount;

	bool containsObject(const char* key) const;
};

#endif // !JSONARRAY_H

template <class T>
JSONArray<T>::JSONArray()
{
	this->objects = nullptr;
	this->objectsCount = 0;
}

template <class T>
JSONArray<T>::JSONArray(const JSONArray& other)
{
	this->objects = new JSONObject<T>[other.objectsCount];
	for (int i = 0; i < other.objectsCount; i++)
		this->objects[i] = other.objects[i];
	this->objectsCount = other.objectsCount;
}

template <class T>
JSONArray<T>& JSONArray<T>::operator=(const JSONArray& other)
{
	if (this != &other)
	{
		if (this->objects != nullptr)
			delete[] this->objects;

		this->objects = new JSONObject<T>[other.objectsCount];
		for (int i = 0; i < other.objectsCount; i++)
			this->objects[i] = other.objects[i];
		this->objectsCount = other.objectsCount;
	}
	return *this;
}

template <class T>
JSONArray<T>::~JSONArray()
{
	if (this->objects != nullptr)
		delete[] this->objects;
}

template <class T>
void JSONArray<T>::addObject(const JSONObject<T>& object)
{
	JSONObject<T>* temp = new JSONObject<T>[this->objectsCount + 1];
	for (int i = 0; i < this->objectsCount; i++)
		temp[i] = this->objects[i];
	if (this->objects != nullptr)
		delete[] this->objects;
	this->objects = temp;
	this->objects[this->objectsCount] = object;
	this->objectsCount += 1;
}

template <class T>
void JSONArray<T>::addObject(const char* key, T* value)
{
	JSONObject<T>* temp = new JSONObject<T>[this->objectsCount + 1];
	for (int i = 0; i < this->objectsCount; i++)
		temp[i] = this->objects[i];
	if(this->objects != nullptr)
		delete[] this->objects;
	this->objects = temp;
	this->objects[this->objectsCount] = JSONObject<T>(key, value);
	this->objectsCount += 1;
}

template <class T>
void JSONArray<T>::removeObject(const char* key)
{
	if (containsObject(key))
	{
		int counter = 0;
		JSONObject<T>* temp = new JSONObject<T>[this->objectsCount - 1];
		for (int i = 0; i < this->objectsCount; i++)
		{
			if (!this->objects[i].validateKey(key))
				temp[counter++] = this->objects[i];
		}
		delete[] this->objects;
		this->objects = temp;
		this->objectsCount -= 1;
	}
}

template <class T>
T JSONArray<T>::getValue(const char* key)
{
	for (int i = 0; i < this->objectsCount; i++)
	{
		if (this->objects[i].validateKey(key))
			return *this->objects[i].getValue();
	}

	std::cout << "ERROR! No such object. ";
	return -1;
}

template <class T>
void JSONArray<T>::printToFile(const char* fileName) const	// Outputs characters with their ASCII codes
{
	if (fileName == nullptr)
	{
		std::cout << "ERROR! No file name given.\n";
		return;
	}

	std::ofstream file(fileName, std::ios::app);

	for (int i = 0; i < this->objectsCount; i++)
	{
		if(this->objects[i].getKey()!=nullptr)
			file << i + 1 << ". Key: " << this->objects[i].getKey() << ", ";
		else
			file << i + 1 << ". Key: NULL, ";

		if (this->objects[i].getValue() != nullptr)
			file << "Value: " << *this->objects[i].getValue() << std::endl;
		else
			file << "Value: NULL" << std::endl;
	}

	file.close();
}

template <class T>
bool JSONArray<T>::containsObject(const char* key) const
{
	for (int i = 0; i < this->objectsCount; i++)
	{
		if (this->objects[i].validateKey(key))
			return true;
	}
	std::cout << "ERROR! No such object.\n";
	return false;
}