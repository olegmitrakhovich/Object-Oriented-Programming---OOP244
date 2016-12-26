// OOP244 Workshop 2: Compound types and privacy
// File AccountNumber.h
// Version 1.0
// Date 22 May 2016
// Author       Oleg Mitrakhovich
// Description
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name                 Date            Reason
//
///////////////////////////////////////////////////////////
#ifndef ACCOUNTNUMBER_H
#define ACCOUNTNUMBER_H


#define MAX_NAME_LENGTH   40
#define MIN_BANKCODE    100
#define MAX_BANKCODE   999
#define MIN_BRANCHCODE    1
#define MAX_BRANCHCODE   220
#define MIN_ACCNO    10000
#define MAX_ACCNO    99999

namespace sict {

	class AccountNumber {
		char _name[MAX_NAME_LENGTH + 1];
		int _bankCode;
		int _branchCode;
		int _accountNumber;
		bool _validAccNumber;
		void displayName() const;
		void displayNumber() const;
	public:
		void name(const char name[]);
		void accountNumber(int bankCode, int branchCode, int accountNumber);
		void display(bool display_name = true, bool display_number = true) const;
		bool isValid() const;


	};

}

#endif

