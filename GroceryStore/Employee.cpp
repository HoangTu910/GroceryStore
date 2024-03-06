#include "Employee.h"

Employee::Employee()
{
	this->userName = "user1";
	this->userPassword = "123";
}


Employee::Employee(string name, string password)
{
	this->userName = name;
	this->userPassword = password;
}

void Employee::setEmployeePassword(string password)
{
	this->userPassword = password;
}

void Employee::setEmployeeUserName(string username)
{
	this->userName = username;
}

string Employee::getEmployeePassword()
{
	return this->userPassword;
}

string Employee::getEmployeeUserName()
{
	return this->userName;
}




