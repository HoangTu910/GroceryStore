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
	int quantity;
	float sellPrice = 0;
	int sellQuantity = 0;
public:
	Product(string productName, string category, float price, int id, int quantity);
	//getter & setter
	void setProductName(string name);
	void setCategory(string cat);
	void setProductPrice(float price);
	void setProductID(int id);
	void setSellPrice(float price);
	void setSellQuantity(int quantity);
	void setQuantity(int quantity);

	string getProductName();
	string getCategory();
	float getProductPrice();
	int getProductID();
	int getProductQuantity();
	float getSellPrice();
	int getSellQuantity();
};

