#include "Inventory.h"
#include "Product.h"
#include "Global.h"
#pragma once
class Store
{
private:
	vector<Product> productOnSell;
	Inventory inv;
public:
	void showSingleProduct(Product& product);
	void checkInventory();
	void arrangeProduct();
	bool findInVector(vector<int> &vector, int number);
	void removeInVector(vector<int> &vector, int number);
	vector<Product> getProductOnSell();
	int getProductElement(vector<Product>vector, Product product);
	void editProductOnSell();
	void removeProductInVector(vector<Product>& vector, Product product);
	void goShopping();
	void showSingleSellProduct(Product& product);
};

