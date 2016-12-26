// OOP244 Milestone 2
// File GenEdCourse.cpp
// Version 1.0
// Date 28 July 2016
// Author Oleg Mitrakhovich
// Description
// function defintions for GenEdCourse class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include "GenEdcourse.h"
#include <iomanip>

using namespace sict;

GenEdCourse::GenEdCourse() {
	langLevel_ = 0;
}

GenEdCourse::GenEdCourse(const char* code, const char* tittle, int credits, int studyload, int level) : Course(code, tittle, credits, studyload) {
	langLevel_ = level;
}

int GenEdCourse::getLangLevel() {
	return langLevel_;
}

int GenEdCourse::setLangLevel(int value) {
	return langLevel_ = value;
}

void GenEdCourse::display(std::ostream& os) const {
	Course::display(os);
	os << "|" << " ";
	os << std::left << std::setw(7) << "matrix" << "|" << " ";
	os << std::right << std::setw(11) << langLevel_ << "|" << std::endl;
}

namespace sict {

	std::ostream& operator<<(std::ostream& os, const GenEdCourse& obj) {
		obj.display(os);
		return os;
	}

}
