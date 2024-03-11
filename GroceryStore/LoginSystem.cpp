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

void LoginSystem::showUserInfo()
{
	system("cls");
	Global global;
	LoginSystem login;
	Employee employee;
	Option option;
	vector<int> initMenuColor = { 3 };
	int counter = 1;
	int width = 45;
	int height = 10;
	int top = 7;
	int lefts = global.leftCenter(width);
	int leftBox = global.leftCenterBox(width, 20);
	bool exit = false;
	char key;
	string storeLabels = "USER";
	string menuLabel = "USER PROFILE";
	
	while (!exit) {
		global.setColor(7);
		global.gotoXY(global.leftCenter(storeLabels.length() - 1), 3);
		cout << storeLabels;
		global.gotoXY(global.leftCenter(menuLabel.length() - 1), 5);
		cout << menuLabel;

		global.drawRectangle(lefts, top, width, height);
		global.gotoXY(leftBox, top + 3);
		cout << "Last Name: " << employee.getEmployeeLastName() << endl;
		global.gotoXY(leftBox, top + 4);
		cout << "First Name: " << employee.getEmployeeFirstName() << endl;
		global.gotoXY(leftBox, top + 5);
		cout << "Gender: " << employee.getEmployeeGender() << endl;
		global.gotoXY(leftBox, top + 6);
		cout << "Staff ID: " << employee.getEmployeeID() << endl;
		global.gotoXY(leftBox, top + 7);
		cout << "Date of Birth: " << employee.getEmployeeBirth() << endl;

		global.gotoXY(leftBox, top + 9);
		global.setColor(initMenuColor[0]);
		cout << "Exit";
		key = _getch();
		
		if (key == '\r') {
			exit = true;
		}
	}

	option.userAccountMenu();

}
