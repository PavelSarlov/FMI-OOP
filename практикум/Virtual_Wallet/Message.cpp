#include "Message.h"

Message::Message()
{
	this->type = STATEMENT;
	this->message = nullptr;	
}
Message::Message(const char* message)
{
	this->type = STATEMENT;
	this->message = nullptr;
	setStringValues(this->message, message);
}
Message::Message(const Message& other)
{
	this->type = other.type;
	this->message = nullptr;
	setStringValues(this->message, other.message);
}
Message& Message::operator=(const Message& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->message = nullptr;
		setStringValues(this->message, other.message);
	}
	return *this;
}
Message::~Message()
{
	if (this->message != nullptr)
		delete[] this->message;
}

const char* Message::getMessage() const
{
	return this->message;
}