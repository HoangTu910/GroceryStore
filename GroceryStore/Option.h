#pragma once
#include "Global.h"
#include "LoginSystem.h"
#include "Store.h"

class initMenu{
public:
	vector<int> initMenuColor = {};
	int counter = 0;
	char key;
	string option;
};

class Option
{
private:
	int globalOption;
public:
	class UserOption {
	private:
		vector<int> initMenuColor = {};
		int counter = 0;
		char key;
		string option;
	public:
		void userAccountMenu();
	};
	
	
	class StoreOption : public initMenu{
	public:
		void storeMenu();
	};

	void userAccountMenu() {
		UserOption user;
		user.userAccountMenu();
	}

	void storeMenu() {
		StoreOption store;
		store.storeMenu();
	}
};

