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
#include "GenEdCourse.h"
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

/*
void GenEdCourse::display(std::ostream& os) const {
	Course::display(os);
	os << "|" << " ";
	os << std::left << std::setw(7) << "" << "|" << " ";
	os << std::right << std::setw(11) << langLevel_ << "|" << std::endl;
}
*/

std::ostream& GenEdCourse::display(std::ostream& os) const {
	Course::display(os);
	os << "|" << " ";
	os << std::left << std::setw(7) << "" << "|" << " ";
	os << std::right << std::setw(11) << langLevel_ << "|" << std::endl;
	return os;
}

std::fstream& GenEdCourse::load(std::fstream& fileStream) {

	char COURSECODE[MAX_COURSECODE_LEN + 1];
	char COURSETITLE[50];
	int CREDITS;
	int STUDYLOAD;
	char SYSTEM[7];
	int LANG;
	int i = 0;
	char ch[1];

	if (fileStream.is_open()){
		fileStream.getline(COURSECODE, 256, ',');
		fileStream.getline(COURSETITLE, 256, ',');
		fileStream >> CREDITS;
		fileStream.getline(ch, 1, ',');
		fileStream >> STUDYLOAD;
		fileStream.getline(ch, 1, ',');
		//fileStream.getline(SYSTEM, 256, ',');
		fileStream >> LANG;
		fileStream.ignore(1, '\n');
		setCourseCode(COURSECODE);
		setCourseTitle(COURSETITLE);
		setCredits(CREDITS);
		setStudyLoad(STUDYLOAD);
		setLangLevel(LANG);

	}else{
		std::cout << "file not found" << std::endl;
	}

	return fileStream;
}

std::istream& GenEdCourse::read(std::istream& istr) {

	return istr;
}

std::fstream& GenEdCourse::store(std::fstream& file, bool addNewLine) const {
	file << TYPE_GEN << "," << getCourseCode() << "," << getCourseTitle() << "," << getCredits() << "," << getStudyLoad() << "," << langLevel_ << (addNewLine ? "\n" : " ");
	return file;
}

namespace sict {

	std::ostream& operator<<(std::ostream& os, const GenEdCourse& obj) {
		obj.display(os);
		return os;
	}

}
