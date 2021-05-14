#include "Card.h"

Card::Card()
{
	this->typeName = nullptr;
	this->cvvNumber = 0;
	this->balanceLimit = 0;
	this->cardNumber = nullptr;
	this->ownerName = nullptr;
	this->bankName = nullptr;
	this->expDate = ExpirationDate();
	this->balance = 0;
	this->cardPIN = 0;
}
Card::Card(Network network, int pin, int cvv, double balanceLimit, const char* cardNumber, const char* ownerName, const char* bankName)
{
	this->typeName = nullptr;
	this->cardNetwork = network;
	this->cvvNumber = cvv;
	this->balanceLimit = balanceLimit;
	this->cardNumber = nullptr;
	this->ownerName = nullptr;
	this->bankName = nullptr;
	setStringValues(this->cardNumber, cardNumber);
	setStringValues(this->ownerName, ownerName);
	setStringValues(this->bankName, bankName);
	this->expDate = ExpirationDate();
	this->balance = 0;
	this->cardPIN = pin;
}
Card::Card(const Card& other)
{
	this->cardNetwork = other.cardNetwork;
	this->cvvNumber = other.cvvNumber;
	this->balanceLimit = other.balanceLimit;
	setStringValues(this->cardNumber, other.cardNumber);
	setStringValues(this->ownerName, other.ownerName);
	setStringValues(this->bankName, other.bankName);
	this->expDate = other.expDate;
	this->balance = 0;
	this->cardPIN = other.cardPIN;
}
Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		this->cardNetwork = other.cardNetwork;
		this->cvvNumber = other.cvvNumber;
		this->balanceLimit = other.balanceLimit;
		setStringValues(this->cardNumber, other.cardNumber);
		setStringValues(this->ownerName, other.ownerName);
		setStringValues(this->bankName, other.bankName);
		this->expDate = other.expDate;
		this->balance = 0;
		this->cardPIN = other.cardPIN;
	}
	return *this;
}
Card::~Card()
{
	if (this->ownerName != nullptr)
		delete[] this->ownerName;
	if (this->cardNumber != nullptr)
		delete[] this->cardNumber;
	if (this->bankName != nullptr)
		delete[] this->bankName;
	if (this->typeName != nullptr)
		delete[] this->typeName;
}

const char* Card::getTypeName() const
{
	return this->typeName;
}
CardType Card::getCardType() const
{
	return this->cardType;
}
Network Card::getCardNetwork() const
{
	return this->cardNetwork;
}
int Card::getCvvNumber() const
{
	return this->cvvNumber;
}
const char* Card::getCardNumber() const
{
	return this->cardNumber;
}
const char* Card::getOwnerName() const
{
	return this->ownerName;
}
const char* Card::getBankName() const
{
	return this->bankName;
}
ExpirationDate Card::getExpDate() const
{
	return this->expDate;
}
double Card::getBalance() const
{
	return this->balance;
}
double Card::getBalanceLimit() const
{
	return this->balanceLimit;
}

void Card::printCardInfo() const
{
	std::cout << "Owner: "; printString(this->ownerName); std::cout << std::endl;
	std::cout << "Card number: "; printString(this->cardNumber); std::cout << std::endl;
	std::cout << "CVV: " << this->cvvNumber << std::endl;
	std::cout << "Bank: "; printString(this->bankName); std::cout << std::endl;
	std::cout << "Expiration date: "<< this->expDate << std::endl;
	std::cout << "Card balance: "<< this->balance << std::endl;

	std::cout << std::endl;
}

bool Card::authenticatePIN(int givenPIN) const
{
	if (this->cardPIN != givenPIN)
		return false;
	return true;
}
bool Card::authenticateCvvNumber(int givenCvv) const
{
	if (this->cvvNumber != givenCvv)
		return false;
	return true;
}
bool Card::authenticateCardNumber(const char* givenCardNumber) const
{
	if (givenCardNumber == nullptr)
		return false;

	int length = -1;
	do
	{
		length++;
		if (this->cardNumber[length] != givenCardNumber[length])
			return false;
	} while (givenCardNumber[length] != '\0');

	return true;
}
bool Card::authenticateExpDate(const ExpirationDate& givenExpDate) const
{
	if (this->expDate.getMonth() != givenExpDate.getMonth() || this->expDate.getYear() != givenExpDate.getYear())
		return false;

	return true;
}