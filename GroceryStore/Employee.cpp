#include "Employee.h"

Employee::Employee()
{
	this->userName = "user1";
	this->userPassword = "123";
	this->firstName = "Hoang Huu";
	this->lastName = "Tu";
	this->gender = "Male";
	this->staffID = "165";
	this->dateOfBirth = "16/05/2003";
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

void Employee::setEmployeeLastName(string lastname)
{
	this->lastName = lastname;
}

void Employee::setEmployeeFirstName(string firstname)
{
	this->firstName = firstname;
}

void Employee::setEmployeeGender(string gender)
{
	this->gender = gender;
}

void Employee::setEmployeeID(string ID)
{
	this->staffID = ID;
}

void Employee::setEmployeeBirth(string date)
{
	this->dateOfBirth = date;
}

string Employee::getEmployeePassword()
{
	return this->userPassword;
}

string Employee::getEmployeeUserName()
{
	return this->userName;
}

string Employee::getEmployeeLastName()
{
	return this->lastName;
}

string Employee::getEmployeeFirstName()
{
	return this->firstName;
}

string Employee::getEmployeeGender()
{
	return this->gender;
}

string Employee::getEmployeeID()
{
	return this->staffID;
}

string Employee::getEmployeeBirth()
{
	return this->dateOfBirth;
}




