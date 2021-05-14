#include "Store.h"
#include "Appliance.h"
#include "Clothing.h"
#include "Electronic.h"
#include "Home.h"
#include "Software.h"

// Constructor/Destructor
Store::Store()
{
	this->filterProductsList = DEFAULT;
}
Store::Store(const Store& other)
{
	*this = other;
}
Store& Store::operator=(const Store& other)
{
	if (this != &other)
	{
		this->products = other.products;
		this->filterProductsList = other.filterProductsList;
	}
	return *this;
}
Store::~Store()
{
	if (!this->products.empty())
	{
		for (auto& product : this->products)
			delete product.first;
		this->products.clear();
	}
}

void Store::setFilterProductsList(Category filter)
{
	this->filterProductsList = filter;
}

// Functions
void Store::showStoreInfo()
{
	int screenWidth = 120;
	int spacing = 15;

	std::cout << "*************************************************" <<" Products in store: " << "**************************************************\n\n";

	std::cout << "Filter: ";
	switch (this->filterProductsList)
	{
	case 0:
		std::cout << "Software" << std::endl;
		break;
	case 1:
		std::cout << "Home" << std::endl;
		break;
	case 2:
		std::cout << "Clothing" << std::endl;
		break;
	case 3:
		std::cout << "Electronics" << std::endl;
		break;
	case 4:
		std::cout << "Appliances" << std::endl;
		break;
	default:
		std::cout << "None" << std::endl;
		break;
	}

	std::cout << "\n";
	std::cout.precision(2);
	std::cout << ' ' << std::left << std::setw(spacing + 4) << "ID:" << std::setw(spacing + 6) << "Name:" << std::setw(spacing + 10) << "In stock:" << std::setw(spacing + 21) << "Price per item (lv.):" << "Category:\n";
	
	for (int j = 0; j < screenWidth; j++)
	{
		std::cout << '-';
	}

	if (!this->products.empty())
	{
		for (auto& product : this->products)
		{
			if (this->filterProductsList == DEFAULT)
			{
				std::cout << ' ' << std::fixed << std::left << std::setw(spacing + 4) << product.first->getId() << std::setw(spacing + 6) << product.first->getName() << std::setw(spacing + 10) << product.second << std::setw(spacing + 21) << product.first->getPrice() << product.first->getCategoryName() << "(" << product.first->getCategory() << ")\n";

				for (int j = 0; j < screenWidth; j++)
				{
					std::cout << '-';
				}
			}
			else
			{
				if (product.first->getCategory() == this->filterProductsList)
				{
					std::cout << ' ' << std::fixed << std::left << std::setw(spacing + 4) << product.first->getId() << std::setw(spacing + 6) << product.first->getName() << std::setw(spacing + 10) << product.second << std::setw(spacing + 21) << product.first->getPrice() << product.first->getCategoryName() << "(" << product.first->getCategory() << ")\n";

					for (int j = 0; j < screenWidth; j++)
					{
						std::cout << '-';
					}
				}
			}
		}
	}

	std::cout << "\n\n";
	for (int j = 0; j < screenWidth; j++)
	{
		std::cout << '_';
	}
	std::cout << "\n\n\n";
}
void Store::addProduct(int quantity, const Product* _product)
{
	if (_product == nullptr)
		return;

	if (quantity < 0)
	{
		std::cout << "ERROR! Invalid quantity.\n";
		return;
	}

	if (!this->products.empty())
	{
		for (auto& product : this->products)
		{
			if (product.first->getId() == _product->getId())
			{
				product.second += quantity;
				return;
			}
		}
	}

	switch (_product->getCategory())
	{
	case APPLIANCES:
		this->products.insert(std::pair<Product*, int>(new Appliance(*(dynamic_cast<const Appliance*>(_product))), quantity));
		break;
	case CLOTHING:
		this->products.insert(std::pair<Product*, int>(new Clothing(*(dynamic_cast<const Clothing*>(_product))), quantity));
		break;
	case HOME:
		this->products.insert(std::pair<Product*, int>(new Home(*(dynamic_cast<const Home*>(_product))), quantity));
		break;
	case ELECTRONICS:
		this->products.insert(std::pair<Product*, int>(new Electronic(*(dynamic_cast<const Electronic*>(_product))), quantity));
		break;
	case SOFTWARE:
		this->products.insert(std::pair<Product*, int>(new Software(*(dynamic_cast<const Software*>(_product))), quantity));
		break;
	}	
}
void Store::removeProduct(int id)
{
	if (!this->products.empty())
	{
		for (auto& product : this->products)
		{
			if (product.first->getId() != id)
			{
				this->products.erase(product.first);
				return;
			}
		}
	}

	std::cout << "ERROR! Product with ID provided doesn't exist in the store." << std::endl;
}
void Store::storeInterface(User* user)
{
	system("cls");

	std::cout.precision(2);
	std::cout.right;

	// Instructions
	std::cout << "List of actions:\n";
	std::cout << '\t' << "-a ID QUANTITY (adds a product with given positive integer id and positive integer quantity to the cart)\n";
	std::cout << '\t' << "-r ID (removes a product with given positive integer id from the cart)\n";
	std::cout << '\t' << "-e (empties the cart)\n";
	std::cout << '\t' << "-b (proceeds to buying the items in the cart)\n";
	std::cout << '\t' << "-q (exits the store)\n";
	std::cout << '\t' << "-f FUNDS (adds positive number funds to your account)\n";
	std::cout << '\t' << "-l (logs you out of the current account)\n";
	std::cout << '\t' << "-s CATEGORY (filters the items in the store by given positive integer and its corresponding category)\n";
	std::cout << '\t' << "-d (removes the category filter)\n";
	std::cout << '\t' << "-i ID (shows product description)\n";

	std::cout << "\n\n";

	std::cout << std::fixed << "User: " << user->getUsername() << ", Balance: " << user->getBalance() << " lv.";

	std::cout << "\n\n\n";

	showStoreInfo();
	user->getCart().showCartInfo();
}
void Store::storeLogic(User* user, bool& exitStore, bool& logged)
{
	storeInterface(user);

	while (true)
	{
		std::cout << "\nScroll to the top for instructions.\n";
		std::cout << "\nInput action: ";

		if (std::cin.peek() != '-')
		{
			std::cout << "\nERROR! Please read the list of actions and follow the syntaxis.";
			Sleep(2000);
		}
		else
		{
			getchar();

			int id = 0;
			int quantity = 0;
			double funds = 0;
			int filter = 0;

			switch (std::cin.peek())
			{
			case 'a':
				getchar();

				std::cin >> id;

				if (std::cin.fail() || id <= 0)
				{
					std::cout << "\nERROR! Invalid ID." << std::endl;
					Sleep(2000);
					break;
				}

				std::cin >> quantity;

				if (std::cin.fail() || quantity <= 0)
				{
					std::cout << "\nERROR! Invalid quantity." << std::endl;
					Sleep(2000);
					break;
				}

				if (!this->products.empty())
				{
					for (const auto& product : this->products)
					{
						if (this->products.find(product.first) == this->products.end() && product.first->getId() != id)
						{
							std::cout << "\nERROR! Product with ID provided doesn't exist in the store." << std::endl;
							Sleep(2000);
						}
						else if (product.first->getId() == id)
						{
							user->getCart().addItem(product.second, quantity, product.first);
							break;
						}
					}
				}
				else
				{
					std::cout << "\nERROR! Product with ID provided doesn't exist in the store." << std::endl;
					Sleep(2000);
				}

				break;
			case 'r':
				getchar();

				std::cin >> id;

				if (std::cin.fail() || id <= 0)
				{
					std::cout << "\nERROR! Invalid ID." << std::endl;
					Sleep(2000);
					break;
				}
				else
				{
					user->getCart().removeItem(id);
				}

				break;
			case 'e':
				getchar();
				user->getCart().empty();
				break;
			case 'b':
				getchar();
				if (user->makePurchase())
				{
					for (const auto& item : user->getCart().getItems())
					{
						for (auto& product : this->products)
						{
							if (item.first->getId() == product.first->getId())
								product.second -= item.second;
						}
					}
					user->getCart().empty();
				}
				break;
			case 'q':
				getchar();
				exitStore = true;
				system("cls");
				std::cout << "Exiting..." << std::endl;
				Sleep(2000);
				break;
			case 'f':
				getchar();

				std::cin >> funds;

				if (std::cin.fail() || !user->addFunds(funds))
				{
					std::cout << "\nERROR! Please enter a valid number.";
					Sleep(2000);
					break;
				}

				std::cout.precision(2);
				std::cout << std::fixed << "\nYou successfully added " << funds << " lv. to your account.";
				Sleep(2000);
				
				break;
			case 'l':
				getchar();
				setFilterProductsList(DEFAULT);
				system("cls");
				std::cout << "Logging out...";
				logged = false;
				Sleep(2000);
				break;
			case 's':
				getchar();

				std::cin >> filter;

				if (std::cin.fail() || filter < 0 || filter >= DEFAULT)
				{
					std::cout << "\nERROR! Invalid category." << std::endl;
					Sleep(2000);
					break;
				}

				setFilterProductsList((Category)filter);

				break;
			case 'd':
				getchar();
				setFilterProductsList(DEFAULT);
				break;
			case 'i':
				getchar();

				std::cin >> id;

				if (std::cin.fail() || id <= 0)
				{
					std::cout << "\nERROR! Invalid ID." << std::endl;
					Sleep(2000);
					break;
				}

				if (!this->products.empty())
				{
					for (auto& product : this->products)
					{
						if (this->products.find(product.first) == this->products.end() && product.first->getId() != id)
						{
							std::cout << "\nERROR! Product with ID provided doesn't exist in the store." << std::endl;
							Sleep(2000);
						}
						else if (product.first->getId() == id)
						{
							system("cls");
							product.first->print_description();
							system("pause");
							break;
						}
					}
				}
				else
				{
					std::cout << "\nERROR! Product with ID provided doesn't exist in the store." << std::endl;
					Sleep(2000);
				}

				break;
			default:
				std::cout << "\nERROR! Please read the list of actions and follow the syntaxis." << std::endl;
				Sleep(2000);
				break;
			}
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
}