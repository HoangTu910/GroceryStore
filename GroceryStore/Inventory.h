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
	vector<Product> inventory;
	int inventoryCapacity = 100;
public:
	void initProduct();
	void checkInventory();
	int getInventoryCapacity();
	vector<Product> getInventory();
};

