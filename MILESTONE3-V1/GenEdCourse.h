// OOP244 Milestone 2
// File GenEdCourse.h
// Version 1.0
// Date 28 July 2016
// Author Oleg Mitrakhovich
// Description
// GenEdCourse class.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
#ifndef GENED_H
#define GENED_H

#include "Course.h"

namespace sict {

	class GenEdCourse : public Course {
		int langLevel_;
	public:
		//friend class GenEdCourseTester;
		GenEdCourse();
		GenEdCourse(const char*, const char*, int, int, int);
		int getLangLevel();
		int setLangLevel(int);
		//void display(std::ostream&) const;
		std::ostream& display(std::ostream& os) const;
		std::fstream& load(std::fstream& file);
		std::istream& read(std::istream& istr);
		std::fstream& store(std::fstream& file, bool addNewLine = true) const;

	};

	std::ostream& operator<<(std::ostream&, const Course&);

}
#endif

