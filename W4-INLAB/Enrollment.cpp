// OOP244 Workshop 4: Constructors
// File Enrollment.cpp
// Version 1.0
// Date 8 June 2016
// Author Oleg Mitrakhovich
// Description
// CPP file for workshop 4 defines all the functions in Enrollment.h
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include "Enrollment.h"
#include <iostream>
#include <cstring>

using namespace sict;
using namespace std;

bool Enrollment::isValid()const {
	return name_ && name_[0];
}
//done
void Enrollment::setEmpty() {
	name_[0] = 0;
	code_[0] = 0;
	year_ = 0;
	semester_ = 0;
	slot_ = 0;
	enrolled_ = false;
}
// done
bool Enrollment::isEnrolled() const {
	return enrolled_;
}

// done
void Enrollment::display(bool nameOnly)const {
	if (isValid()) {
		cout << name_;
		if (!nameOnly) {
			cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
			cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
		}
	}
	else {
		cout << "Invalid enrollment!" << endl;
	}
}

void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled) {
	if (name == nullptr || strlen(name) == 0 || code == nullptr || strlen(code) == 0 || 2015 > year || 2015 < year || semester <= 0 || semester > 3 || time <= 0 || time >= 6) {
		setEmpty();
	}
	else {
		strcpy(name_, name);
		strcpy(code_, code);
		year_ = year;
		semester_ = semester;
		slot_ = time;
		enrolled_ = enrolled;
	}
}

bool Enrollment::hasConflict(const Enrollment &other) const {
	
	if (year_ == 0){
	 	return false;
	}

	if (other.year_ == year_ && other.semester_ == semester_ && other.slot_ == slot_) {
		return true;
	}
	else
		return false;
}

Enrollment::Enrollment() {
	name_[0] = '\0';
	code_[0] = '\0';
	year_ = 0;
	semester_ = 0;
	slot_ = 0;
	enrolled_ = false;
}

Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time) {
	set(name, code, year, semester, time, false);
}
