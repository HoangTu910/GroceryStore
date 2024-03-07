#include "LoginSystem.h"

void LoginSystem::configLogin()
{
	system("cls");
	Global global;
	string password = "";
	string newPassword = "0";
	string username;
	string warnLabel = "Welcome user !";
	string continueNoti = "Press 'r' to continue...";
	int width = 45;
	int height = 7;
	int top = 7;
	int left = global.leftCenter(width);
	while (password != newPassword) {
		string storeLabel = "GROCERY STORE MANAGMENT";
		string loginLabel = "CHANGE PASSWORD";

		system("cls");
		global.gotoXY(global.leftCenter(warnLabel.length()), top + 9);
		cout << warnLabel;
		global.drawRectangle(left, top, width, height);

		global.gotoXY(global.leftCenter(storeLabel.length()), 3);
		cout << storeLabel;
		global.gotoXY(global.leftCenter(loginLabel.length()), 5);
		cout << loginLabel;

		global.gotoXY(left + 5, top + 2);
		cout << "Username: ";
		global.gotoXY(left + 5, top + 4);
		cout << "Password: ";
		global.gotoXY(left + 5, top + 6);
		cout << "Confirm Password: ";

		global.gotoXY(left + 16, top + 2);
		cin >> username;
		global.gotoXY(left + 16, top + 4);
		cin >> password;
		global.gotoXY(left + 23, top + 6);
		cin >> newPassword;

		warnLabel = "Password does not match";
	}
	global.employee.setEmployeePassword(newPassword);


	system("cls");
	char keyPressed;
	global.drawRectangle(left, top, 45, 10);
	global.gotoXY(global.leftCenter(continueNoti.length()), top + 3);
	cout << "Changed password ! Login again" << endl;
	global.gotoXY(global.leftCenter(continueNoti.length()), top + 5);
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
	global.generateLogin();
}
