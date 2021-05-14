#pragma once

#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <fstream>
#include "Transaction.h"
#include "PaymentInfo.h"
#include "StandardCard.h"
#include "GoldenCard.h"
#include "PlatinumCard.h"
#include "ErrorMessage.h"
#include "SuccessMessage.h"

const int MAXIMUM_CARDS = 5;

class Wallet
{
public:
	Wallet();
	Wallet(const Wallet& other);
	Wallet& operator=(const Wallet& other);
	~Wallet();

	Card& getCard(const char*);
	void createCard(CardType, Network, int, int, double, const char*, const char*, const char*);
	void addFundsToCard(const char*, double);
	void payWithCard(const char*, PaymentInfo&, int);
	void removeCard(const char*);
	void printTransactionHistory() const;
	void printCardsInfo() const;

	/*void deleteWallet();*/

private:
	Message makePayment(Card&, PaymentInfo&);
	Transaction executeTransaction(Card&, PaymentInfo&);
	bool validatePayment(const Card&) const;
	bool validateCardNumber(const Card&) const;
	bool validateCardCvv(const Card&) const;
	bool validateCardExpDate(const Card&) const;

	int cardsCount;
	Card* cards;
	Transaction* tranHistory;
	int tranHistoryCount;
};
#endif // !WALLET_H