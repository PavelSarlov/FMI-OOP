#include "PlatinumCard.h"

PlatinumCard::PlatinumCard() : Card()
{
	setStringValues(this->typeName, "PLATINUM");
	this->cardType = PLATINUM;
	this->expDate = ExpirationDate(YEAR_IN_SECONDS * 4);
}
PlatinumCard::PlatinumCard(Network network, int pin, int cvv, double balanceLimit, const char* cardNumber, const char* ownerName, const char* bankName) : Card(network, pin, cvv, balanceLimit, cardNumber, ownerName, bankName)
{
	setStringValues(this->typeName, "PLATINUM");
	this->cardType = PLATINUM;
	this->expDate = ExpirationDate(YEAR_IN_SECONDS * 4);
}
PlatinumCard::PlatinumCard(const PlatinumCard& other) : Card(other)
{
	setStringValues(this->typeName, other.typeName);
	this->cardType = other.cardType;
}
PlatinumCard& PlatinumCard::operator=(const PlatinumCard& other)
{
	if (this != &other)
	{
		setStringValues(this->typeName, other.typeName);
		this->cardType = other.cardType;
		Card::operator=(other);
	}
	return *this;
}