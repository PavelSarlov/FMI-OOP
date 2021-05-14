#pragma once

#ifndef PLATINUMCARD_H
#define PLATINUMCARD_H

#include "Card.h"

class PlatinumCard : public Card
{
public:
	PlatinumCard();
	PlatinumCard(Network, int, int, double, const char*, const char*, const char*);
	PlatinumCard(const PlatinumCard& other);
	PlatinumCard& operator=(const PlatinumCard& other);
};
#endif