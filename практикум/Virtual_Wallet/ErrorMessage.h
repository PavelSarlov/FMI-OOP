#pragma once

#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include "Message.h"

class ErrorMessage : public Message
{
public:
	ErrorMessage(const char*);
	ErrorMessage(const ErrorMessage& other);
	ErrorMessage& operator=(const ErrorMessage& other);
};

#endif