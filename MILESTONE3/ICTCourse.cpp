// OOP244 Milestone 3 and 4
// File ICTCourse.cpp
// Version 1.0
// Date 8 August 2016
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
	file << TYPE_ICT << ",";
	Course::store(file);
	file << computerSystem__ << (addNewLine ? "\n" : " ");
	return file;
		
}

std::fstream& ICTCourse::load(std::fstream& fileStream) {
	
	
	char SYSTEM[7];
	
	if (fileStream.is_open())
	{		

			Course::load(fileStream);
			fileStream.getline(SYSTEM, 256, '\n');
			setComputerSystem(SYSTEM);

		}else{
		std::cout << "file not found";
	}
		return fileStream;
}

std::istream& ICTCourse::read(std::istream& istr) {

	Course::read(istr);
	char system[7];
	std::cin.ignore(2000, '\n');
	std::cout << "System: ";
	istr.getline(system, 7, '\n');
	
	setComputerSystem(system);

	return istr;
}

namespace sict {

	std::ostream& operator<<(std::ostream& os, const ICTCourse& obj) {
		obj.display(os);
		return os;
	}

}




