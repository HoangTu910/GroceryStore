#include "Global.h"
#include "Employee.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

using namespace std;

int Global::getOption()
{
	return this->option;
}

void Global::setOption(int option)
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


void Global::generateMenu()
{
	cout << "Running..." << endl;
	this->initMenuColor = { 7, 7, 7 };
	this->counter = 2;
	while(true) {
		gotoXY(10, 5);
		setColor(this->initMenuColor[0]);
		cout << "1. Menu ";

		gotoXY(10, 6);
		setColor(this->initMenuColor[1]);
		cout << "2. Menu ";

		gotoXY(10, 7);
		setColor(this->initMenuColor[2]);
		cout << "3. Menu ";

		this->key = _getch();
		if (this->key == 'w' && (this->counter >= 2 && this->counter <= 3)) {
			this->counter--;
		}

		if (this->key == 's' && (this->counter >= 1 && this->counter <= 2)) {
			this->counter++;
		}
		
		if (this->key == '\r') {
			switch (this->counter) {
			case 1: cout << "Menu 1 "; break;
			case 2: cout << "Menu 2 "; break;
			case 3: cout << "Menu 3 "; break;
			}
		}

		this->initMenuColor[0] = 7; 
		this->initMenuColor[1] = 7; 
		this->initMenuColor[2] = 7;

		switch (this->counter) {
		case 1: this->initMenuColor[0] = 12; break;
		case 2: this->initMenuColor[1] = 12; break;
		case 3: this->initMenuColor[2] = 12; break;
		}
	}
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
	int windowWidth = terminalWidth - width/2;
	return windowWidth;
}


void Global::generateLogin()
{
	Employee employee;
	string password;
	string username;
	string warnLabel = "Welcome user !";

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
			warnLabel = "Welcome " + employee.getEmployeeUserName();
		}

	} while (username != employee.getEmployeeUserName() || password != employee.getEmployeePassword());
}


