#include "Cart.h"
#include "Appliance.h"
#include "Clothing.h"
#include "Electronic.h"
#include "Home.h"
#include "Software.h"

// Constructor/Destructor
Cart::Cart()
{
	this->totalCost = 0;
}
Cart::Cart(const Cart& other)
{
	*this = other;
}
Cart& Cart::operator=(const Cart& other)
{
	if (this != &other)
	{
		this->items = other.items;
		this->totalCost = other.totalCost;
	}
	return *this;
}
Cart::~Cart()
{
	if (!this->items.empty())
	{
		for (auto& item : this->items)
			delete item.first;
		this->items.clear();
	}
}

// Getters
double Cart::getTotalCost() const
{
	return this->totalCost;
}
std::map<Product*, int> Cart::getItems() const
{
	return this->items;
}

// Functions
void Cart::addItem(int inStock, int quantity, const Product* product)
{
	if (quantity > inStock)
	{
		std::cout << "\nERROR! The quantity is higher than the in-stock number.";
		Sleep(2000);
		return;
	}

	if (!this->items.empty())
	{
		for (auto& item : this->items)
		{
			if (item.first->getId() == product->getId())
			{
				if (quantity + item.second > inStock)
				{
					std::cout << "\nERROR! The quantity is higher than the in-stock number.";
					Sleep(2000);
				}
				else
				{
					item.second += quantity;
					this->totalCost = getTotalCost() + (quantity * product->getPrice());
				}
				return;
			}
		}
	}

	switch (product->getCategory())
	{
	case APPLIANCES:
		this->items.insert(std::pair<Product*, int>(new Appliance(*(dynamic_cast<const Appliance*>(product))), quantity));
		break;
	case CLOTHING:
		this->items.insert(std::pair<Product*, int>(new Clothing(*(dynamic_cast<const Clothing*>(product))), quantity));
		break;
	case HOME:
		this->items.insert(std::pair<Product*, int>(new Home(*(dynamic_cast<const Home*>(product))), quantity));
		break;
	case ELECTRONICS:
		this->items.insert(std::pair<Product*, int>(new Electronic(*(dynamic_cast<const Electronic*>(product))), quantity));
		break;
	case SOFTWARE:
		this->items.insert(std::pair<Product*, int>(new Software(*(dynamic_cast<const Software*>(product))), quantity));
		break;
	}
	this->totalCost = getTotalCost() + (quantity * product->getPrice());
}
void Cart::removeItem(int id)
{
	if (!this->items.empty())
	{
		for (auto& item : this->items)
		{
			if (item.first->getId() == id)
			{
				this->totalCost -= item.second * item.first->getPrice();
				delete item.first;
				this->items.erase(item.first);
				return;
			}
		}
	}

	std::cout << "\nERROR! Item with ID provided doesn't exist in the cart." << std::endl;
	Sleep(2000);
}
void Cart::empty()
{
	if (!this->items.empty())
	{
		for (auto& item : this->items)
			delete item.first;
		this->items.clear();
	}
	this->totalCost = 0;
}
void Cart::showCartInfo() const
{
	int screenWidth = 120;
	int spacing = 15;

	std::cout << "****************************************************" << " Items in cart: " << "**************************************************\n\n";

	std::cout << "Cart Subtotal (" << std::setw(0) << this->items.size() << " items): "<< getTotalCost() << " lv.\n\n";
	std::cout.precision(2);
	std::cout << ' ' << std::left << std::setw(spacing + 4) << "ID:" << std::setw(spacing + 6) << "Name:" << std::setw(spacing + 9) << "In cart:" << std::setw(spacing + 21) << "Price per item (lv.):" << "Category:\n";

	for (int j = 0; j < screenWidth; j++)
	{
		std::cout << '-';
	}

	if (!this->items.empty())
	{
		for (auto& item : this->items)
		{
			std::cout << ' ' << std::fixed << std::left << std::setw(spacing + 4) << item.first->getId() << std::setw(spacing + 6) << item.first->getName() << std::setw(spacing + 9) << item.second << std::setw(spacing + 21) << item.first->getPrice() << item.first->getCategoryName() << "(" << item.first->getCategory() << ")\n";

			for (int j = 0; j < screenWidth; j++)
			{
				std::cout << '-';
			}
		}
	}
	
	std::cout << "\n";
	for (int j = 0; j < screenWidth; j++)
	{
		std::cout << '_';
	}
	std::cout << "\n\n";
}
void Cart::showPurchaseInfo() const
{
	system("cls");

	std::cout << "You bought the following items:\n" << std::endl;

	if (!this->items.empty())
	{
		for (auto& item : this->items)
		{
			std::cout << item.second << "x " << item.first->getName() << ", Price per item: " << item.first->getPrice() << " lv., " << "All: " << item.first->getPrice() * item.second << " lv.\n";
		}
	}

	std::cout << "\nTotal = " << getTotalCost() << " lv." << std::endl;
	std::cout << "\nThank you for shopping with us!" << std::endl;

	system("pause");
}
bool Cart::confirmItems() const
{
	if (this->items.size() == 0)
		return false;
	return true;
}