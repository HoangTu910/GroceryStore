#pragma once
#include "Employee.h"
#include "Global.h"
#include "Product.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

class Customer
{
private:
	int customerID;
	string phoneNumber;
	int bonusPoint;
	string customerName;
	string customerGender;

public:
	vector<Customer> customerDatabase;
	vector<vector<Product>> transactionHistory;
	void setCustomerID(int id);
	void setPhoneNumber(string phonenum);
	void setBonusPoint(int point);
	void setCustomerName(string name);
	void setCustomerGender(string gender);

	int getCustomerID();
	string getCustomerPhone();
	int getBonusPoint();
	string getCustomerName();
	string getCustomerGender();

	//Application Method
	void showCustomerList();
};

