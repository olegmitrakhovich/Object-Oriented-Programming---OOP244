// OOP244 Milestone 3 and 4
// File GenEdCourse.h
// Version 1.0
// Date 8 August 2016
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
		std::ostream& display(std::ostream&) const;
		std::fstream& load(std::fstream&);
		std::istream& read(std::istream&);
		std::fstream& store(std::fstream&, bool addNewLine = true) const;

	};

	std::ostream& operator<<(std::ostream&, const Course&);

}
#endif

