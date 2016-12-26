// OOP244 Workshop 5: operator overload
// File Account.cpp
// Version 1.0
// Date june 15/2016
// Author oleg mitrakhovich
// Description
// cpp file for account workshop operator overload.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#include <iomanip>
#include <cstring>
#include "Account.h"
using namespace std;
namespace sict {
	Account::Account() {
		name_[0] = 0;
		balance_ = 0;
	}
	Account::Account(double balance) {
		name_[0] = 0;
		balance_ = balance;
	}
	Account::Account(const char name[], double balance) {
		strncpy(name_, name, 40);
		name_[40] = 0;
		balance_ = balance;
	}


	void Account::display(bool gotoNewline)const {
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}


	Account& Account::operator+=(const Account& C) {
		balance_ += C.balance_;
		return *this;
	}

	Account& Account::operator=(const char* name) {
		strcpy(name_, name);
		return *this;
	}

	Account operator+(const Account& X, const Account& C) {
		Account temp;
		temp.balance_ = X.balance_ + C.balance_;
		return temp;
	}

	std::ostream& operator<<(std::ostream& os, const Account& obj) {
		obj.display(false);
		return os;
	}

}
