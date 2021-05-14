#pragma once

class MyString
{
public:
	MyString();
	MyString(const char*);
	~MyString();

	char* getStr() const;

	void print();
	void append(const char);
	friend bool operator==(MyString&, MyString&);
	friend bool operator!=(MyString&, MyString&);
	friend bool operator>(MyString&, MyString&);
	friend bool operator<(MyString&, MyString&);

private:
	char* str;
};