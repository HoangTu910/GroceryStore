#pragma once
#include "Global.h"
#include "LoginSystem.h"

class Option
{
private:
	int globalOption;
public:
	class UserOption {
	private:
		vector<int> initMenuColor;
		int counter;
		char key;
		string option;
	public:
		void userAccountMenu();
	};
	
	void userAccountMenu() {
		UserOption user;
		user.userAccountMenu();
	}
};

