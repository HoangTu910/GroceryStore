#include "Inventory.h"
#include "drawBox.h"

Product createProduct(const std::string& name, const std::string& category, float price, int id, int quantity) {
	return Product(name, category, price, id, quantity);
}
Inventory::Inventory()
{
	initProduct();
}
void Inventory::initProduct()
{
	Product apple("Apple", "fruit", 100, 101, 50);
	Product banana("Banana", "fruit", 100, 102, 50);
	Product lemon("Lemon", "fruit", 50, 103, 50);

	Product pencil("Pencil", "tool", 150, 201, 50);
	Product ruler("Ruler", "tool", 120, 202, 50);
	Product eraser("Eraser", "tool", 80, 203, 50);
	Product notebook("Notebook", "tool", 160, 204, 50);

	Product sweeper("Sweeper", "other", 200, 301, 50);
	Product firstAid("First Aid", "other", 180, 302, 50);
	Product snack("Snack", "other", 70, 303, 50);

	this->inventory = {
		apple, banana, pencil, ruler, eraser, notebook, sweeper, firstAid, snack
	};

}

void Inventory::checkInventory()
{

}

void Inventory::importProduct()
{
	system("cls");
	Global global;
	global.initBar(3, "ID Product", "Categorize", "Name Product");
	while (true) {
		
	}
}

int Inventory::getInventoryCapacity()
{
	return this->inventoryCapacity;
}

vector<Product> Inventory::getInventory()
{
	return this->inventory;
}

Product& Inventory::getProduct(size_t index)
{
	if (index < this->inventory.size()) {
		return this->inventory[index];
	}
	throw std::out_of_range("Index out of range");
}





