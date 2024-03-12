#include "Store.h"
#include "Option.h"
#include <conio.h>
#include <iomanip>

using namespace std;

void Store::checkInventory()
{
    system("cls");
    vector<int> initMenuColor = { 7,7 };
    char keyPressed;
	Inventory inv;
    Global global;
    Option option;
    int width = 80;
    int height = 20;
    int top = 7;
    int lefts = global.leftCenter(width);
    int leftBox = global.leftCenterBox(width, 74);
    int geti = 0;
    inv.initProduct();
    int counter = 1;
    char key;
    string storeLabels = "STORE";
    string menuLabel = "CHECK INVENTORY";
    while (true) {
        if (inv.getInventory().empty()) {
            std::cout << "Inventory is empty." << std::endl;
        }
        else {
            global.setColor(7);
            global.gotoXY(global.leftCenter(storeLabels.length() - 1), 3);
            cout << storeLabels;
            global.gotoXY(global.leftCenter(menuLabel.length() - 1), 5);
            cout << menuLabel;

            global.drawRectangle(lefts, top, width, height);
            global.gotoXY(leftBox, top + 3);
            cout << setw(16) << left << "  ID Product";
            cout << setw(16) << left << "  Categorize";
            cout << setw(16) << left << "  Name Product";
            cout << setw(16) << left << "  Price";
            cout << "  Quantity" << endl;
            for (int i = 0; i < inv.getInventory().size(); i++) {
                global.gotoXY(leftBox, top + 5 + i + 1);
                showSingleProduct(inv.getInventory()[i]);
                geti = i;
            }

            global.gotoXY(global.leftCenter(7), top + 5 + geti + 4);
            global.setColor(initMenuColor[0]);
            cout << ">> 1 <<";
            global.gotoXY(global.leftCenter(4), top + 5 + geti + 6);
            global.setColor(initMenuColor[1]);
            cout << "Exit";

            key = _getch();
            if (key == 'w' && (counter >= 2 && counter <= 2)) {
                counter--;
            }

            if (key == 's' && (counter >= 1 && counter <= 1)) {
                counter++;
            }

            if (key == '\r') {
                switch (counter) {
                case 1: cout << "1"; break;
                case 2: option.storeMenu(); break;
                }
            }
            initMenuColor[0] = 7;
            initMenuColor[1] = 7;

            switch (counter) {
            case 1: initMenuColor[0] = 3; break;
            case 2: initMenuColor[1] = 3; break;
            }
        }
    }
}

bool Store::findInVector(vector<int>& vector, int number) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == number) {
            return true;
            break;
        }
    }
    return false;
}
void Store::removeInVector(vector<int>& vector, int number) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == number) {
            vector.erase(vector.begin()+i);
        }
    }
}


void Store::arrangeProduct()
{
    Global global;
    system("cls");
    vector<int> initMenuColor;
    char keyPressed;
    Inventory inv;
    Option option;
    int width = 80;
    int height = 20;
    int top = 7;
    int lefts = global.leftCenter(width);
    int leftBox = global.leftCenterBox(width, 74);
    int geti = 0;
    inv.initProduct();
    int counter = 1;
    char key;
    string storeLabels = "STORE";
    string menuLabel = "ARRANGE PRODUCT";
    int invenSize = inv.getInventory().size();
    vector<int> isChosen;
    char checkBox;

    for (int i = 0; i < inv.getInventory().size() + 3; i++) {
        initMenuColor.push_back(7);
    }
    while (true) {
        if (inv.getInventory().empty()) {
            std::cout << "Inventory is empty." << std::endl;
        }
        else {
            global.setColor(7);
            global.gotoXY(global.leftCenter(storeLabels.length() - 1), 3);
            cout << storeLabels;
            global.gotoXY(global.leftCenter(menuLabel.length() - 1), 5);
            cout << menuLabel;

            global.drawRectangle(lefts, top, width, height);
            global.gotoXY(leftBox, top + 3);
            cout << setw(16) << left << "  ID Product";
            cout << setw(16) << left << "  Categorize";
            cout << setw(16) << left << "  Name Product";
            cout << setw(16) << left << "  Price";
            cout << "  Quantity" << endl;
            for (int i = 0; i < inv.getInventory().size(); i++) {
                global.gotoXY(leftBox, top + 5 + i + 1);
                global.setColor(initMenuColor[i]);
                showSingleProduct(inv.getInventory()[i]);
                geti = i;
            }

            global.gotoXY(global.leftCenter(13), top + 5 + geti + 3);
            global.setColor(initMenuColor[geti + 1]);
            cout << "PUSH TO STORE";
            global.gotoXY(global.leftCenter(4), top + 5 + geti + 5);
            global.setColor(initMenuColor[geti + 2]);
            cout << "Page";
            global.gotoXY(global.leftCenter(4), top + 5 + geti + 7);
            global.setColor(initMenuColor[geti + 3]);
            cout << "Exit";

            key = _getch();
            if (key == 'w' && (counter >= 2 && counter <= invenSize + 3)) {
                counter--;
            }

            if (key == 's' && (counter >= 1 && counter <= invenSize + 2)) {
                counter++;
            }

            if (key == '\r') {
                switch (counter) {
                case 11: cout << "page"; break;
                case 12: option.storeMenu(); break;
                default: break;
                }
                bool check = findInVector(isChosen, counter - 1);
                cout << check;
                if (check) {
                    removeInVector(isChosen, counter - 1);
                    checkBox = ' ';
                }
                else {
                    isChosen.push_back(counter - 1);
                    checkBox = char(219);
                }
                global.gotoXY(width + lefts - 2, top + 5 + counter - 1 + 1);
                cout << checkBox;
            }

            for (int i = 0; i < inv.getInventory().size() + 3; i++) {
             
                initMenuColor[i] = 7;
            }   
            initMenuColor[counter - 1] = 3;
        }
    }
}

void Store::showSingleProduct(Product &product)
{
    cout << "  " << setw(14) << left << product.getProductID();
    cout << "  " << setw(14) << left << product.getCategory();
    cout << "  " << setw(14) << left << product.getProductName();
    cout << "  " << setw(14) << left << product.getProductPrice();
    cout << "  " << product.getProductQuantity() << endl;
}
