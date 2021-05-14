#include "Wallet.h"

Wallet::Wallet()
{
	this->cardsCount = 0;
	this->cards = nullptr;
	this->tranHistory = nullptr;
	this->tranHistoryCount = 0;
}
Wallet::Wallet(const Wallet& other)
{
	this->cardsCount = other.cardsCount;
	this->cards = new Card[other.cardsCount];
	for (int i = 0; i < other.cardsCount; i++)
		this->cards[i] = other.cards[i];
	this->tranHistoryCount = other.tranHistoryCount;
	this->tranHistory = new Transaction[other.tranHistoryCount];
	for (int i = 0; i < other.tranHistoryCount; i++)
		this->tranHistory[i] = other.tranHistory[i];
}
Wallet& Wallet::operator=(const Wallet& other)
{
	if (this != &other)
	{
		Wallet::~Wallet();

		this->cardsCount = other.cardsCount;
		this->cards = new Card[other.cardsCount];
		for (int i = 0; i < other.cardsCount; i++)
			this->cards[i] = other.cards[i];
		this->tranHistoryCount = other.tranHistoryCount;
		this->tranHistory = new Transaction[other.tranHistoryCount];
		for (int i = 0; i < other.tranHistoryCount; i++)
			this->tranHistory[i] = other.tranHistory[i];
	}
	return *this;
}
Wallet::~Wallet()
{
	if (this->cards != nullptr)
		delete[] this->cards;
	if (this->tranHistory != nullptr)
		delete[] this->tranHistory;
}

