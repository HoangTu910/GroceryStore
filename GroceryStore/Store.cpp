#include "Store.h"
#include "Option.h"
#include <conio.h>
#include <iomanip>
#include <cmath>

using namespace std;
int customerIndex = -1;
int totalProductOnSell = 0;
vector<Product> virtualProductOnSell;
vector<Product> prevProductOnSell;
vector<Product> tempInventory;
vector<Product> tempProductOnSell;
vector<vector<Product>> prevTransactionHistory;
set<int> generateSet;


void Store::checkInventory(vector<Product>& inv)
{
    system("cls");
    //removeZeroQuantity(inv);
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

            global.gotoXY(global.leftCenter(9), top + 5 + geti + 4);
            global.setColor(initMenuColor[0]);
            cout << ">> " << page + 1 << "/" << ceil(float(inv.size() / 10.0))    << " <<";
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
                case 1: page = (page + 1) % (inv.size() / 10 + 1); system("cls"); break;
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


void Store::arrangeProduct(vector<Product>& inv, vector<Product>& productOnSell)
{
    /*removeZeroQuantity(inv);*/
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
    int counterPush = 0;
    string storeLabels = "STORE";
    string menuLabel = "ARRANGE PRODUCT - MAXIMUM 10 PRODUCTS AT A TIME";
    int invenSize = inv.size();
    int tempSize = invenSize;
    vector<int> isChosen;
    vector<int> pageCounter;
    int redundant = tempSize % 10;
    tempSize = tempSize - redundant;
    for (int i = 0; i < tempSize / 10; i++) {
        pageCounter.push_back(10);
    }
    pageCounter.push_back(redundant);
    char checkBox;
    int page = 0;
    for (int i = 0; i < inv.size() + 3; i++) {
        initMenuColor.push_back(7);
    }
    prevProductOnSell = productOnSell;
    totalProductOnSell = productOnSell.size();

    while (true) {
        if (inv.empty()) {
            global.notiBox("Nothing to push.");
            option.storeMenu();
        }
        else {
            global.setColor(7);
            global.gotoXY(global.leftCenter(storeLabels.length() - 1), 2);
            cout << storeLabels;
            global.gotoXY(global.leftCenter(menuLabel.length() - 1), 3);
            cout << menuLabel;
            global.gotoXY(global.leftCenter(11 - 1), 5);
            string push;
            if (counterPush < 10) {
                push = "0" + to_string(counterPush);
            }
            else {
                push = to_string(counterPush);
            }
            cout << "PUSHING: " << push;

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
            global.gotoXY(global.leftCenter(9), top + 5 + geti + 5);
            global.setColor(initMenuColor[geti + 2]);
            cout << ">> " << page + 1 << "/" << ceil(float(inv.size() / 10.0)) << " <<";
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
                /*switch (counter) {
                case 11: this->editProductOnSell(inv); break;
                case 12: cout << page; page = (page + 1) % (inv.size() / 10 + 1); system("cls"); counter = 1; break;
                case 13: option.storeMenu(); break;
                default: {
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
                }*/
                if (counter == pageCounter[page] + 1) {
                    this->editProductOnSell(inv, productOnSell);
                }
                else if (counter == pageCounter[page] + 2) {
                    cout << page; page = (page + 1) % (inv.size() / 10 + 1);
                    system("cls"); 
                    counter = 1;
                }
                else if (counter == pageCounter[page] + 3) {
                    option.storeMenu(); break;
                }
                else {
                    bool check = findInVector(isChosen, counter + page * 10 - 1);
                    if (check) {
                        removeInVector(isChosen, counter + page * 10 - 1);
                        this->removeProductInVector(productOnSell, inv[counter + page * 10 - 1]);
                        this->removeProductInVector(virtualProductOnSell, inv[counter + page * 10 - 1]);
                        checkBox = ' ';
                        counterPush--;
                    }
                    else {
                        if (counterPush < 10) {
                            isChosen.push_back(counter + page * 10 - 1);
                            productOnSell.push_back(inv[counter + page * 10 - 1]);
                            virtualProductOnSell.push_back(inv[counter + page * 10 - 1]);
                            checkBox = char(219);
                            counterPush++;
                        }
                    }
                    if (counterPush <= 10) {
                        global.gotoXY(width + lefts - 2, top + 5 + counter - 1 + 1);
                        cout << checkBox;
                    }
                }
            }

            for (int i = 0; i < inv.size() + 3; i++) {
                initMenuColor[i] = 7;
            }
            initMenuColor[counter - 1] = 3; 
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
    return productOnSell;
}

void Store::removeZeroQuantity(vector<Product>& vector)
{
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getProductQuantity() == 0) {
            vector.erase(vector.begin() + i);
        }
    }
}

