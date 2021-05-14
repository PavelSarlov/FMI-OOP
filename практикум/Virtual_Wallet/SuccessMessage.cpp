#include "SuccessMessage.h"

SuccessMessage::SuccessMessage(const char* message) : Message(message)
{
	this->type = SUCCESS;
}
SuccessMessage::SuccessMessage(const SuccessMessage& other) : Message(other)
{
	
}
SuccessMessage& SuccessMessage::operator=(const SuccessMessage& other)
{
	Message::operator=(other);
	return *this;
}