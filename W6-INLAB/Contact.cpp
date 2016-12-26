// OOP244 Workshop 5
// File Contact.cpp
// Version 1.0
// Date 2/july/2016
// Author Oleg Mitrakhovich
// Description
// Contact.h function definitions
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include "Contact.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace sict {

	void Contact::read() {
		std::cout << "Contact Name: ";
		std::cin.getline(name_, 41, '\n');
		std::cout << "Please enter " << _noPN << " phone numbers: " << std::endl;
		for (int i = 0; i < _noPN; i++) {
			std::cout << i + 1 << ": ";
			phoneNumber_[i].read();
		}
	}

	bool Contact::isEmpty()const {
		return phoneNumber_ == nullptr;
	}

	void Contact::setEmpty() {
		name_[0] = 0;
		_noPN = 0;
		phoneNumber_ = nullptr;
	}

	Contact::Contact() {
		setEmpty();
	}

	Contact::Contact(const char* name, int noPN) {
		
		if (name != nullptr) {					
			strncpy(name_, name, 40);
			name_[40] = '\0';
			_noPN = noPN;
			phoneNumber_ = new PhoneNumber[_noPN];
		}
		else {
			setEmpty();
		}

	}

	Contact::~Contact() {
		delete [] phoneNumber_;
		phoneNumber_ = nullptr;
	}

	void Contact::display() const {
		std::cout << name_ << std::endl;
		for(int i = 0; i < _noPN; i++){
		phoneNumber_[i].display(true);
		}
		std::cout.fill('-');
		std::cout.width(40);
		std::cout << '-' << std::endl;
	}
}