void Store::removeZeroSellQuantity(vector<Product>& vector)
{
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getSellQuantity() == 0) {
            vector.erase(vector.begin() + i);
        }
    }
}


void Store::showBill(int index, vector<vector<Product>>& transactionHistory)
{
    Global global;
    int width = 51;
    int height = 20;
    int top = 4;
    int lefts = global.leftCenter(width);
    int leftBox = global.leftCenterBox(width, 47);
    string displayLabel = "MY GROCERY STORE";
    int center = global.leftCenter(displayLabel.length() - 1);
    global.drawRectangle(lefts, top, width, height);

    int alignLeft = lefts + 2;
    int alignTop = top + 2;
    time_t now = time(0);

    struct tm localTime;
    localtime_s(&localTime, &now);

    int day = localTime.tm_mday;
    int month = localTime.tm_mon + 1; 
    int year = localTime.tm_year + 1900;

    global.gotoXY(center, alignTop - 1);
    cout << displayLabel;
    global.gotoXY(alignLeft, alignTop);
    cout << "CUSTOMER BILL";
    global.gotoXY(alignLeft, alignTop+1);
    cout << "UID: ";
    global.gotoXY(alignLeft, alignTop + 2);
    cout << "Name: ";
    global.gotoXY(alignLeft, alignTop + 3);
    cout << "Phone number: ";
    global.gotoXY(alignLeft, alignTop+4);
    cout << "DATE: " << day << "/" << month << "/" << year;
    global.gotoXY(alignLeft, alignTop + 6);
    cout << "*************************************************";
    global.gotoXY(leftBox, alignTop + 7);
    cout << setw(21) << left << "Name Product";
    cout << setw(17) << left << "Quantity";
    cout <<"Total Price";
    while (true) {

    }
        
}


void Store::addCustomer(vector<Customer>& customerDatabase, vector<int>& idContainer)
{
    Global global;
    system("cls");
    int option = global.drawMenu(10, 2, "GROCERY STORE", "CUSTOMER SERVICE", "1. New Customer", "2. Available Customer");
    switch (option) {
        case 1: return newCustomer(customerDatabase, idContainer); break;
        case 2: return availableCustomer(customerDatabase, idContainer); break;
    }
}

void Store::newCustomer(vector<Customer>& customerDatabase, vector<int>& idContainer)
{
    system("cls");
    Customer customer;
    Global global;
    global.hideCursor(false);
    int width = 40;
    int heigth = 12;
    int uid = generateCustomerID(generateSet);
    int bonus = 0;
    string storeLabel = "GROCERY STORE MANAGMENT";
    string Label = "ADD NEW CUSTOMER";
    string phoneNum;
    string name;
    string gender;
    char key;
    global.gotoXY(global.leftCenter(storeLabel.length()-1), 3);
    cout << storeLabel;
    global.gotoXY(global.leftCenter(Label.length()-1), 5);
    cout << Label;
    drawBox drawBox(width, heigth);

    global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 2);
    cout << "UID: ";
    global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 4);
    cout << "Bonus Point: ";
    global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 6);
    cout << "Name: ";
    global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 8);
    cout << "Phone Number: ";
    global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 10);
    cout << "Gender: ";

    global.gotoXY(drawBox.getLeft() + 10, drawBox.getTop() + 2);
    cout << uid;
    global.gotoXY(drawBox.getLeft() + 18, drawBox.getTop() + 4);
    cout << customer.getBonusPoint();
    global.gotoXY(drawBox.getLeft() + 11, drawBox.getTop() + 6);
    cin >> name;
    global.gotoXY(drawBox.getLeft() + 19, drawBox.getTop() + 8);
    cin >> phoneNum;
    global.gotoXY(drawBox.getLeft() + 14, drawBox.getTop() + 10);
    cin >> gender;

    global.gotoXY(global.leftCenter(22), drawBox.getTop() + 12);
    cout << "Press 'enter' to Confirm !";
    customer.setCustomerID(uid);
    customer.setCustomerName(name);
    customer.setPhoneNumber(phoneNum);
    customer.setCustomerGender(gender);

    customerDatabase.push_back(customer);
    idContainer.push_back(customer.getCustomerID());
    global.hideCursor(true);

    key = _getch();
    while (key != '\r') {
        key = _getch();
    }
    global.loadingEffect("Order processing is underway...");
    global.notiBox("Succesfully Purchased - Thank you");
    return global.generateMenu();
}

