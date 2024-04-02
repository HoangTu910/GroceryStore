#include "Inventory.h"
#include "Product.h"
#include "Global.h"
#pragma once
class Store
{

	
public:
	void showSingleProduct(Product& product);
	void checkInventory(vector<Product>& inv);
	void arrangeProduct(vector<Product>& inv, vector<Product>& productOnSell);
	bool findInVector(vector<int> &vector, int number);
	void removeInVector(vector<int> &vector, int number);
	int getProductElement(vector<Product> vector, Product product);
	void editProductOnSell(vector<Product>& inv, vector<Product>& productOnSell);
	void editCustomerCart(vector<Product>& productOnSell, vector<Product>& customerCart, vector<vector<Product>>& transactionHistory);
	void removeProductInVector(vector<Product>& vector, Product product);
	void goShopping(vector<Product>& productOnSell, vector<Product> &customerCart, vector<vector<Product>>& transactionHistory);
	void showSingleSellProduct(Product& product);
	vector<Product> getProductOnSell();
	vector<Product> productOnSell;
	vector<Product> customerCart;
};


