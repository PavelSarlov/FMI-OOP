#include <iostream>
#include <Windows.h>
#include "Store.h"
#include "AccountDatabase.h"
#include "Appliance.h"
#include "Clothing.h"
#include "Electronic.h"
#include "Home.h"
#include "Software.h"

int main()
{
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, 1000, 800, TRUE);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 120, 9001 };
	SetConsoleScreenBufferSize(hConsole, coord);

	AccountDatabase database;
	Store store;
	bool exitStore = false;
	bool logged = false;
	
	Clothing product1 = Clothing(39.99, "Dress", "LC Waikiki", "blue", "XL");
	Clothing product2 = Clothing(69.99, "Boots", "LC Waikiki", "black", "46");
	Clothing product3 = Clothing(15.59, "T-Shirt", "LC Waikiki", "red", "XXL");
					   
	Electronic product4 = Electronic(1999.99, "Laptop", "Apple", "MacOS", "MacBook Air");
	Electronic product5 = Electronic(1399.99, "Phone", "Apple", "iOS", "Iphone 10");
	Electronic product6 = Electronic(1599.99, "Desktop", "Apple", "MacOS", "iMac Pro");
					   
	Home product7 = Home(25.99, "Life Size Mirror", "HomeDepot", "wood and glass", 250, 100, 500);
	Home product8 = Home(229.99, "Office Chair", "HomeDepot", "metal", 2, 100, 150);
	Home product9 = Home(79.99, "Mattress", "HomeDepot", "foam, cotton and wool", 200, 200, 30);
			
	Appliance product10 = Appliance(559.00, "Dishwasher", "HomeDepot", 500, 100, 100, 100);
	Appliance product11 = Appliance(599.00, "Microwave Oven", "HomeDepot", 1200, 50, 40, 30);
	Appliance product12 = Appliance(329.00, "Washing Machine", "HomeDepot", 500, 100, 100, 100);
					 
	Software product13 = Software(195.99, "Windows 10 Pro", "Microsoft", "10 Pro");
	Software product14 = Software(49.80, "TurboTax", "Intuit", "Deluxe");
	Software product15 = Software(19.99, "McAfee", "McAfee", "Free");

	store.addProduct(25, &product1);
	store.addProduct(25, &product2);
	store.addProduct(25, &product3);
	store.addProduct(25, &product4);
	store.addProduct(25, &product5);
	store.addProduct(25, &product6);
	store.addProduct(25, &product7);
	store.addProduct(25, &product8);
	store.addProduct(25, &product9);
	store.addProduct(25, &product10);
	store.addProduct(25, &product11);
	store.addProduct(25, &product12);
	store.addProduct(25, &product13);
	store.addProduct(25, &product14);
	store.addProduct(25, &product15);

	while (!exitStore)
	{
		User* user = database.login(exitStore, logged);

		while (logged && !exitStore)
		{
			store.storeLogic(user, exitStore, logged);
		}
	}

	return 0;
}