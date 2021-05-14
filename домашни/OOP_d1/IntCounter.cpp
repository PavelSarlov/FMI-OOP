#include "IntCounter.h"

IntCounter::IntCounter(int* variable)
{
	this->counter = new int(1);
	this->variable = variable;
}
IntCounter::IntCounter(IntCounter const& intCounter)
{
	this->variable = intCounter.variable;
	this->counter = intCounter.counter;
	*this->counter += 1;
}
IntCounter::~IntCounter()
{
	*this->counter -= 1;
	if (*this->counter == 0)
	{
		delete this->variable;
		delete this->counter;
	}
}

int IntCounter::getCounter() const
{
	return *this->counter;
}
int IntCounter::getVariable() const
{
	return *this->variable;
}