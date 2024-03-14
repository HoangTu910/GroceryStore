#include "Option.h"

Inventory inv;

void Option::UserOption::userAccountMenu()
{
	system("cls");
	Global global;
	global.setColor(7);
	LoginSystem login;
	this->initMenuColor = { 7, 7, 7, 7 };
	this->counter = 2;
	int width = 45;
	int height = 10;
	int top = 7;
	int left = global.leftCenter(width);
	bool isChosen = false;
	global.drawRectangle(left, top, width, height);
	string userLabel = "1. Change Password ";
	string customerLabel = "3. Logout";
	string storeLabel = "USER OPTION";
	while (!isChosen) {
		global.setColor(7);
		global.gotoXY(global.leftCenter(storeLabel.length() - 1), 3);
		cout << storeLabel;
		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 3);
		global.setColor(this->initMenuColor[0]);
		cout << userLabel;

		global.gotoXY(global.leftCenter(userLabel.length() - 1), top + 4);
		global.setColor(this->initMenuColor[1]);
		cout << "2. User Information";

		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 5);
		global.setColor(this->initMenuColor[2]);
		cout << customerLabel;

		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 7);
		global.setColor(this->initMenuColor[3]);
		cout << "Exit";

		this->key = _getch();
		if (this->key == 'w' && (this->counter >= 2 && this->counter <= 4)) {
			this->counter--;
		}

		if (this->key == 's' && (this->counter >= 1 && this->counter <= 3)) {
			this->counter++;
		}

		if (this->key == '\r') {
			switch (this->counter) {
			case 1: this->option = "changepass"; login.configLogin();  isChosen = true; break;
			case 2: this->option = "info"; login.showUserInfo(); isChosen = true; break;
			case 3: this->option = "logout"; global.generateLogin(); isChosen = true; break;
			case 4: cout << "Exit "; global.generateMenu(); isChosen = true; break;
			}
		}

		this->initMenuColor[0] = 7;
		this->initMenuColor[1] = 7;
		this->initMenuColor[2] = 7;
		this->initMenuColor[3] = 7;

		switch (this->counter) {
		case 1: this->initMenuColor[0] = 3; break;
		case 2: this->initMenuColor[1] = 3; break;
		case 3: this->initMenuColor[2] = 3; break;
		case 4: this->initMenuColor[3] = 3; break;
		}
	}
}

void Option::StoreOption::storeMenu()
{
	system("cls");
	Global global;
	LoginSystem login;
	Store store;
	global.setColor(7);
	this->initMenuColor = { 7, 7, 7, 7 };
	this->counter = 2;
	int width = 45;
	int height = 7;
	int top = 7;
	int left = global.leftCenter(width);
	bool isChosen = false;
	global.drawRectangle(left, top, width, height);
	string userLabel = "1. Change Password ";
	string storeLabel = "STORE OPTION";
	while (!isChosen) {
		global.setColor(7);
		global.gotoXY(global.leftCenter(storeLabel.length() - 1), 3);
		cout << storeLabel;
		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 2);
		global.setColor(this->initMenuColor[0]);
		cout << "1. Simulate Shopping";

		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 3);
		global.setColor(this->initMenuColor[1]);
		cout << "2. Check Inventory";

		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 4);
		global.setColor(this->initMenuColor[2]);
		cout << "3. Arrange Product";

		global.gotoXY(global.leftCenter(userLabel.length()-1), top + 6);
		global.setColor(this->initMenuColor[3]);
		cout << "Exit";

		this->key = _getch();
		if (this->key == 'w' && (this->counter >= 2 && this->counter <= 4)) {
			this->counter--;
		}

		if (this->key == 's' && (this->counter >= 1 && this->counter <= 3)) {
			this->counter++;
		}

		if (this->key == '\r') {
			switch (this->counter) {
			case 1: this->option = "shopping"; login.configLogin();  isChosen = true; break;
			case 2: this->option = "checkinven"; store.checkInventory(inv.inventory); isChosen = true; break;
			case 3: this->option = "arrange"; store.arrangeProduct(inv.inventory); isChosen = true; break;
			case 4: this->option = "exit"; global.generateMenu(); isChosen = true; break;
			}
		
		}

		this->initMenuColor[0] = 7;
		this->initMenuColor[1] = 7;
		this->initMenuColor[2] = 7;
		this->initMenuColor[3] = 7;

		switch (this->counter) {
		case 1: this->initMenuColor[0] = 3; break;
		case 2: this->initMenuColor[1] = 3; break;
		case 3: this->initMenuColor[2] = 3; break;
		case 4: this->initMenuColor[3] = 3; break;
		}
	}
}

void Option::CustomerOption::customerMenu(Customer& customerReference)
{
	Global global;
	int option = global.drawMenu(10, 2, "Grocery Store Management", "Manage Customer", "1. Show Customers Infomation", "2. Config Customers Info");
	switch (option) {
	case 1: 
		system("cls");
		customerReference.showCustomerList(); global.generateMenu(); break;
	case 2:
		cout << "Customer Option 2"; break;
	case 3:
		global.generateMenu(); break;
	}
}

void Option::ImportOption::importMenu()
{
	Global global;
	int option = global.drawMenu(10, 3, "IMPORT PRODUCT", "CHOOSE SUPPLIER BRAND", "1. Drinks Factory", "2. Fruit Market", "3. Tool Factory");
	switch (option) {
	case 1:
		global.generateMenu(); break;
	case 2:
		global.generateMenu(); break;
	case 3:
		global.generateMenu(); break;
	case 4:
		global.generateMenu(); break;
	case 5:
		global.generateMenu(); break;
	}
}

