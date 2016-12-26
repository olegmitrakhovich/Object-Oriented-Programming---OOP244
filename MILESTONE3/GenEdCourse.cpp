// OOP244 Milestone 3 and 4
// File GenEdCourse.cpp
// Version 1.0
// Date 8 August 2016
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

	
	int LANG;
	
	if (fileStream.is_open()){
		
		Course::load(fileStream);
		fileStream >> LANG;
		fileStream.ignore(1, '\n');
		
		setLangLevel(LANG);

	}else{
		std::cout << "file not found" << std::endl;
	}

	return fileStream;
}

std::istream& GenEdCourse::read(std::istream& istr) {
	Course::read(istr);
	int langLevel = 0;
	
	
	std::cin.ignore(2000, '\n');
	std::cout << "Language Requirement: ";
	std::cin >> langLevel;

	
	setLangLevel(langLevel);
	

	return istr;
}

std::fstream& GenEdCourse::store(std::fstream& file, bool addNewLine) const {
	file << TYPE_GEN << ",";
	Course::store(file);
	file << langLevel_ << (addNewLine ? "\n" : " ");
	return file;
}

namespace sict {

	std::ostream& operator<<(std::ostream& os, const GenEdCourse& obj) {
		obj.display(os);
		return os;
	}

}
