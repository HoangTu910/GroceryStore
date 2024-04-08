#include "Inventory.h"
#include "Product.h"
#include "Global.h"
#include "Customer.h"
#include "drawBox.h"
#include <ctime>
#include <set>
#include <random>
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
	void editCustomerCart(vector<Product>& productOnSell, vector<Product>& customerCart, vector<vector<Product>>& transactionHistory, vector<Customer> &customerDatabase, vector<int>& idContainer);
	void removeProductInVector(vector<Product>& vector, Product product);
	void goShopping(vector<Product>& productOnSell, vector<Product> &customerCart, vector<vector<Product>>& transactionHistory, vector<Customer> &customerDatabase, vector<int>& idContainer);
	void showSingleSellProduct(Product& product);
	vector<Product> getProductOnSell();
	vector<Product> productOnSell;
	vector<Product> customerCart;
	void removeZeroQuantity(vector<Product>& vector);
	void removeZeroSellQuantity(vector<Product>& vector);
	void showBill(int index, vector<vector<Product>>& transactionHistory);
	void addCustomer(vector<Customer> &customerDatabase, vector<int>& idContainer);
	void newCustomer(vector<Customer>& customerDatabase, vector<int>& idContainer);
	void availableCustomer(vector<Customer>& customerDatabase, vector<int>& idContainer);
	int generateCustomerID(set<int> &generateSet);
	int getCustomerElement(int id, vector<Customer>& customerDatabase);
};


