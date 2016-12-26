// OOP244 Workshop 2: Compound types and privacy
// File ???????
// Version 1.0
// Date 22/May/2016
// Author       Oleg Mitrakhovich
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name                 Date            Reason
//
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "AccountNumber.h"
namespace sict {


	void AccountNumber::name(const char name[]) {

		strcpy(_name, name);
	};

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {
		if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE && branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE && accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO) {
			_bankCode = bankCode;
			_branchCode = branchCode;
			_accountNumber = accountNumber;
			_validAccNumber = true;
		}
		else {
			_validAccNumber = false;
		}
	};

	bool AccountNumber::isValid() const {
		return _validAccNumber;
	}


	void AccountNumber::display(bool display_name, bool display_number) const {
		if (isValid() && display_name == true && display_number == true) {
			std::cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << std::endl;
		}
		else if(isValid() && display_name == false && display_number == true) {
			AccountNumber::displayNumber();
		}
		else if (isValid() && display_number == false && display_name == true) {
			AccountNumber::displayName();
		}
		else if (!isValid()) {
			std::cout << _name << " does not have a valid account number." << std::endl;
		}
	};

	void AccountNumber::displayNumber() const {
		std::cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << std::endl;
	};

	void AccountNumber::displayName() const {
		std::cout << "Name: " << _name << std::endl;
	};
}
