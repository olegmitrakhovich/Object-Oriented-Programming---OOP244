// OOP244 Workshop 5
// File Contact.h
// Version 1.0
// Date 2/july/2016
// Author Oleg Mitrakhovich
// Description
// function prototypes.
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
		void read();
		bool isEmpty()const;
		void display()const;
	};

}
