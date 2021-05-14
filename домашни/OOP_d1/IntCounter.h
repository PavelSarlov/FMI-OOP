#pragma once

class IntCounter
{
public:
	IntCounter(int*);
	IntCounter(IntCounter const&);
	~IntCounter();

	int getCounter() const;
	int getVariable() const;

private:
	int* counter;
	int* variable;
};