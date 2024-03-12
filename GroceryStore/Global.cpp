#include "Global.h"
#include "Employee.h"
#include "Option.h"
#include <cstdarg>

using namespace std;


string Global::getOption()
{
	return this->option;
}

void Global::setOption(string option)
{
	this->option = option;
}

void Global::setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Global::gotoXY(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void Global::hideCursor(bool isHiden) {
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = !isHiden;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void Global::drawRectangle(int left, int top, int width, int height)
{
	gotoXY(left, top);
	cout << char(201);
	for (int i = 0; i < width; ++i) {
		cout << char(205);
	}
	cout << char(187);

	for (int i = 0; i <= height; ++i) {
		gotoXY(left, top + i + 1);
		cout << char(186);
	}	
	gotoXY(left, top + height + 1);
	cout << char(200);
	for (int i = 0; i < width; ++i) {
		cout << char(205);
	}
	cout << char(188);
	for (int i = 0; i <= height-1; ++i) {
		gotoXY(left+width+1, top +i+1);
		cout << char(186);
	}
}


int Global::getTerminalWidth(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwSize.X;
}


int Global::getTerminalHeight() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwSize.Y;
}


int Global::leftCenter(int width) {
	int terminalWidth = (getTerminalWidth() / 2);
	int terminalHeight = getTerminalHeight() / 2;
	int left = terminalWidth - (width / 2);
	return left;
}


int Global::leftCenterBox(int boxWidth, int width) {
	int terminalWidth = (getTerminalWidth() / 2);
	int left = terminalWidth - (boxWidth / 2);
	int windowWidth = terminalWidth - (width / 2);
	return windowWidth;
}


void Global::generateMenu()
{
	system("cls");
	setColor(7);
	Option option;
	this->initMenuColor = { 7, 7, 7, 7, 7 };
	this->counter = 3;
	int width = 46;
	int height = 10;
	int top = 7;
	int left = leftCenter(width);
	drawRectangle(left, top, width, height);
	string userLabel = "1. User Account";
	string customerLabel = "2. Manage Customer";
	string inventoryLabel = "3. Import Products";
	string storeLabel = "4. Store";
	string storeLabels = "GROCERY STORE MANAGMENT";
	string menuLabel = "MAIN MENU";
	while(true) {
		setColor(7);
		gotoXY(leftCenter(storeLabels.length() - 1), 3);
		cout << storeLabels;
		gotoXY(leftCenter(menuLabel.length() - 1), 5);
		cout << menuLabel;

		gotoXY(leftCenter(userLabel.length() - 1), top + 3);
		setColor(this->initMenuColor[0]);
		cout << userLabel;

		gotoXY(leftCenter(userLabel.length() - 1), top + 4);
		setColor(this->initMenuColor[1]);
		cout << customerLabel;

		gotoXY(leftCenter(userLabel.length() - 1), top + 5);
		setColor(this->initMenuColor[2]);
		cout << inventoryLabel;

		gotoXY(leftCenter(userLabel.length() - 1), top + 6);
		setColor(this->initMenuColor[3]);
		cout << storeLabel;

		gotoXY(leftCenter(userLabel.length() - 1), top + 8);
		setColor(this->initMenuColor[4]);
		cout << "Exit";

		this->key = _getch();
		if (this->key == 'w' && (this->counter >= 2 && this->counter <= 5)) {
			this->counter--;
		}

		if (this->key == 's' && (this->counter >= 1 && this->counter <= 4)) {
			this->counter++;
		}
		
		if (this->key == '\r') {
			switch (this->counter) {
			case 1: this->option = "user"; option.userAccountMenu(); break;
			case 2: this->option = "customer";  cout << "customer "; break;
			case 3: this->option = "import";  drawMenu(10, 4, "IMPORT PRODUCT", "CHOOSE SUPPLIER BRAND", "1. Drinks Factory", "2. Fruit Market", "3. Tool Factory", "4. Create New Product"); break;
			case 4: this->option = "store";  option.storeMenu(); break;
			case 5: cout << "Exit "; generateLogin(); break;
			}
		}

		this->initMenuColor[0] = 7; 
		this->initMenuColor[1] = 7; 
		this->initMenuColor[2] = 7;
		this->initMenuColor[3] = 7;
		this->initMenuColor[4] = 7;

		switch (this->counter) {
		case 1: this->initMenuColor[0] = 3; break;
		case 2: this->initMenuColor[1] = 3; break;
		case 3: this->initMenuColor[2] = 3; break;
		case 4: this->initMenuColor[3] = 3; break;
		case 5: this->initMenuColor[4] = 3; break;
		}
	}
}

int Global::drawMenu(int height, int numberMenu, string storeLabels, string menuLabel, ...)
{
	system("cls");
	vector<int> initMenuColor;
	string userLabel = "1. User Account";
	vector<string> menuList;
	va_list args;
	int counter = 1;	
	char key;
	va_start(args, numberMenu);

	for (int i = 0; i < numberMenu; i++) {
		char* str = va_arg(args, char*);
		string menuItem(str);
		menuList.push_back(menuItem);
	}

	va_end(args);
	/*initMenuColor.resize(menuList.size());*/

	for (int i = 0; i < numberMenu + 1; i++) {
		initMenuColor.push_back(7);
	}

	int width = 46;
	int top = 7;
	int left = leftCenter(width);
	drawRectangle(left, top, width, height);

	while (true) {
		int geti = 0;
		setColor(7);
		gotoXY(leftCenter(storeLabels.length() - 1), 3);
		cout << storeLabels;
		gotoXY(leftCenter(menuLabel.length() - 1), 5);
		cout << menuLabel;

		for (int i = 0; i < menuList.size(); i++) {
			gotoXY(leftCenter(userLabel.length() - 1), top + 3 + i);
			setColor(initMenuColor[i]);
			cout << menuList[i];
			geti = i;
		}
		
		gotoXY(leftCenter(userLabel.length() - 1), top + 3 + geti + 2);
		setColor(initMenuColor[numberMenu]);
		cout << "Exit";

		key = _getch();

		if (key == 'w' && (counter >= 2 && counter <= numberMenu + 1)) {
			counter--;
		}

		if (key == 's' && (counter >= 1 && counter <= numberMenu)) {
			counter++;
		}

		if (key == '\r') {
			return counter;
			break;
		}

		for (int i = 0; i < initMenuColor.size(); i++) {
			initMenuColor[i] = 7;
		}
		
		for (int i = 0; i < initMenuColor.size(); i++) {
			if (counter == i + 1) {
				initMenuColor[i] = 3;
				break;
			}
		}
	}
}


void Global::generateLogin()
{
	setColor(7);
	string password;
	string username;
	string warnLabel = "Welcome user";
	string continueNoti = "Press 'r' to continue...";

	int width = 45;
	int height = 10;
	int top = 7;
	int left = leftCenter(width);
	do {
		string storeLabel = "GROCERY STORE MANAGMENT";
		string loginLabel = "LOGIN";

		system("cls");
		gotoXY(leftCenter(warnLabel.length() - 1), top + 9);
		cout << warnLabel;
		drawRectangle(left, top, width, height);
	
		gotoXY(leftCenter(storeLabel.length() - 1), 3);
		cout << storeLabel;
		gotoXY(leftCenter(loginLabel.length() - 1), 5);
		cout << loginLabel;

		gotoXY(left + 5, top + 3);
		cout << "Username: ";
		gotoXY(left + 5, top + 6);
		cout << "Password: ";

		gotoXY(left + 16, top + 3);
		cin >> username;
		gotoXY(left + 16, top + 6);
		cin >> password;

		if (username != employee.getEmployeeUserName() || password != employee.getEmployeePassword()) {
			warnLabel = "Wrong username or password";
		}
		else {
			system("cls");
			hideCursor(true);
			char keyPressed;
			drawRectangle(left, top, 45, 10);
			gotoXY(leftCenter(continueNoti.length() - 1), top + 3);
			cout << "Login successful ! " << endl;
			gotoXY(leftCenter(continueNoti.length() - 1), top + 5);
			cout << continueNoti;
			do {
				if (_kbhit()) {
					keyPressed = _getch();
					if (keyPressed == 'r' || keyPressed == 'R') {
						system("cls");
						break;
					}
				}
			} while (true);
			warnLabel = "Welcome " + employee.getEmployeeUserName();
		}

	} while (username != employee.getEmployeeUserName() || password != employee.getEmployeePassword());
	this->generateMenu();
}










