#include "Customer.h"
#include "Option.h"

void Customer::setCustomerID(int id)
{
	this->customerID = id;
}

void Customer::setPhoneNumber(string phonenum)
{
	this->phoneNumber = phonenum;
}

void Customer::setBonusPoint(int point)
{
	this->bonusPoint = point;
}

void Customer::setCustomerName(string name)
{
	this->customerName = name;
}

void Customer::setCustomerGender(string gender)
{
	this->customerGender = gender;
}

int Customer::getCustomerID()
{
	return this->customerID;
}

string Customer::getCustomerPhone()
{
	return this->phoneNumber;
}

int Customer::getBonusPoint()
{
	return this->bonusPoint;
}

string Customer::getCustomerName()
{
	return this->customerName;
}

string Customer::getCustomerGender()
{
	return this->customerGender;
}

void Customer::removeCustomer(int index, vector<Customer>& customerDatabase)
{
	Global global;
	string option = global.getTextElementBox("Do you want to remove this customer? (y/n)");
	if(option == "y") customerDatabase.erase(customerDatabase.begin() + index);
	system("cls");
}

void Customer::changeCustomerInfo(int index, vector<Customer>& customerDatabase)
{
	system("cls");
	Global global;
	Option option;
	global.hideCursor(false);
	int width = 40;
	int heigth = 12;
	int counter = 3;
	vector<int> initMenuColor = { 7, 7, 7, 7 };
	string storeLabel = "GROCERY STORE MANAGMENT";
	string Label = "EDIT CUSTOMER INFORMATION";
	char key;
	global.gotoXY(global.leftCenter(storeLabel.length() - 1), 3);
	cout << storeLabel;
	global.gotoXY(global.leftCenter(Label.length() - 1), 5);
	cout << Label;
	drawBox drawBox(width, heigth);
	global.hideCursor(true);
	bool isRun = true;
	while (isRun) {
		global.setColor(7);
		global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 2);
		cout << "UID: ";
		global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 4);
		cout << "Bonus Point: ";
		global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 6);
		cout << "Name: ";
		global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 8);
		cout << "Phone Number: ";
		global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 10);
		cout << "Gender: ";

		global.gotoXY(drawBox.getLeft() + 10, drawBox.getTop() + 2);
		cout << customerDatabase[index].getCustomerID();
		global.gotoXY(drawBox.getLeft() + 18, drawBox.getTop() + 4);
		cout << customerDatabase[index].getBonusPoint();
		global.gotoXY(drawBox.getLeft() + 11, drawBox.getTop() + 6);
		global.setColor(initMenuColor[0]);
		cout << customerDatabase[index].getCustomerName();
		global.gotoXY(drawBox.getLeft() + 19, drawBox.getTop() + 8);
		global.setColor(initMenuColor[1]);
		cout << customerDatabase[index].getCustomerPhone();
		global.gotoXY(drawBox.getLeft() + 14, drawBox.getTop() + 10);
		global.setColor(initMenuColor[2]);
		cout << customerDatabase[index].getCustomerGender();

		global.gotoXY(global.leftCenter(7), drawBox.getTop() + 12);
		global.setColor(initMenuColor[3]);
		cout << "Confirm";

		key = _getch();

		if (key == 'w' && (counter >= 2 && counter <= 4)) {
			counter--;
		}

		if (key == 's' && (counter >= 1 && counter <= 3)) {
			counter++;
		}
		if (key == '\r') {
			string name, phone, gender;
			switch (counter) {
			case 1: 
				global.gotoXY(drawBox.getLeft() + 11, drawBox.getTop() + 6);
				global.removeCache();
				global.gotoXY(drawBox.getLeft() + 11, drawBox.getTop() + 6);
				cin >> name;
				customerDatabase[index].setCustomerName(name);
				break;
			case 2:
				global.gotoXY(drawBox.getLeft() + 19, drawBox.getTop() + 8);
				global.removeCache();
				global.gotoXY(drawBox.getLeft() + 19, drawBox.getTop() + 8);
				cin >> phone;
				customerDatabase[index].setPhoneNumber(phone);
				break;
			case 3:
				global.gotoXY(drawBox.getLeft() + 14, drawBox.getTop() + 10);
				global.removeCache();
				global.gotoXY(drawBox.getLeft() + 14, drawBox.getTop() + 10);
				cin >> gender;
				customerDatabase[index].setCustomerGender(gender);
				break;
			case 4:
				isRun = false;
				system("cls");
				break;
			}
		}
		initMenuColor[0] = 7;
		initMenuColor[1] = 7;
		initMenuColor[2] = 7;
		initMenuColor[3] = 7;

		switch (counter) {
		case 1: initMenuColor[0] = 3; break;
		case 2: initMenuColor[1] = 3; break;
		case 3: initMenuColor[2] = 3; break;
		case 4: initMenuColor[3] = 3; break;
		}
	}
}

