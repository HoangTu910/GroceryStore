#include "Inventory.h"


Product createProduct(const std::string& name, const std::string& category, float price, int id, int quantity) {
	return Product(name, category, price, id, quantity);
}
void Inventory::initProduct()
{
	Product apple("Apple", "fruit", 100, 1, 50);
	Product banana("Banana", "fruit", 100, 2, 50);
	Product lemon("Lemon", "fruit", 50, 3, 50);

	Product pencil("Pencil", "tool", 150, 4, 50);
	Product ruler("Ruler", "tool", 120, 5, 50);
	Product eraser("Eraser", "tool", 80, 6, 50);
	Product notebook("Notebook", "tool", 160, 7, 50);

	Product sweeper("Sweeper", "other", 200, 8, 50);
	Product firstAid("First Aid", "other", 180, 9, 50);
	Product snack("Snack", "other", 70, 10, 50);

	inventory = {
		apple, banana, pencil, ruler, eraser, notebook, sweeper, firstAid, snack
	};

}



