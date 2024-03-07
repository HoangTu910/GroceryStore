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

int Customer::setCustomerID()
{
	return this->customerID;
}

string Customer::setCustomerPhone()
{
	return this->phoneNumber;
}

int Customer::setBonusPoint()
{
	return this->bonusPoint;
}




