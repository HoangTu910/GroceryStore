#pragma once
#include "Global.h"
#include "LoginSystem.h"
#include "Store.h"
#include "Customer.h"
#include "Inventory.h"


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
	//User Option Class
	class UserOption {
	private:
		vector<int> initMenuColor = {};
		int counter = 0;
		char key;
		string option;
	public:
		void userAccountMenu();
	};
	
	
	//Store Option Class
	class StoreOption : public initMenu{
	public:
		void storeMenu();
	};


	//Customer Option Class
	class CustomerOption : public initMenu {
	public:
		void customerMenu(Customer& customerReference);
	};


	//Import Option Class
	class ImportOption : public initMenu {
	public:
		void importMenu();
	};

	void userAccountMenu() {
		UserOption user;
		user.userAccountMenu();
	}

	void storeMenu() {
		StoreOption store;
		store.storeMenu();
	}

	void customerMenu(Customer& customerReference) {
		CustomerOption customer;
		customer.customerMenu(customerReference);
	}

	void importMenu() {
		ImportOption import;
		import.importMenu();
	}
	


};

