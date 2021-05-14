#include "GoldenCard.h"

GoldenCard::GoldenCard() : Card()
{
	setStringValues(this->typeName, "GOLDEN");
	this->cardType = GOLDEN;
	this->expDate = ExpirationDate(YEAR_IN_SECONDS * 4);
}
GoldenCard::GoldenCard(Network network, int pin, int cvv, double balanceLimit, const char* cardNumber, const char* ownerName, const char* bankName) : Card(network, pin, cvv, balanceLimit, cardNumber, ownerName, bankName)
{
	setStringValues(this->typeName, "GOLDEN");
	this->cardType = GOLDEN;
	this->expDate = ExpirationDate(YEAR_IN_SECONDS * 4);
}
GoldenCard::GoldenCard(const GoldenCard& other) : Card(other)
{
	setStringValues(this->typeName, other.typeName);
	this->cardType = other.cardType;
}
GoldenCard& GoldenCard::operator=(const GoldenCard& other)
{
	if (this != &other)
	{
		setStringValues(this->typeName, other.typeName);
		this->cardType = other.cardType;
		Card::operator=(other);
	}
	return *this;
}