#include "Option.h"


void Option::UserOption::userAccountMenu()
{
	system("cls");
	Global global;
	LoginSystem login;
	this->initMenuColor = { 7, 7, 7 };
	this->counter = 2;
	int width = 45;
	int height = 7;
	int top = 7;
	int left = global.leftCenter(width);
	bool isChosen = false;
	global.drawRectangle(left, top, width, height);
	string userLabel = "1. Change Password ";
	string customerLabel = "2. Logout";
	while (!isChosen) {
		global.gotoXY(global.leftCenter(userLabel.length()), top + 3);
		global.setColor(this->initMenuColor[0]);
		cout << userLabel;

		global.gotoXY(global.leftCenter(userLabel.length()), top + 4);
		global.setColor(this->initMenuColor[1]);
		cout << customerLabel;

		global.gotoXY(global.leftCenter(userLabel.length()), top + 6);
		global.setColor(this->initMenuColor[2]);
		cout << "Exit";

		this->key = _getch();
		if (this->key == 'w' && (this->counter >= 2 && this->counter <= 3)) {
			this->counter--;
		}

		if (this->key == 's' && (this->counter >= 1 && this->counter <= 2)) {
			this->counter++;
		}

		if (this->key == '\r') {
			switch (this->counter) {
			case 1: this->option = "changepass"; login.configLogin();  isChosen = true; break;
			case 2: this->option = "logout"; global.generateLogin(); isChosen = true; break;
			case 3: cout << "Exit "; global.generateMenu(); isChosen = true; break;
			}
		}

		this->initMenuColor[0] = 7;
		this->initMenuColor[1] = 7;
		this->initMenuColor[2] = 7;

		switch (this->counter) {
		case 1: this->initMenuColor[0] = 3; break;
		case 2: this->initMenuColor[1] = 3; break;
		case 3: this->initMenuColor[2] = 3; break;
		}
	}
}
