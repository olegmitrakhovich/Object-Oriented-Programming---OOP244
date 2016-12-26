// OOP244 Milestone 3 and 4
// File Course.h
// Version 1.0
// Date 8 August 2016
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
#include "Streamable.h"

namespace sict {


	class Course : public Streamable {
		char courseCode_[MAX_COURSECODE_LEN + 1];
		char* courseTitle_;
		int credits_;
		int studyLoad_;
	public:
		//friend class CourseTester;
		Course();
		Course(const char*, const char*, int, int);
		Course(const Course&);
		virtual ~Course();
		Course& operator=(const Course&);
		bool operator==(const char*);
		int operator+=(int);
		void setCourseCode(const char*);
		void setCourseTitle(const char*);
		void setCredits(int);
		void setStudyLoad(int);
		const char* getCourseCode() const;
		const char* getCourseTitle() const;
		int getCredits() const;
		int getStudyLoad() const;
		bool isEmpty() const;
		//virtual void display(std::ostream&) const;
		std::ostream& display(std::ostream&) const;
		std::fstream& load(std::fstream&);
		std::istream& read(std::istream&);
		std::fstream& store(std::fstream&, bool addNewLine = true) const;
	};

	std::ostream& operator<<(std::ostream& os, const Course&);
}

#endif
