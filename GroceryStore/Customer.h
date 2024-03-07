#pragma once
#include "Employee.h"
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
public:
	void setCustomerID(int id);
	void setPhoneNumber(string phonenum);
	void setBonusPoint(int point);

	int setCustomerID();
	string setCustomerPhone();
	int setBonusPoint();
};

