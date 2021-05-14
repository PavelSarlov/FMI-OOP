#include "ErrorMessage.h"

ErrorMessage::ErrorMessage(const char* message) : Message(message)
{
	this->type = ERROR;
}
ErrorMessage::ErrorMessage(const ErrorMessage& other) : Message(other)
{

}
ErrorMessage& ErrorMessage::operator=(const ErrorMessage& other)
{
	Message::operator=(other);
	return *this;
}