void Customer::showTransactionHistory(vector<vector<Product>>& transactionHistory, vector<Customer>& customerDatabase, vector<int>& idContainer)
{
	system("cls");
	for (int i = 0; i < transactionHistory.size(); i++) {
		cout << "ID: " << idContainer[i] << endl;
		for (int j = 0; j < transactionHistory[i].size(); j++) {
			cout << "Name: " << transactionHistory[i][j].getProductName() << endl;
			cout << "Quantity: " << transactionHistory[i][j].getSellQuantity() << endl;
			cout << "Price: " << transactionHistory[i][j].getSellPrice() * transactionHistory[i][j].getSellQuantity() << endl;
		}
	}
}

void Customer::showCustomerList(vector<Customer>& customerDatabase)
{
	Global global;
	Option option;
	string storeLabels = "Manage Customer Information";
	string listLabel = "C - Change    V - View    D - Delete"; 
	string currentMode = "View Mode";
	int geti = 0;
	int counter = 1;
	int page = 0;
	int width = 30;
	int height = customerDatabase.size() + 7;
	int top = 7;	
	char key;
	int lefts = global.leftCenter(width);
	int leftBox = global.leftCenterBox(width, 4-1);
	vector<int> initMenuColor;
	int invenSize = customerDatabase.size();
	int tempSize = invenSize;
	char checkBox;
	vector<int> pageCounter;
	string prevMode = "";
	bool prep = false;
	int redundant = tempSize % 10;
	tempSize = tempSize - redundant;
	for (int i = 0; i < tempSize / 10; i++) {
		pageCounter.push_back(10);
	}
	pageCounter.push_back(redundant);
	for (int i = 0; i < customerDatabase.size() + 3; i++) {
		initMenuColor.push_back(7);
	}
	while (true) {
		if (prep == true) {
			pageCounter.clear();
			initMenuColor.clear();
			invenSize = customerDatabase.size();
			tempSize = invenSize;
			redundant = tempSize % 10;
			tempSize = tempSize - redundant;
			for (int i = 0; i < tempSize / 10; i++) {
				pageCounter.push_back(10);
			}
			pageCounter.push_back(redundant);
			for (int i = 0; i < customerDatabase.size() + 3; i++) {
				initMenuColor.push_back(7);
			}
			prep = false;
		}

		if (customerDatabase.empty()) {
			global.notiBox("No Customer Data.");
			return option.storeMenu();
		}
		else {
			global.setColor(7);
			global.gotoXY(global.leftCenter(storeLabels.length() - 1), 3);
			cout << storeLabels;
			global.gotoXY(global.leftCenter(listLabel.length() - 1), 5);
			cout << listLabel;
			global.drawRectangle(lefts, top, width, height);
			if (prevMode != currentMode) {
				global.gotoXY(global.leftCenterBox(width, currentMode.length()+3), top + 1);
				global.removeCache();
			}
			global.gotoXY(global.leftCenterBox(width, currentMode.length() - 2), top + 1);
			cout << currentMode;
			prevMode = currentMode;
			for (int i = page * 10; (i < customerDatabase.size()) && (i < page * 10 + 10); i++) {
				global.gotoXY(leftBox, top + 2 + i % 10 + 1);
				global.setColor(initMenuColor[i % 10]);
				cout << customerDatabase[i].getCustomerID();
				geti = i % 10;
			}

			global.gotoXY(global.leftCenter(8), top + 5 + geti + 1);
			global.setColor(initMenuColor[geti + 1]);
			cout <<">> " << page + 1 << "/" << ceil(float(customerDatabase.size() / 10.0)) << " <<";
			global.gotoXY(global.leftCenter(3), top + 5 + geti + 3);
			global.setColor(initMenuColor[geti + 2]);
			cout << "Exit";

			key = _getch();
			if (key == 'w' && (counter >= 2 && counter <= invenSize + 3)) {
				counter--;
			}

			if (key == 's' && (counter >= 1 && counter <= invenSize + 2)) {
				counter++;
			}

			if (key == 'c') {
				currentMode = "Change Mode";
			}

			if (key == 'v') {
				currentMode = "View Mode";
			}

			if (key == 'd') {
				currentMode = "Delete Mode";
			}

			if (key == '\r') {
				if (counter == pageCounter[page] + 1) {
					page = (page + 1) % (customerDatabase.size() / 10 + 1);
					system("cls");
					counter = 1;
				}
				else if (counter == pageCounter[page] + 2) {
					return option.storeMenu(); break;
				}
				else {
					if (currentMode == "View Mode") showSingleCustomer(customerDatabase[counter - 1]);
					else if (currentMode == "Change Mode") { 
						changeCustomerInfo(counter - 1, customerDatabase);
					}
					else if (currentMode == "Delete Mode") { 
						removeCustomer(counter - 1, customerDatabase); 
						prep = true;
					}
				}
			}
			for (int i = 0; i < customerDatabase.size() + 3; i++) {
				initMenuColor[i] = 7;
			}
			initMenuColor[counter - 1] = 3;
		}
	}
}

