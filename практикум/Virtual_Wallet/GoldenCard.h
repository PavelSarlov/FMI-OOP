#pragma once

#ifndef GOLDENCARD_H
#define GOLDENCARD_H

#include "Card.h"

class GoldenCard : public Card
{
public:
	GoldenCard();
	GoldenCard(Network, int, int, double, const char*, const char*, const char*);
	GoldenCard(const GoldenCard& other);
	GoldenCard& operator=(const GoldenCard& other);
};

#endif