#pragma once

#ifndef SUCCESSMESSAGE_H
#define SUCCESSMESSAGE_H

#include "Message.h"

class SuccessMessage : public Message
{
public:
	SuccessMessage() : Message(){}
	SuccessMessage(const char*);
	SuccessMessage(const SuccessMessage& other);
	SuccessMessage& operator=(const SuccessMessage& other);
};

#endif // !SUCCESSMESSAGE_H


