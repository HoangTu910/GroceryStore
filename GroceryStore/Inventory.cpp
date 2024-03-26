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

	this->inventory = { apple, banana, pencil, ruler, eraser, notebook, sweeper, snack, lemon, firstAid};

}


void Inventory::checkInventory()
{

}

void Inventory::importProduct(Inventory& inv)
{
	Global global;
	int getNum = global.getNumberElementBox("NUMBER PRODUCT TO IMPORT (<10)");
	system("cls");
	global.hideCursor(false);
	string storeLabels = "GROCERY STORE MANAGMENT";
	string menuLabel = "IMPORT PRODUCT (USER)";
	int col = 0;
	int row = 0;
	int num = 0;
	int distance = 18;
	int initPosRow = 21;
	global.setColor(7);
	global.gotoXY(global.leftCenter(storeLabels.length() - 1), 3);
	cout << storeLabels;
	global.gotoXY(global.leftCenter(menuLabel.length() - 1), 5);
	cout << menuLabel;
	global.initBar(getNum, 5, "ID Product", "Categorize", "Name Product", "Price", "Quantity");
	while (num < getNum) {
		int id, quantity;
		string category, name;
		float price;
		global.gotoXY(initPosRow + row, 5 + 5 + col + 1);
		cin >> id;
		row += distance;
		global.gotoXY(initPosRow + row, 5 + 5 + col + 1);
		cin >> category;
		row += distance;
		global.gotoXY(initPosRow + row, 5 + 5 + col + 1);
		cin >> name;
		row += distance;
		global.gotoXY(initPosRow + row, 5 + 5 + col + 1);
		cin >> price;
		row += distance;
		global.gotoXY(initPosRow + row, 5 + 5 + col + 1);
		cin >> quantity;
		row += distance;
		col++;
		row = 0;
		num++;
		inv.inventory.push_back(Product(name, category, price, id, quantity));
	}
	global.hideCursor(true);
	return global.generateMenu();
}


void Inventory::importProductFile(Inventory& inv)
{
	Global global;
	string filename = global.getTextElementBox("Import CSV File");
	ifstream file(filename);

	if (!file.is_open()) {
		global.notiBox("Error opening file: " + filename);
		return global.generateMenu();
	}

	string line;
	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);
		string name, categorize;
		int id, quantity;
		float price;
		string field;

		getline(ss, field, ',');
		id = stoi(field); 

		getline(ss, categorize, ',');
		getline(ss, name, ',');

		getline(ss, field, ',');
		price = stof(field);

		getline(ss, field);
		quantity = stoi(field);

		inv.inventory.push_back(Product(name, categorize, price, id, quantity));
	}
	file.close();
	global.hideCursor(true);
	global.loadingEffect("Importing CSV File...");
	return global.generateMenu();
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







