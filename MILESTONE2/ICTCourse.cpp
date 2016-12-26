// OOP244 Milestone 2
// File ICTCourse.cpp
// Version 1.0
// Date 28 July 2016
// Author Oleg Mitrakhovich
// Description
// function defintions for ICTCourse class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include "ICTCourse.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace sict;

ICTCourse::ICTCourse() {
	strncpy(computerSystem__, "matrix", 7);
}

ICTCourse::ICTCourse(const char* code , const char* tittle, int credits, int studyload, char* ptr) : Course(code, tittle, credits, studyload){
	strncpy(computerSystem__, ptr, 7);
}


const char* ICTCourse::getComputersystem() const {
	return computerSystem__;
}

void ICTCourse::setComputerSystem(const char* value) {
	strncpy(computerSystem__, value, 7);

}


void ICTCourse::display(std::ostream& os) const {
	Course::display(os);
	os << "|" << " ";
	os << std::left << std::setw(7) << computerSystem__<< "|" << " ";
	os << std::right << std::setw(11) << "0" << "|" << std::endl;
}



namespace sict {

	std::ostream& operator<<(std::ostream& os, const ICTCourse& obj) {
		obj.display(os);
		return os;
	}

}




