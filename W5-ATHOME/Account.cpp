// OOP244 Workshop 5 operator overload
// File Account.cpp
// Version 1.0
// Date 15 June 2016
// Author Oleg Mitrakhovich
// Description
// Account.cpp for workshop 5
//
//
// Revision History
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Name              Date            Reason                                                          //
//Oleg Mitrakhovich  15 June 2016     added helper function definition in order to overload += again.//
///////////////////////////////////////////////////////////////////////////////////////////////////////
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

	Account operator+(const Account& A, const Account& C) {
		Account temp;
		temp = A.getbalance() + C.getbalance();
		return temp;
	}

	double Account::getbalance() const {
		return balance_;
	}

	double operator+=(double& e, const Account& A) {
		 return e += A.getbalance();
	}

	std::ostream& operator<<(std::ostream& os, const Account& obj) {
		obj.display(false);
		return os;
	}

}


