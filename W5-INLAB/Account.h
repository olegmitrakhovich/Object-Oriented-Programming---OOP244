// OOP244 Workshop 5: operator overload
// File Account.h
// Version 1.0
// Date june 15/2016
// Author oleg mitrakhovich
// Description
// header file for account workshop operator overload.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
namespace sict {
	class Account {
		char name_[41];
		double balance_;
	public:
		Account();
		Account(double balance);
		Account(const char name[], double balance = 0.0);
		void display(bool gotoNewline = true)const;
		Account& operator+=(const Account& C);
		Account& operator=(const char* name);
		friend Account operator+(const Account& X, const Account& C);
	};

	std::ostream& operator<<(std::ostream& os, const Account& obj);


};

#endif