void Store::availableCustomer(vector<Customer>& customerDatabase, vector<int>& idContainer)
{
    system("cls");
    Global global;
    Option option;
    global.hideCursor(false);
    int width = 40;
    int heigth = 12;
    int id = global.getIndexVector("Customer ID");
    string storeLabel = "GROCERY STORE MANAGMENT";
    string Label = "ADD NEW CUSTOMER";
    char key;
    global.gotoXY(global.leftCenter(storeLabel.length() - 1), 3);  
    cout << storeLabel; 
    global.gotoXY(global.leftCenter(Label.length() - 1), 5); 
    cout << Label;  
    drawBox drawBox(width, heigth); 
    int index = getCustomerElement(id, customerDatabase);


    if (index == -1) {
        global.notiBox("No customer available");
        return option.storeMenu();
    }
    else {
        global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 2);
        cout << "UID: ";
        global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 4);
        cout << "Bonus Point: ";
        global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 6);
        cout << "Name: ";
        global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 8);
        cout << "Phone Number: ";
        global.gotoXY(drawBox.getLeft() + 5, drawBox.getTop() + 10);
        cout << "Gender: ";

        global.gotoXY(drawBox.getLeft() + 10, drawBox.getTop() + 2);
        cout << customerDatabase[index].getCustomerID();
        global.gotoXY(drawBox.getLeft() + 18, drawBox.getTop() + 4);
        cout << customerDatabase[index].getBonusPoint();
        global.gotoXY(drawBox.getLeft() + 11, drawBox.getTop() + 6);
        cout << customerDatabase[index].getCustomerName();
        global.gotoXY(drawBox.getLeft() + 19, drawBox.getTop() + 8);
        cout << customerDatabase[index].getCustomerPhone();
        global.gotoXY(drawBox.getLeft() + 14, drawBox.getTop() + 10);
        cout << customerDatabase[index].getCustomerGender();

        global.gotoXY(global.leftCenter(22), drawBox.getTop() + 12);
        cout << "Press 'enter' to Confirm !";
        idContainer.push_back(customerDatabase[index].getCustomerID());
        key = _getch();
        while (key != '\r') {
            key = _getch();
        }
        global.loadingEffect("Order processing is underway...");
        global.notiBox("Succesfully Purchased - Thank you");
        return global.generateMenu();
    }
    

}

int Store::generateCustomerID(set<int>& generateSet)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1000, 9999);
    int randomNumber = distribution(gen);
    while (generateSet.find(randomNumber) != generateSet.end()) {
        randomNumber = distribution(gen);
    }
    generateSet.insert(randomNumber);
    return randomNumber;
}

int Store::getCustomerElement(int id, vector<Customer>& customerDatabase)
{
    for (int i = 0; i < customerDatabase.size(); i++) {
        if (customerDatabase[i].getCustomerID() == id) {
            return i;
        }
    }
    return -1;
}