void Customer::showCustomerDetail(int index, vector<Customer>& customerDatabase)
{
	for (int i = 0; i < customerDatabase.size(); i++) {
		if (i == index) {
			return showSingleCustomer(customerDatabase[i]);
		}
	}
}

void Customer::showSingleCustomer(Customer customerDatabase)
{
	system("cls");
	Global global;
	Option option;
	global.hideCursor(false);
	int width = 40;
	int heigth = 12;
	string storeLabel = "GROCERY STORE MANAGMENT";
	string Label = "CUSTOMER INFORMATION";
	char key;
	global.gotoXY(global.leftCenter(storeLabel.length() - 1), 3);
	cout << storeLabel;
	global.gotoXY(global.leftCenter(Label.length() - 1), 5);
	cout << Label;
	drawBox drawBox(width, heigth);

	global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 2);
	cout << "UID: ";
	global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 4);
	cout << "Bonus Point: ";
	global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 6);
	cout << "Name: ";
	global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 8);
	cout << "Phone Number: ";
	global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 10);
	cout << "Gender: ";

	global.gotoXY(drawBox.getLeft() + 10, drawBox.getTop() + 2);
	cout << customerDatabase.getCustomerID();
	global.gotoXY(drawBox.getLeft() + 18, drawBox.getTop() + 4);
	cout << customerDatabase.getBonusPoint();
	global.gotoXY(drawBox.getLeft() + 11, drawBox.getTop() + 6);
	cout << customerDatabase.getCustomerName();
	global.gotoXY(drawBox.getLeft() + 19, drawBox.getTop() + 8);
	cout << customerDatabase.getCustomerPhone();
	global.gotoXY(drawBox.getLeft() + 14, drawBox.getTop() + 10);
	cout << customerDatabase.getCustomerGender();

	global.gotoXY(global.leftCenter(22), drawBox.getTop() + 12);
	cout << "Press 'enter' to Confirm !";

	key = _getch();
	while (key != '\r') {
		key = _getch();
	}
	system("cls");
}








