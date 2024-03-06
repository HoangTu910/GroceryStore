#pragma once
#include<cstring>
#include<string>

using namespace std;

class Employee
{
private:
	string userPassword;
	string userName;

public:
	Employee();
	Employee(string name, string password);
	void setEmployeePassword(string password);
	void setEmployeeUserName(string userName);
	string getEmployeePassword();
	string getEmployeeUserName();
};