Card& Wallet::getCard(const char* name)
{
	if (name != nullptr)
	{
		for (int i = 0; i < this->cardsCount; i++)
		{
			bool found = true;

			for (int j = 0; name[j] != '\0' || this->cards[i].getOwnerName()[j] != '\0'; j++)
			{
				if (name[j] != this->cards[i].getOwnerName()[j])
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				return this->cards[i];
			}
		}
	}

	std::cout << "\nERROR! No such card found.\n";
	Card card = Card();
	return Card();
}
void Wallet::createCard(CardType type, Network network, int pin, int cvv, double balanceLimit, const char* cardNumber, const char* ownerName, const char* bankName)
{
	if (this->cardsCount < 5)
	{
		Card* temp = new Card[this->cardsCount + 1];
		for (int i = 0; i < this->cardsCount; i++)
		{
			temp[i] = this->cards[i];
		}
		delete[] this->cards;
		this->cards = temp;

		switch (type)
		{
		case STANDARD:
			this->cards[this->cardsCount] = StandardCard(network, pin, cvv, balanceLimit, cardNumber, ownerName, bankName);
			break;
		case GOLDEN:
			this->cards[this->cardsCount] = GoldenCard(network, pin, cvv, balanceLimit, cardNumber, ownerName, bankName);
			break;
		case PLATINUM:
			this->cards[this->cardsCount] = PlatinumCard(network, pin, cvv, balanceLimit, cardNumber, ownerName, bankName);
			break;
		}

		this->cardsCount += 1;
	}
	else
	{
		std::cout << "ERROR! Up to 5 cards per wallet allowed.\n";
	}
}
void Wallet::addFundsToCard(const char* name, double funds)
{
	Card card = getCard(name);

	if (card.getOwnerName() != nullptr)
	{
		if ((card.getBalance() + funds <= card.getBalanceLimit() && card.getBalanceLimit() != 0) || card.getBalanceLimit() == 0)
		{
			if (funds > 0)
			{
				card.balance += funds;
				std::cout << std::setprecision(2) << std::fixed << "\nYou have successfully deposited " << funds << " lv. to your card\n";
			}
			else
			{
				std::cout << "\nERROR! Invalid number of funds.\n";
			}
		}
		else
		{
			std::cout << "\nERROR! You have exceeded the balance limit.\n";
		}
	}
}
void Wallet::payWithCard(const char* name, PaymentInfo& paymentInfo, int pin)
{
	Card card = getCard(name);

	if (card.getOwnerName() != nullptr)
	{
		if (card.getBalance() >= paymentInfo.getItemPrice())
		{
			if (card.authenticatePIN(pin))
			{
				Message message = makePayment(card, paymentInfo);
				std::cout << message.getMessage();
			}
			else
				std::cout << "\nERROR! Invalid PIN.\n";
		}
		else
			std::cout << "\nERROR! Insufficient funds.\n";
	}
}
void Wallet::removeCard(const char* name)
{
	Card card = getCard(name);

	if (card.getOwnerName() != nullptr)
	{
		int counter = 0;
		Card* temp = new Card[this->cardsCount - 1];
		for (int i = 0; i < this->cardsCount; i++)
		{
			for (int j = 0; ; j++)
			{
				if (this->cards[i].getOwnerName()[j] != name[j])
				{
					temp[counter++] = this->cards[i];
					break;
				}
				else if (this->cards[i].getOwnerName()[j] == '\0' && name[j] == '\0')
				{
					break;
				}
			}
			
		}
		delete[] this->cards;
		this->cards = temp;
		this->cardsCount -= 1;
	}
}
Message Wallet::makePayment(Card& card, PaymentInfo& paymentInfo)
{
	if (validatePayment(card))
	{
		Transaction* temp = new Transaction[this->tranHistoryCount + 1];
		for (int i = 0; i < this->tranHistoryCount; i++)
			temp[i] = this->tranHistory[i];
		delete[] this->tranHistory;
		this->tranHistory = temp;
		this->tranHistory[this->tranHistoryCount] = executeTransaction(card, paymentInfo);
		this->tranHistoryCount += 1;

		SuccessMessage message = SuccessMessage("Transaction successful!");
		return message;
	}
	else
	{
		ErrorMessage message = ErrorMessage("ERROR! Transaction unsuccessful.");
		return message;
	}
}
Transaction Wallet::executeTransaction(Card& card, PaymentInfo& paymentInfo)
{
	std::time_t dateAndTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	Transaction newTransaction = Transaction(paymentInfo, dateAndTime);

	card.balance -= paymentInfo.getItemPrice();

	return newTransaction;
}
bool Wallet::validatePayment(const Card& card) const
{
	if (!validateCardNumber(card) || !validateCardCvv(card) || !validateCardExpDate(card))
		return false;
	return true;
}
bool Wallet::validateCardNumber(const Card& card) const
{
	std::cout << "\nEnter card number: ";
	char* cardNumber = new char[1]();
	for (int i = 0; std::cin.peek() != '\n'; i++)
	{
		char* temp = new char[i + 2]();
		for (int j = 0; j < i; j++)
			temp[j] = cardNumber[j];
		delete[] cardNumber;
		cardNumber = temp;
		cardNumber[i] = getchar();
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (card.authenticateCardNumber(cardNumber))
	{
		delete[] cardNumber;
		return true;
	}
	delete[] cardNumber;
	return false;
}
bool Wallet::validateCardCvv(const Card& card) const
{
	std::cout << "\nEnter card CVV: ";

	int cvv = 0;
	std::cin >> cvv;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (card.authenticateCvvNumber(cvv))
		return true;
	return false;
}
bool Wallet::validateCardExpDate(const Card& card) const
{
	std::cout << "\nEnter card expiration date: ";
	
	int month, year;
	std::cin >> month;
	std::cin >> year;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	ExpirationDate expDate = ExpirationDate(MONTH_IN_SECONDS * month + YEAR_IN_SECONDS * year);

	if (card.authenticateExpDate(expDate))
	{
		return true;
	}
	return false;
}
void Wallet::printTransactionHistory() const
{
	std::ofstream tranLog("transactions.txt");

	for (int i = 0; i < this->tranHistoryCount; i++)
	{
		tranLog << "Transaction made on " << this->tranHistory[i].getTimeAndDate();
		tranLog << "Item: " << this->tranHistory[i].getPaymentInfo().getItemName() << std::endl;
		tranLog << "Price: " << this->tranHistory[i].getPaymentInfo().getItemPrice() << " lv." << std::endl << std::endl;
	}

	tranLog.close();
}
void Wallet::printCardsInfo() const
{
	std::cout << "Your cards:" << std::endl << std::endl;
	for (int i = 0; i < this->cardsCount; i++)
	{
		std::cout << i + 1 << ")" << std::endl;
		this->cards[i].printCardInfo();
	}
}

//void Wallet::deleteWallet()
//{
//	delete this;
//}