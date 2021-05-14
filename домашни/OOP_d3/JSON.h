#pragma once

#ifndef JSON_H
#define JSON_H

template <class T>
class JSON
{
public:
	JSON() {};

	virtual JSON<T>* operator[] (const int& pos) const { throw - 1; }
	virtual void insert(const char* key, T value) { throw - 1; }
	virtual void insert(const JSON<T>* arr) { throw - 1; }
	virtual void remove(unsigned int index) { throw - 1; }
	virtual bool remove(const char* key) { throw - 1; }
	virtual T get_value(const char* key) const { throw - 1; }
	virtual const char* get_key() const { throw - 1; }
	virtual void set_key(const char* key) { throw - 1; }
	virtual void set_value(T value) { throw - 1; }
	virtual T get_value() const { throw - 1; }
	virtual int get_size() const { throw - 1; }
};

#endif