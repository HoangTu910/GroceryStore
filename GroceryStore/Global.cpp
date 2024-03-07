#include "Global.h"
#include "Employee.h"
#include "Option.h"

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
	for (int i = 0; i <= width; ++i) {
		cout << char(205);
	}
	cout << char(187);

	for (int i = 0; i <= height; ++i) {
		gotoXY(left, top + i + 1);
		cout << char(186);
	}
	gotoXY(left, top + height + 1);
	cout << char(200);
	for (int i = 0; i <= width; ++i) {
		cout << char(205);
	}
	cout << char(188);
	for (int i = 0; i <= height-1; ++i) {
		gotoXY(left+width+2, top +i+1);
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
	int terminalWidth = getTerminalWidth() / 2;
	int terminalHeight = getTerminalHeight() / 2;
	int left = terminalWidth - (width / 2);
	return left;
}


int Global::leftCenterBox(int boxWidth, int width) {
	int terminalWidth = getTerminalWidth() / 2;
	int left = terminalWidth - (boxWidth / 2);
	int windowWidth = terminalWidth - width / 2;
	return windowWidth;
}

void Global::generateMenu()
{
	system("cls");
	Option option;
	this->initMenuColor = { 7, 7, 7, 7, 7 };
	this->counter = 3;
	int width = 45;
	int height = 10;
	int top = 7;
	int left = leftCenter(width);
	drawRectangle(left, top, width, height);
	string userLabel = "1. User Account ";
	string customerLabel = "2. Manage Customer";
	string inventoryLabel = "3. Manage Inventory";
	string storeLabel = "4. Store";
	while(true) {
		gotoXY(leftCenter(userLabel.length()), top + 3);
		setColor(this->initMenuColor[0]);
		cout << userLabel;

		gotoXY(leftCenter(userLabel.length()), top + 4);
		setColor(this->initMenuColor[1]);
		cout << customerLabel;

		gotoXY(leftCenter(userLabel.length()), top + 5);
		setColor(this->initMenuColor[2]);
		cout << inventoryLabel;

		gotoXY(leftCenter(userLabel.length()), top + 6);
		setColor(this->initMenuColor[3]);
		cout << storeLabel;

		gotoXY(leftCenter(userLabel.length()), top + 8);
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
			case 3: this->option = "inventory";  cout << "inventory "; break;
			case 4: this->option = "store";  cout << "store "; break;
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


void Global::generateLogin()
{
	string password;
	string username;
	string warnLabel = "Welcome user !";
	string continueNoti = "Press 'r' to continue...";

	int width = 45;
	int height = 10;
	int top = 7;
	int left = leftCenter(width);
	do {
		string storeLabel = "GROCERY STORE MANAGMENT";
		string loginLabel = "LOGIN";

		system("cls");
		gotoXY(leftCenter(warnLabel.length()), top + 9);
		cout << warnLabel;
		drawRectangle(left, top, width, height);
	
		gotoXY(leftCenter(storeLabel.length()), 3);
		cout << storeLabel;
		gotoXY(leftCenter(loginLabel.length()), 5);
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
			gotoXY(leftCenter(continueNoti.length()), top + 3);
			cout << "Login successful ! " << endl;
			gotoXY(leftCenter(continueNoti.length()), top + 5);
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