void Store::goShopping(vector<Product>& productOnSell, vector<Product>& customerCart, vector<vector<Product>>& transactionHistory, vector<Customer> &customerDatabase, vector<int>& idContainer)
{
    //removeZeroSellQuantity(productOnSell);
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
    string menuLabel = "WELCOME TO GROCERY STORE";
    int invenSize = productOnSell.size();
    int tempSize = invenSize;
    vector<int> isChosen;
    vector<int> pageCounter;
    int redundant = tempSize % 10;
    tempSize = tempSize - redundant;
    for (int i = 0; i < tempSize / 10; i++) {
        pageCounter.push_back(10);
    }
    pageCounter.push_back(redundant);
    char checkBox;
    int page = 0;
    for (int i = 0; i < productOnSell.size() + 3; i++) {
        initMenuColor.push_back(7);
    }

    while (true) {
        if (productOnSell.empty()) {
            global.notiBox("Nothing to on shop.");
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
            for (int i = page * 10; (i < productOnSell.size()) && (i < page * 10 + 10); i++) {
                global.gotoXY(leftBox, top + 5 + i % 10 + 1);
                global.setColor(initMenuColor[i % 10]);
                cout << "  " << setw(14) << left << productOnSell[i].getProductID();
                cout << "  " << setw(14) << left << productOnSell[i].getCategory();
                cout << "  " << setw(14) << left << productOnSell[i].getProductName();
                cout << "  " << setw(14) << left << productOnSell[i].getSellPrice();
                cout << "  " << productOnSell[i].getSellQuantity() << endl;
                geti = i % 10;
            }

            global.gotoXY(global.leftCenter(13), top + 5 + geti + 3);
            global.setColor(initMenuColor[geti + 1]);
            cout << "[ADD TO CART]";
            global.gotoXY(global.leftCenter(9), top + 5 + geti + 5);
            global.setColor(initMenuColor[geti + 2]);
            cout << ">> " << page + 1 << "/" << ceil(float(productOnSell.size() / 10.0)) << " <<";
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
                if (counter == pageCounter[page] + 1) {
                    this->editCustomerCart(productOnSell, customerCart, transactionHistory, customerDatabase, idContainer);
                }
                else if (counter == pageCounter[page] + 2) {
                    page = (page + 1) % (productOnSell.size() / 10 + 1);
                    system("cls");
                    counter = 1;
                }
                else if (counter == pageCounter[page] + 3) {
                    return option.storeMenu(); break;
                }
                else {
                    bool check = findInVector(isChosen, counter + page * 10 - 1);
                    if (check) {
                        removeInVector(isChosen, counter + page * 10 - 1);
                        this->removeProductInVector(customerCart, productOnSell[counter + page * 10 - 1]);
                        checkBox = ' ';
                    }
                    else {
                        isChosen.push_back(counter + page * 10 - 1);
                        customerCart.push_back(productOnSell[counter + page * 10 - 1]);
                        checkBox = char(219);
                    }
                    global.gotoXY(width + lefts - 2, top + 5 + counter - 1 + 1);
                    cout << checkBox;
                }
            }

            for (int i = 0; i < productOnSell.size() + 3; i++) {
                initMenuColor[i] = 7;
            }
            initMenuColor[counter - 1] = 3; 
        }
    }
}

