#include "Store.h"
#include "Option.h"
#include <conio.h>
#include <iomanip>

using namespace std;

void Store::checkInventory(vector<Product>& inv)
{
    system("cls");
    vector<int> initMenuColor = { 7,7 };
    char keyPressed;
    Global global;
    Option option;
    int width = 80;
    int height = 20;
    int top = 7;
    int lefts = global.leftCenter(width);
    int leftBox = global.leftCenterBox(width, 74);
    int geti = 0;
    int counter = 1;
    char key;
    int page = 0;
    string storeLabels = "STORE";
    string menuLabel = "CHECK INVENTORY";
    while (true) {
        if (inv.empty()) {
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
            for (int i = page * 10; (i < inv.size()) && (i < page * 10 + 10); i++) {
                global.gotoXY(leftBox, top + 5 + i % 10 + 1);
                showSingleProduct(inv[i]);
                geti = i % 10;
            }

            global.gotoXY(global.leftCenter(7), top + 5 + geti + 4);
            global.setColor(initMenuColor[0]);
            cout << ">> " << page + 1 << " <<";
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
                case 1: cout << page; page = (page + 1) % (inv.size() / 10 + 1); system("cls"); break;
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
            vector.erase(vector.begin() + i);
        }
    }
}


void Store::arrangeProduct(vector<Product>& inv)
{
    Global global;
    system("cls");
    vector<int> initMenuColor;
    char keyPressed;
    Option option;
    int width = 80;
    int height = 21;
    int top = 7;
    int lefts = global.leftCenter(width);
    int leftBox = global.leftCenterBox(width, 74);
    int geti = 0;
    int counter = 1;
    char key;
    string storeLabels = "STORE";
    string menuLabel = "ARRANGE PRODUCT";
    int invenSize = inv.size();
    vector<int> isChosen;
    char checkBox;
    int page = 0;
    for (int i = 0; i < inv.size() + 3; i++) {
        initMenuColor.push_back(7);
    }
    while (true) {
        if (inv.empty()) {
            global.notiBox("Nothing to push.");
            option.storeMenu();
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
            for (int i = page * 10; (i < inv.size()) && (i < page * 10 + 10); i++) {
                global.gotoXY(leftBox, top + 5 + i % 10 + 1);
                global.setColor(initMenuColor[i % 10]);
                showSingleProduct(inv[i]);
                geti = i % 10;
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
                case 11: this->editProductOnSell(inv);
                case 12: cout << page; page = (page + 1) % (inv.size() / 10 + 1); system("cls"); counter = 1; break;
                case 13: option.storeMenu(); break;
                default: {
                    bool check = findInVector(isChosen, counter + page * 10 - 1);
                    if (check) {
                        removeInVector(isChosen, counter + page * 10 - 1);
                        this->removeProductInVector(this->productOnSell, inv[counter + page * 10 - 1]);
                        checkBox = ' ';
                    }
                    else {
                        isChosen.push_back(counter + page * 10 - 1);
                        this->productOnSell.push_back(inv[counter + page * 10 - 1]);
                        checkBox = char(219);
                    }
                    global.gotoXY(width + lefts - 2, top + 5 + counter - 1 + 1);
                    cout << checkBox;
                    break;
                }
                }
            }

            for (int i = 0; i < inv.size() + 3; i++) {

                initMenuColor[i] = 7;
            }
            initMenuColor[counter - 1] = 3; //ha
        }
    }
}


void Store::showSingleProduct(Product& product)
{
    cout << "  " << setw(14) << left << product.getProductID();
    cout << "  " << setw(14) << left << product.getCategory();
    cout << "  " << setw(14) << left << product.getProductName();
    cout << "  " << setw(14) << left << product.getProductPrice();
    cout << "  " << product.getProductQuantity() << endl;
}


void Store::showSingleSellProduct(Product& product)
{
    cout << "  " << setw(14) << left << product.getProductID();
    cout << "  " << setw(14) << left << product.getCategory();
    cout << "  " << setw(14) << left << product.getProductName();
    /*cout << "  " << setw(14) << left << product.getSellPrice();
    cout << "  " << product.getSellQuantity() << endl;*/
}


