#include "Inventory.h"
#include "Product.h"
#include "Global.h"
#pragma once
class Store
{
private:

public:
	void showSingleProduct(Product& product);
	void checkInventory();
	void arrangeProduct();
	bool findInVector(vector<int> &vector, int number);
	void removeInVector(vector<int> &vector, int number);
	void goShopping();
};

