// OOP244 Milestone 2
// File Course.cpp
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
#ifndef ICT_H
#define ICT_H
#include "Course.h"

namespace sict {

	class ICTCourse : public Course {
		char computerSystem__[6 + 1];
	public:
		//friend class ICTCourseTester;
		ICTCourse(const char*, const char*, int, int, const char*);
		ICTCourse();
		const char* getComputerSystem() const;
		void setComputerSystem(const char* value);
		//void display(std::ostream&) const;
		std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& display(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	std::ostream& operator<<(std::ostream&, const Course&);
}
#endif
