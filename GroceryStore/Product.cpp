#include "Product.h"

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
