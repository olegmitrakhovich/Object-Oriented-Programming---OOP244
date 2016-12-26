// OOP244 Milestone 2
// File Course.h
// Version 1.0
// Date 28 July 2016
// Author Oleg Mitrakhovich
// Description
// course class
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////

#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include "General.h"
//#include "ICTCourse.h"

namespace sict {


	class Course {
		char courseCode_[MAX_COURSECODE_LEN + 1];
		char* courseTitle_;
		int credits_;
		int studyLoad_;
	public:
		Course();
		Course(const char*, const char*, int, int);
		Course(const Course&);
		virtual ~Course();
		Course& operator=(const Course&);
		bool operator==(const char*);
		int operator+=(int);
		void setCourseCode(const char*);
		void setCourseTitle(char*);
		void setCredits(int);
		void setStudyLoad(int);
		const char* getCourseCode() const;
		const char* getCourseTitle() const;
		int getCredits() const;
		int getStudyLoad() const;
		bool isEmpty() const;
		virtual void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream& os, const Course&);
}

#endif
