// OOP244 Workshop 2: Compound types and privacy
// File	???????
// Version 1.0
// Date	22/May/2016
// Author	Oleg Mitrakhovich
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "AccountNumber.h";

using namespace sict;


void accountNumber::setName(const char name[]) {
	
	strcpy(_name, name);
};

void accountNumber::setAccountNumber(int bankCode, int branchCode, int accountNumber) {
	if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE && branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE && accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO) {
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;
		_validAccNumber = true;
	}else{
		_validAccNumber = false;
	}
};

bool accountNumber::isValid() const {
	return _validAccNumber;
}

using namespace std;

void accountNumber::display() const {
	if (isValid()) {
		cout << "Name:" << _name << ", Account number:" << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
	}
	else {
		cout << _name << " does not have a valid account number." << endl;
	}
};