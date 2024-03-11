#pragma once
#include<cstring>
#include<string>

using namespace std;

class Employee
{
private:
	string userPassword;
	string userName;
	string lastName;
	string firstName;
	string gender;
	string staffID;
	string dateOfBirth;

public:
	Employee();
	Employee(string name, string password);
	void setEmployeePassword(string password);
	void setEmployeeUserName(string userName);
	void setEmployeeLastName(string lastname);
	void setEmployeeFirstName(string firstname);
	void setEmployeeGender(string gender);
	void setEmployeeID(string ID);
	void setEmployeeBirth(string date);

	string getEmployeePassword();
	string getEmployeeUserName();
	string getEmployeeLastName();
	string getEmployeeFirstName();
	string getEmployeeGender();
	string getEmployeeID();
	string getEmployeeBirth();
};

