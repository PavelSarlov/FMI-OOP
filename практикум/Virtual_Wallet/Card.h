#pragma once

#ifndef CARD_H
#define CARD_H

#include "HelperFunctions.h"
#include "Message.h"
#include "ExpirationDate.h"

enum Network { VISA, MASTERCARD, MAESTRO, AMERICANEXPRESS, ELECTRON, DISCOVER, INTERLINK };
enum CardType { STANDARD, GOLDEN, PLATINUM };

class Card
{
public:
	Card();
	Card(Network, int, int, double, const char*, const char*, const char*);
	Card(const Card& other);
	Card& operator=(const Card& other);
	~Card();
	friend class Wallet;

	const char* getTypeName() const;
	CardType getCardType() const;
	Network getCardNetwork() const;
	int getCvvNumber() const;
	const char* getCardNumber() const;
	const char* getOwnerName() const;
	const char* getBankName() const;
	ExpirationDate getExpDate() const;
	double getBalance() const;
	double getBalanceLimit() const;

	void printCardInfo() const;

	bool authenticateCvvNumber(int) const;
	bool authenticatePIN(int) const;
	bool authenticateCardNumber(const char*) const;
	bool authenticateExpDate(const ExpirationDate&) const;

protected:
	const char* typeName;
	CardType cardType;
	Network cardNetwork;
	const char* cardNumber;
	const char* ownerName;
	const char* bankName;
	ExpirationDate expDate;
	double balance;
	double balanceLimit;
	int cardPIN;
	int cvvNumber;
};
#endif // !CARD_H