int Store::getProductElement(vector<Product> vector, Product product)
{
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getProductID() == product.getProductID()) {
            return i;
            break;
        }
    }
    return 0;
}



vector<Product> Store::getProductOnSell() {
    return this->productOnSell;
}

void Store::goShopping()
{

}
//void Store::editProductOnSell(Inventory& inv)
//{
//
//}

void Store::editProductOnSell(vector<Product>& inv)
{
    Global global;
    system("cls");
    vector<int> initMenuColor;
    char keyPressed;
    Option option;
    int width = 80;
    int height = 21;
    int top = 7;
    int lefts = global.leftCenter(width);
    int leftBox = global.leftCenterBox(width, 74);
    int geti = 0;
    int counter = 1;
    int page = 0;
    char key;
    bool once = true;
    string storeLabels = "STORE";
    string menuLabel = "EDIT PRICE AND QUANTITY BEFORE ON SELL";
    int invenSize = inv.size();
    vector<int> isChosen;
    char checkBox;

    for (int i = 0; i < 3; i++) {
        initMenuColor.push_back(7);
    }
    while (true) {
        if (this->productOnSell.empty()) {
            global.notiBox("Inventory is empty");
            option.storeMenu();
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

            for (int i = page * 10; (i < this->productOnSell.size()) && (i < page * 10 + 10); i++) {
                global.gotoXY(leftBox, top + 5 + i % 10 + 1);
                showSingleSellProduct(this->productOnSell[i]);
                geti = i % 10;
            }

            global.gotoXY(global.leftCenter(17), top + 5 + geti + 3);
            global.setColor(initMenuColor[0]);
            cout << "[UPLOAD TO STORE]";
            global.gotoXY(global.leftCenter(7), top + 5 + geti + 5);
            global.setColor(initMenuColor[1]);
            cout << ">> " << page + 1 << " <<";
            global.gotoXY(global.leftCenter(4), top + 5 + geti + 7);
            global.setColor(initMenuColor[2]);
            cout << "Exit";

            while (once) {
                for (int i = page * 10; (i < this->productOnSell.size()) && (i < page * 10 + 10); i++) {
                    global.hideCursor(false);
                    vector<Product> maskVector(inv);
                    int index = getProductElement(maskVector, this->productOnSell[i]);
                    float sellPrice;
                    int sellQuantity;
                    global.gotoXY(73, top + 5 + i % 10 + 1);
                    cin >> sellPrice;
                    global.gotoXY(89, top + 5 + i % 10 + 1);
                    cin >> sellQuantity;
                    this->productOnSell[i].setSellPrice(sellPrice);
                    this->productOnSell[i].setSellQuantity(sellQuantity);
                    int productQuantity = inv[index].getProductQuantity();
                    int productLeft = productQuantity - sellQuantity;
                    if (productLeft < 0) {
                        productLeft = productQuantity;
                    }
                    else {
                        productLeft = productLeft;
                    }
                    inv[index].setQuantity(productLeft);
                }
                once = false;
            }

            global.hideCursor(true);
            key = _getch();
            if (key == 'w' && (counter >= 2 && counter <= 3)) {
                counter--;
            }

            if (key == 's' && (counter >= 1 && counter <= 2)) {
                counter++;
            }

            if (key == '\r') {
                switch (counter) {
                case 1: system("cls"); global.loadingEffect("Uploading..."); option.storeMenu(); break;
                case 2: cout << page; page = (page + 1) % (productOnSell.size() + 1); counter = 1; system("cls"); once = true; break;
                case 3: option.storeMenu(); break;
                default: break;
                }
            }

            for (int i = 0; i < 3; i++) {
                initMenuColor[i] = 7;
            }

            initMenuColor[counter - 1] = 3;
        }
    }
}

void Store::removeProductInVector(vector<Product>& vector, Product product)
{
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getProductID() == product.getProductID()) {
            vector.erase(vector.begin() + i);
        }
    }
}
