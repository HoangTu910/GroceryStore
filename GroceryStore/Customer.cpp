#include "Customer.h"

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

void Customer::showCustomerList()
{
	Global global;
	if (this->customerDatabase.empty()) {
		global.notiBox("No Customer Data.");
	}
}






