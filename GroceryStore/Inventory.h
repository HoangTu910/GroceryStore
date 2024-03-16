#pragma once
#include "Product.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

class Inventory
{
private:
	int inventoryCapacity = 100;
public:
	Inventory();
	void initProduct();
	void checkInventory();
	void importProduct();
	int getInventoryCapacity();
	vector<Product> getInventory();
	Product& getProduct(size_t index);
	vector<Product> inventory;
};

