// OOP244 Milestone 3 and 4
// File Course.cpp
// Version 1.0
// Date 8 August 2016
// Author Oleg Mitrakhovich
// Description
// function defintions for course class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#include <cstring>
#include <iomanip>
#include "Course.h"
#include "General.h"

using namespace sict;

Course::Course() {
	courseCode_[0] = '\0';
	courseTitle_ = nullptr;
	credits_ = -1;
	studyLoad_ = -1;
}

Course::Course(const char* code, const char* title, int credits, int studyLoad) {
	strncpy(courseCode_, code, MAX_COURSECODE_LEN + 1);
	
	courseTitle_ = new char[strlen(title) + 1];
	strcpy(courseTitle_, title);

	credits_ = credits;
	studyLoad_ = studyLoad;
}

Course::Course(const Course& src) {
	courseTitle_ = nullptr;
	*this = src;
}

Course& Course::operator=(const Course& src) {
	if (this != &src) {
		credits_ = src.credits_;
		studyLoad_ = src.studyLoad_;
		strncpy(courseCode_, src.courseCode_, MAX_COURSECODE_LEN + 1);
		delete [] courseTitle_;
		if (src.courseTitle_ != nullptr) {
			courseTitle_ = new char[strlen(src.courseTitle_) + 1];
			strcpy(courseTitle_, src.courseTitle_);
		}
		else
			courseTitle_ = nullptr;
	}
	return *this;
}

Course::~Course() {
	delete [] courseTitle_;
}

void Course::setCourseCode(const char* src) {
	strncpy(courseCode_, src, MAX_COURSECODE_LEN + 1 );
	
}

void Course::setCourseTitle(const char* src) {
	courseTitle_ = new char[strlen(src) + 1];
	strcpy(courseTitle_, src);
}

void Course::setCredits(int src) {
	credits_ = src;
}

void Course::setStudyLoad(int src) {
	studyLoad_ = src;
}

const char* Course::getCourseCode() const {
	return courseCode_;
}

const char* Course::getCourseTitle() const {
	return courseTitle_;
}

int Course::getCredits() const {
	return credits_;
}
int Course::getStudyLoad() const {
	return studyLoad_;
}

bool Course::isEmpty() const {

	if (courseCode_[0] == '\0' || strcmp(courseCode_, "") == 0 || courseTitle_ == nullptr || strcmp(courseTitle_, "") == 0 ||  credits_ == 0 || credits_ == -1 || studyLoad_ == 0 || studyLoad_ == -1) {
		return true;
	}else {
		return false;
	}
}

bool Course::operator==(const char* src) {
	if (strcmp(courseCode_, src) == 0) {
		return true;
	}
	else
		return false;

}


int Course::operator+=(int src) {
	return studyLoad_ += src;
}

using namespace std;

/*
void Course::display(std::ostream& os) const {
	
				os << left << setw(6)  << courseCode_;
                os << "|";
                os << left << setw(40) << courseTitle_;
                os << " " << "|" << " ";
                os << right << setw(8) << credits_;
                os << "|";
                os << right << setw(12) << studyLoad_;
                

	
}
*/

std::ostream& Course::display(std::ostream& os) const {
	//display(os);
	os << left << setw(6) << courseCode_;
	os << "|";
	os << left << setw(40) << courseTitle_;
	os << " " << "|" << " ";
	os << right << setw(8) << credits_;
	os << "|";
	os << right << setw(12) << studyLoad_;
	return os;
}

std::fstream& Course::load(std::fstream& fileStream) {
	
	char COURSECODE[MAX_COURSECODE_LEN + 1];
	char COURSETITLE[50];
	int CREDITS;
	int STUDYLOAD;

	fileStream.getline(COURSECODE, 256, ',');
	fileStream.getline(COURSETITLE, 256, ',');
	fileStream >> CREDITS;
	fileStream.ignore(1, ',');
	fileStream >> STUDYLOAD;
	fileStream.ignore(1, ',');

	setCourseCode(COURSECODE);
	setCourseTitle(COURSETITLE);
	setCredits(CREDITS);
	setStudyLoad(STUDYLOAD);
	
	return fileStream;
}

std::istream& Course::read(std::istream& istr) {
	
	char coursecode[MAX_COURSECODE_LEN + 1];
	char coursetitle[45];
	int credits = 0;
	int studyload = 0;

	std::cout << "Course Code: ";
	istr >> coursecode;

	std::cin.ignore(2000, '\n');
	std::cout << "Course Title: ";
	istr.getline(coursetitle, 45, '\n');

	std::cout << "Course Credit: ";
	istr >> credits;

	std::cin.ignore(2000, '\n');
	std::cout << "Study Load: ";
	istr >> studyload;

	setCourseCode(coursecode);
	setCourseTitle(coursetitle);
	setCredits(credits);
	setStudyLoad(studyload);

	return istr;
}

std::fstream& Course::store(std::fstream& file, bool addNewLine) const {
	file << courseCode_ << "," << courseTitle_ << "," << credits_ << "," << studyLoad_ << ",";
	return file;
}

namespace sict {

	std::ostream& operator<<(std::ostream& os, const Course& src) {
		src.display(os);
		return os;
	}
};





