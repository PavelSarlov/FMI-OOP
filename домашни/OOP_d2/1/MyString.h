#pragma once

#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <iostream>

class MyString {
private:
    char* content;

public:
    MyString();
    MyString(const char* input);

    MyString(const MyString& from);

    MyString& operator=(const MyString& from);

    ~MyString();

    void append(char to_append);
    void print();

    friend std::ostream& operator<<(std::ostream& out, const MyString& myStr);
    friend std::istream& operator>>(std::istream& in, MyString& myStr);
};
#endif