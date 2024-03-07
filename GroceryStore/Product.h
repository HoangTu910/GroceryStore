#pragma once
#include "Global.h"
#include "Employee.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

using namespace std;

class Product
{
private:
	string productName;
	string category;
	float productPrice;
	int productID;
public:
	//getter & setter
	void setProductName(string name);
	void setCategory(string cat);
	void setProductPrice(float price);
	void setProductID(int id);

	string getProductName();
	string getCategory();
	float getProductPrice();
	int getProductID();
};

