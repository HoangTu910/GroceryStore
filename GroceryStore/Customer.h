#pragma once
#include "Employee.h"
#include "Global.h"
#include "Product.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>
#include <iomanip>
#include <algorithm>

class Customer
{
private:
	int customerID;
	string phoneNumber;
	int bonusPoint = 0;
	string customerName;
	string customerGender;

public:
	vector<Customer> customerDatabase;
	vector<vector<Product>> transactionHistory;
	vector<int> idContainer;
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
	void showCustomerList(vector<Customer> &customerDatabase);
	void showCustomerDetail(int index, vector<Customer>& customerDatabase);
	void showSingleCustomer(Customer customerDatabase);
	void removeCustomer(int index, vector<Customer>& customerDatabase);
	void changeCustomerInfo(int index, vector<Customer>& customerDatabase);
	void showTransactionHistory(vector<vector<Product>>& transactionHistory, vector<Customer>& customerDatabase, vector<int>& idContainer);
};

