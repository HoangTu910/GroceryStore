#include "Inventory.h"
#include "Product.h"
#include "Global.h"
#pragma once
class Store
{
private:
	vector<Product> productOnSell;
public:
	void showSingleProduct(Product& product);
	void checkInventory(vector<Product>& inv);
	void arrangeProduct(vector<Product>& inv);
	bool findInVector(vector<int> &vector, int number);
	void removeInVector(vector<int> &vector, int number);
	int getProductElement(vector<Product> vector, Product product);
	void editProductOnSell(vector<Product>& inv);
	void removeProductInVector(vector<Product>& vector, Product product);
	void goShopping();
	void showSingleSellProduct(Product& product);
	vector<Product> getProductOnSell();
};

