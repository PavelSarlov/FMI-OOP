#include "StandardCard.h"

StandardCard::StandardCard() : Card()
{
	setStringValues(this->typeName, "STANDARD");
	this->cardType = STANDARD;
	this->expDate = ExpirationDate(YEAR_IN_SECONDS * 3);
}
StandardCard::StandardCard(Network network, int pin, int cvv, double balanceLimit, const char* cardNumber, const char* ownerName, const char* bankName) : Card(network, pin, cvv, balanceLimit, cardNumber, ownerName, bankName)
{
	setStringValues(this->typeName, "STANDARD");
	this->cardType = STANDARD;
	this->expDate = ExpirationDate(YEAR_IN_SECONDS * 3);
}
StandardCard::StandardCard(const StandardCard& other) : Card(other)
{
	setStringValues(this->typeName, other.typeName);
	this->cardType = other.cardType;
}
StandardCard& StandardCard::operator=(const StandardCard& other)
{
	if (this != &other)
	{
		setStringValues(this->typeName, other.typeName);
		this->cardType = other.cardType;
		Card::operator=(other);
	}
	return *this;
}