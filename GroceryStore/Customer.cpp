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

void Customer::showCustomerList(vector<Customer>& customerDatabase)
{
	Global global;
	Option option;
	string storeLabels = "GROCERY STORE";
	string listLabel = "CUSTOMER DATABASE"; 
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
		if (customerDatabase.empty()) {
			global.notiBox("No Customer Data.");
		}
		else {
			cout << counter;
			global.setColor(7);
			global.gotoXY(global.leftCenter(storeLabels.length() - 1), 3);
			cout << storeLabels;
			global.gotoXY(global.leftCenter(listLabel.length() - 1), 5);
			cout << listLabel;
			global.drawRectangle(lefts, top, width, height);

			for (int i = page * 10; (i < customerDatabase.size()) && (i < page * 10 + 10); i++) {
				global.gotoXY(leftBox, top + 2 + i % 10 + 1);
				global.setColor(initMenuColor[i % 10]);
				cout << customerDatabase[i].getCustomerID();
				geti = i % 10;
			}

			global.gotoXY(global.leftCenter(2), top + 5 + geti + 1);
			global.setColor(initMenuColor[geti + 1]);
			cout << page + 1 << "/" << ceil(float(customerDatabase.size() / 10.0));
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

			if (key == '\r') {
				if (counter == pageCounter[page] + 1) {
					page = (page + 1) % (customerDatabase.size() / 10 + 1);
					system("cls");
					counter = 1;
				}
				else if (counter == pageCounter[page] + 2) {
					return option.storeMenu(); break;
				}

			}
			for (int i = 0; i < customerDatabase.size() + 3; i++) {
				initMenuColor[i] = 7;
			}
			initMenuColor[counter - 1] = 3;
		}
	}
}






