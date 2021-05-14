#pragma once

#ifndef STANDARDCARD_H
#define STANDARDCARD_H

#include "Card.h"

class StandardCard : public Card
{
public:
	StandardCard();
	StandardCard(Network, int, int, double, const char*, const char*, const char*);
	StandardCard(const StandardCard& other);
	StandardCard& operator=(const StandardCard& other);
};

#endif // !STANDARDCARD_H
