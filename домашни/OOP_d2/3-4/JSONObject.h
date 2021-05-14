#pragma once

#ifndef JSONOBJECT_H
#define JSONOBJECT_H

template <class T>
class JSONObject
{
public:
	JSONObject();
	JSONObject(const char* key, T* value);
	JSONObject(const JSONObject& other);
	JSONObject& operator=(const JSONObject& other);
	~JSONObject();

	bool validateKey(const char* givenKey) const;
	const char* getKey() const;
	const T* getValue() const;

private:
	char* key;
	T* value;
};
#endif



#pragma warning(push)
#pragma warning(disable : 4996)

template <class T>
JSONObject<T>::JSONObject()
{
	this->key = nullptr;
	this->value = nullptr;
}

template <class T>
JSONObject<T>::JSONObject(const char* key, T* value)
{
	if (key != nullptr)
	{
		this->key = new char[strlen(key) + 1]();
		strcpy(this->key, key);
	}
	else
		this->key = new char[11]("DEFAULTKEY");

	this->value = value;
}

template <class T>
JSONObject<T>::JSONObject(const JSONObject& other)
{
	if (other.key != nullptr)
	{
		this->key = new char[strlen(other.key) + 1]();
		strcpy(this->key, other.key);
	}
	else
		this->key = new char[11]("DEFAULTKEY");

	this->value = new T(*other.value);
}

template <class T>
JSONObject<T>& JSONObject<T>::operator=(const JSONObject& other)
{
	if (this != &other)
	{
		if (this->key != nullptr)
			delete[] this->key;
		if (this->value != nullptr)
			delete this->value;

		if (other.key != nullptr)
		{
			this->key = new char[strlen(other.key) + 1]();
			strcpy(this->key, other.key);
		}
		else
			this->key = new char[11]("DEFAULTKEY");

		this->value = new T(*other.value);
	}
	return *this;
}

template <class T>
JSONObject<T>::~JSONObject()
{
	if (this->key != nullptr)
		delete[] this->key;
	if (this->value != nullptr)
		delete this->value;
}

template <class T>
bool JSONObject<T>::validateKey(const char* givenKey) const
{
	if (givenKey != nullptr)
	{
		for (int j = 0; key[j] != '\0' && this->key[j] != '\0'; j++)
		{
			if (this->key[j] != givenKey[j])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

template<class T>
const T* JSONObject<T>::getValue() const
{
	return this->value;
}

template<class T>
const char* JSONObject<T>::getKey() const
{
	return this->key;
}

#pragma warning (pop)