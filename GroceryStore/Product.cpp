#include "Product.h"

Product::Product(string productName, string category, float price, int id, int quantity)
{
	this->productName = productName;
	this->category = category;
	this->productPrice = price;
	this->productID = id;
	this->quantity = quantity;
}

//getter & setter
void Product::setProductName(string name)
{
	this->productName = name;
}

void Product::setCategory(string cat)
{
	this->category = cat;
}

void Product::setProductPrice(float price)
{
	this->productPrice = price;
}

void Product::setProductID(int id)
{
	this->productID = id;
}

string Product::getProductName()
{
	return this->productName;
}

string Product::getCategory()
{
	return this->category;
}

float Product::getProductPrice()
{
	return this->productPrice;
}

int Product::getProductID()
{
	return this->productID;
}
