#pragma once

#ifndef OBJECTARRAY_H
#define OBJECTARRAY_H

#include <iostream>

template<class T>
class Array
{
public:
	Array();
	Array(T* arr, int size);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T* getArray();
	void add(const T& obj);
	void remove_at(int index);
	T& get_at(int index) const;
	int get_size() const;

private:
	T* arr;
	int size;
};

#endif

template<class T>
Array<T>::Array()
{
	this->arr = new T[0];
	this->size = 0;
}

template<class T>
Array<T>::Array(T* arr, int size)
{
	this->arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = arr[i];
	this->size = size;
}

template<class T>
Array<T>::Array(const Array& other)
{
	*this = other;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] this->arr;

		this->arr = new T[other.size];
		for (int i = 0; i < other.size; i++)
			this->arr[i] = other.arr[i];
		this->size = other.size;
	}
	return *this;
}

template<class T>
Array<T>::~Array()
{
	delete[] this->arr;
}

template<class T>
T* Array<T>::getArray()
{
	return this->arr;
}

template<class T>
void Array<T>::add(const T& obj)
{
	T* temp = new T[this->size + 1];
	for (int i = 0; i < this->size; i++)
		temp[i] = this->arr[i];
	delete[] this->arr;
	this->arr = temp;
	this->arr[size] = obj;
	this->size += 1;
}

template<class T>
void Array<T>::remove_at(int index)
{
	T* temp = new T[this->size - 1];
	for (int i = 0, j = 0; i < this->size; i++)
	{
		if (i != index)
			temp[j++] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temp;
	this->size -= 1;
}

template<class T>
T& Array<T>::get_at(int index) const
{
	if (index < 0 || index >= size)
	{
		std::cout << "ERROR! Invalid index.\n";
		return this->arr[this->size - 1];
	}
	return this->arr[index];
}

template<class T>
int Array<T>::get_size() const
{
	return this->size;
}