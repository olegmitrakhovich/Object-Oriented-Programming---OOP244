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
		GenEdCourse();
		GenEdCourse(const char*, const char*, int, int, int);
		int getLangLevel();
		int setLangLevel(int);
		void display(std::ostream&) const;

	};

	std::ostream& operator<<(std::ostream&, const Course&);

}
#endif

