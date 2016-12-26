// OOP244 Workshop 5 operator overload
// File Account.h
// Version 1.0
// Date 15 June 2016
// Author Oleg Mitrakhovich
// Description
// Account.h for workshop 5
//
//
// Revision History
////////////////////////////////////////////////////////////////////////////////////////////////
// Name              Date            Reason
//Oleg Mitrakhovich  15 June 2016     added helper function in order to overload += again.
///////////////////////////////////////////////////////////////////////////////////////////////////
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
		double getbalance() const;
		Account& operator+=(const Account& C);
		Account& operator=(const char* name);
		friend Account operator+(const Account& A, const Account& C);
		
	};

	std::ostream& operator<<(std::ostream& os, const Account& obj);
	double operator+=(double& e, const Account& A);
};

#endif
