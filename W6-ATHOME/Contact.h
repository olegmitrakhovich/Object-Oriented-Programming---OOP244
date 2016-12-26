// OOP244 Workshop 5: Class with a Resource
// File Contact.h
// Version 1.0
// Date july/4/2016
// Author Oleg Mitrakhovich
// Description
// Header file for contact class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include "PhoneNumber.h"

namespace sict {
	class Contact {
		char name_[41];
		PhoneNumber* phoneNumber_;
		int _noPN;
		void setEmpty();

	public:
		Contact();
		~Contact();
		Contact(const char*, int);
		Contact(const Contact&);
		void read();
		bool isEmpty()const;
		void display()const;
		void copy(const Contact&);
		Contact& operator=(const Contact&);

	};

}
