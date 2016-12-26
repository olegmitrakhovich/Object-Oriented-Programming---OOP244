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

ICTCourse::ICTCourse(const char* code , const char* tittle, int credits, int studyload, const char* ptr) : Course(code, tittle, credits, studyload){
	strncpy(computerSystem__, ptr, 7);
}


const char* ICTCourse::getComputerSystem() const {
	return computerSystem__;
}

void ICTCourse::setComputerSystem(const char* value) {
	strncpy(computerSystem__, value, 7);

}

/*
void ICTCourse::display(std::ostream& os) const {
	Course::display(os);
	os << "|" << " ";
	os << std::left << std::setw(7) << computerSystem__<< "|" << " ";
	os << std::right << std::setw(11) << "" << "|" << std::endl;
}

*/

std::ostream& ICTCourse::display(std::ostream& os) const {
	Course::display(os);
	os << "|" << " ";
	os << std::left << std::setw(7) << computerSystem__ << "|" << " ";
	os << std::right << std::setw(11) << "" << "|" << std::endl;
	return os;

}

std::fstream& ICTCourse::store(std::fstream& file, bool addNewLine) const {
	file << TYPE_ICT << "," << getCourseCode() << "," << getCourseTitle() << "," << getCredits() << "," << getStudyLoad() << "," <<  computerSystem__ << (addNewLine ? "\n" : " ");

	return file;
		
}

std::fstream& ICTCourse::load(std::fstream& fileStream) {
	
	char COURSECODE[MAX_COURSECODE_LEN + 1];
	char COURSETITLE[50];
	int CREDITS;
	int STUDYLOAD;
	int LANG;
	char SYSTEM[7];
	int i = 0;
	char ch[1];
	char ch2[1];

	if (fileStream.is_open())
	{		
		
			fileStream.getline(COURSECODE, 256, ',');
			fileStream.getline(COURSETITLE, 256, ',');
			fileStream >> CREDITS;
			fileStream.getline(ch, 1, ',');
			fileStream >> STUDYLOAD;
			fileStream.getline(ch, 1, ',');
			fileStream.getline(SYSTEM, 256, '\n');
			//fileStream >> LANG;
			//fileStream.ignore(1, '\n');
			setCourseCode(COURSECODE);
			setCourseTitle(COURSETITLE);
			setCredits(CREDITS);
			setStudyLoad(STUDYLOAD);
			setComputerSystem(SYSTEM);
		}else{
		std::cout << "file not found";
	}
		return fileStream;
}

std::istream& ICTCourse::read(std::istream& istr) {

	 

	return istr;
}

namespace sict {

	std::ostream& operator<<(std::ostream& os, const ICTCourse& obj) {
		obj.display(os);
		return os;
	}

}




