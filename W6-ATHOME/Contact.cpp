// OOP244 Workshop 5: Class with a Resource
// File Contact.h
// Version 1.0
// Date july/4/2016
// Author Oleg Mitrakhovich
// Description
// CPP file for contact class
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
		delete[] phoneNumber_;
		phoneNumber_ = nullptr;
	}

	void Contact::display() const {
		std::cout << name_ << std::endl;
		for (int i = 0; i < _noPN; i++) {
			phoneNumber_[i].display(true);
		}
		std::cout.fill('-');
		std::cout.width(40);
		std::cout << '-' << std::endl;
	}

	Contact::Contact(const Contact& src) {
		copy(src);
	}


	Contact& Contact::operator=(const Contact& C) {
		if (this != &C) {
			delete [] phoneNumber_;	
			copy(C);
		}
		else {
			return *this;
		}
		return *this;
	}

	
	void Contact::copy(const Contact& src) {
		if (src.phoneNumber_ != nullptr) {
			strncpy(name_, src.name_, 40);
			name_[40] = '\0';
			_noPN = src._noPN;
			phoneNumber_ = new PhoneNumber[src._noPN];
			for (int i = 0; i < src._noPN; i++) {
				phoneNumber_[i] = src.phoneNumber_[i];
			}
		}
		else {
			setEmpty();
		}
	}
	
}