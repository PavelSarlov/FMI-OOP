#pragma once

#ifndef MESSAGE_H
#define MESSAGE_H

#include "HelperFunctions.h"

enum MessageType {STATEMENT, ERROR, SUCCESS};

class Message
{
public:
	Message();
	Message(const char*);
	Message(const Message& other);
	Message& operator=(const Message& other);
	~Message();

	const char* getMessage() const;

protected:
	const char* message;
	MessageType type;
};
#endif // !MESSAGE_H