void Store::editProductOnSell(vector<Product>& inv, vector<Product>& productOnSell)
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
    tempInventory = inv;

    for (int i = 0; i < 3; i++) {
        initMenuColor.push_back(7);
    }
    while (true) {
        if (productOnSell.empty()) {
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

            for (int i = page * 10; (i < virtualProductOnSell.size()) && (i < page * 10 + 10); i++) {
                global.gotoXY(leftBox, top + 5 + i % 10 + 1);
                showSingleSellProduct(virtualProductOnSell[i]);
                geti = i % 10;
            }

            global.gotoXY(global.leftCenter(17), top + 5 + geti + 3);
            global.setColor(initMenuColor[0]);
            cout << "[UPLOAD TO STORE]";
            global.gotoXY(global.leftCenter(9), top + 5 + geti + 5);
            global.setColor(initMenuColor[1]);
            cout << ">> " << page + 1 << "/" << ceil(float(virtualProductOnSell.size() / 10.0)) << " <<";
            global.gotoXY(global.leftCenter(4), top + 5 + geti + 7);
            global.setColor(initMenuColor[2]);
            cout << "Exit";

            while (once) {
                for (int i = page * 10 + (totalProductOnSell); (i < productOnSell.size()) && (i < page * 10 + 10 + totalProductOnSell); i++) {
                    global.hideCursor(false);
                    vector<Product> maskVector(inv);
                    int index = getProductElement(maskVector, productOnSell[i]);
                    float sellPrice;
                    int sellQuantity;
                    global.gotoXY(73, top + 5 + (i+(10-totalProductOnSell)) % 10 + 1);
                    cin >> sellPrice;
                    global.gotoXY(89, top + 5 + (i+(10-totalProductOnSell)) % 10 + 1);
                    cin >> sellQuantity;
                    productOnSell[i].setSellPrice(sellPrice);
                    productOnSell[i].setSellQuantity(productOnSell[i].getSellQuantity() + sellQuantity);
                    cout << "i: " << page * 10 + (totalProductOnSell) << endl;
                    cout << "Shop: " << productOnSell.size() << endl;
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
            removeZeroQuantity(inv);
            totalProductOnSell = productOnSell.size();
           
            global.hideCursor(true);
            key = _getch();
            if (key == 'w' && (counter >= 2 && counter <= 3)) {
                counter--;
            }

            if (key == 's' && (counter >= 1 && counter <= 2)) {
                counter++;
            }

            if (key == '\r') {
                string confirm = "";
                switch (counter) {
                case 1: 
                    system("cls"); 
                    confirm = global.getTextElementBox("Confirm to Push? (y/n)");
                    if (confirm == "y") {
                        global.hideCursor(true);
                        global.loadingEffect("Uploading...");
                        virtualProductOnSell.clear();
                        return option.storeMenu();
                    }
                    else {
                        system("cls");
                        global.hideCursor(true);
                        productOnSell = prevProductOnSell;
                        inv = tempInventory;
                        virtualProductOnSell.clear();
                        return option.storeMenu();
                    }
                     
                    break;
                case 2: cout << page; page = (page + 1) % (virtualProductOnSell.size() + 1); counter = 1; system("cls"); once = true; break;
                case 3: return option.storeMenu(); break;
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


void Store::editCustomerCart(vector<Product>&productOnSell, vector<Product>&customerCart, vector<vector<Product>> &transactionHistory, vector<Customer>& customerDatabase, vector<int> &idContainer)
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
    string menuLabel = "SET YOUR QUANTITY";
    int invenSize = productOnSell.size();
    vector<int> isChosen;
    char checkBox;
    customerIndex++;
    transactionHistory.push_back(vector<Product>()); //Line 1
    cout << customerIndex;
    prevTransactionHistory = transactionHistory;
    for (int i = 0; i < 3; i++) {
        initMenuColor.push_back(7);
    }
    while (true) {
        if (productOnSell.empty()) {
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

            for (int i = page * 10; (i < customerCart.size()) && (i < page * 10 + 10); i++) {
                global.gotoXY(leftBox, top + 5 + i % 10 + 1);
                cout << "  " << setw(14) << left << customerCart[i].getProductID();
                cout << "  " << setw(14) << left << customerCart[i].getCategory();
                cout << "  " << setw(14) << left << customerCart[i].getProductName();
                cout << "  " << setw(14) << left << customerCart[i].getSellPrice();
                geti = i % 10;
            }

            global.gotoXY(global.leftCenter(5), top + 5 + geti + 3);
            global.setColor(initMenuColor[0]);
            cout << "[BUY]";
            global.gotoXY(global.leftCenter(9), top + 5 + geti + 5);
            global.setColor(initMenuColor[1]);
            cout << ">> " << page + 1 << "/" << ceil(float(customerCart.size() / 10.0)) << " <<";
            global.gotoXY(global.leftCenter(4), top + 5 + geti + 7);
            global.setColor(initMenuColor[2]);
            cout << "Exit";
            
            while (once) {
                tempProductOnSell = productOnSell;
                for (int i = page * 10; (i < customerCart.size()) && (i < page * 10 + 10); i++) {
                    global.hideCursor(false);
                    vector<Product> maskVector(productOnSell);
                    int index = getProductElement(maskVector, customerCart[i]);
                    int sellQuantity;
                    global.gotoXY(89, top + 5 + i % 10 + 1);
                    cin >> sellQuantity;
                    customerCart[i].setSellQuantity(sellQuantity);
                    //Fix bug these two lines of code
                    
                    transactionHistory[customerIndex].push_back(customerCart[i]); //Line 2
                    int productQuantity = productOnSell[index].getSellQuantity();
                    int productLeft = productQuantity - sellQuantity;   
                    if (productLeft < 0) {
                        productLeft = productQuantity;
                    }
                    else {
                        productLeft = productLeft;
                    }
                    productOnSell[index].setSellQuantity(productLeft);
                }
                once = false;
            }
            removeZeroSellQuantity(productOnSell);
            global.hideCursor(true);
            key = _getch();
            if (key == 'w' && (counter >= 2 && counter <= 3)) {
                counter--;
            }

            if (key == 's' && (counter >= 1 && counter <= 2)) {
                counter++;
            }

            if (key == '\r') {
                string confirm = "";
                switch (counter) {
                case 1: 
                    system("cls");  
                    confirm = global.getTextElementBox("Confirm to buy ? (y/n)");
                    global.hideCursor(true);
                    if (confirm == "y") {
                        customerCart.clear();
                        //return showBill(customerIndex, transactionHistory);
                        return addCustomer(customerDatabase, idContainer);
                    }
                    else {
                        system("cls");
                        productOnSell = tempProductOnSell;
                        transactionHistory = prevTransactionHistory; //bug dong nay
                        customerCart.clear();
                        return option.storeMenu();
                    }
                    break;
                case 2: cout << page; page = (page + 1) % (customerCart.size() + 1); counter = 1; system("cls"); once = true; break;
                case 3: return option.storeMenu(); break;
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
